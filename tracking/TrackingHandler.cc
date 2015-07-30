#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#include  <uFile.h>
#endif

#define CHANCE 0.1

#include "TrackingHandler.hh"
#include "EventDispatcher.hh"
#include "../event/Event.hh"
#include "../particle/ProcessHandler.hh"
#include "../particle/PhotonProcessHandler.hh"
#include "../body/BodyHandler.hh"
#include "../body/CustomBodyHandler.hh"
#include "../common/Point.hh"
#include "../common/PointFactory.hh"
#include "../particle/PhotonParticleChange.hh"
#include "../io/Writer.cc"
#include "../utils/GeometryAlgorithms.hh"
#include "../utils/Random.hh"
#include <float.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>

TrackingHandler::TrackingHandler(ProcessHandler* processHandler,
    BodyHandler* bodyHandler, int ID,  EventBuffer * eb, Writer * cw, Random * random, uCluster &cl): cl(cl) {
    this->ID = ID;
    this->event = event;
    this->processHandler = processHandler;
    this->bodyHandler = bodyHandler;
    this->eventBuffer = eb;
    this->coroutineWriter = cw;
    this->random = random;
    this->particles_simulated = 0;
}

TrackingHandler::~TrackingHandler() {
    delete this->bodyHandler;
    delete this->coroutineWriter;
}

void TrackingHandler::applyParticlesChanges(Particle* particle, ParticleChange* particleChanges) {
    particle->setDirection(PointFactory::getPoint(dynamic_cast<PhotonParticleChange *>(particleChanges)->getScatter()));
    particle->setEnergy(particle->getEnergy() - dynamic_cast<PhotonParticleChange *>(particleChanges)->getAbsorption());
}

bool TrackingHandler::isDie(Particle* particle) {

    if (particle->getEnergy() >= 1E-4)
        return false;
    else{
        //Ruleta
        if(particle->getEnergy() == 0.0){
            return true;
        }
        else if(random->RandomNumBetweenZeroOne() < CHANCE) // survived the roulette.
        {
            particle->setEnergy(particle->getEnergy() / CHANCE);
            return false;
        }
        else{
            particle->setEnergy(0);
            return true;
        }
    }
}

void TrackingHandler::step(Particle* particle, ParticleChange* particleChanges) {

    CustomBodyHandler * cbh = dynamic_cast<CustomBodyHandler *>(this->bodyHandler);

    Point * nextPost = cbh->getNextPosition(particle->getPosition(), particle->getDirection(), particleChanges->getStep());
    particle->setPosition(nextPost);

    // Se procesa lo que queda de step
    double remaining_step = particleChanges->getStep()->getStep_size() - particleChanges->getStep()->getForeshortenedStep();
    if (remaining_step < 0 || fabs(remaining_step) < DBL_EPSILON)
        remaining_step = 0;

    // Se asigna el step faltante para la siguiente iteracion
    particleChanges->getStep()->setStep_size(remaining_step);
}

void TrackingHandler::preStep(Particle * particle) {
}

void TrackingHandler::postStep(Particle * particle, ParticleChange * pc, bool &hitBoundary) {

}

void TrackingHandler::onHitBoundary(Particle* particle, BodyHandler* bodyHandler, ParticleChange * particleChanges) {
    
    CustomBodyHandler * cbh = dynamic_cast<CustomBodyHandler *>(this->bodyHandler);

    // Reflexion
    if(dynamic_cast<PhotonProcessHandler *>(this->processHandler)->isReflected(particle, cbh->getCurrentBody(), cbh->getNextBody())) {

        Point * reflexion;
        if(cbh->getJoiningToFather())
            reflexion = cbh->getCurrentBody()->getGeometry()->getReflection(cbh->getLastPosition(), particle->getPosition(), particle->getDirection());
        else
            reflexion = cbh->getNextBody()->getGeometry()->getReflection(cbh->getLastPosition(), particle->getPosition(), particle->getDirection());

        particle->setDirection(reflexion);
    }
    // Transmision
    else{

        // Cuando una particula es transmitida debe ser en proporción al radio de interaccion
        double remaining_step = particleChanges->getStep()->getStep_size();
        remaining_step = remaining_step * particleChanges->getStep()->getInteractionRatio();
        particleChanges->getStep()->setStep_size(remaining_step);
        
        // Reemplazar por refracción!!
        // particle->setDirection(PointFactory::getPoint(dynamic_cast<PhotonParticleChange *>(particleChanges)->getScatter()));

        dynamic_cast<CustomBodyHandler *>(this->bodyHandler)->setCurrentBodyAsNextBody();
    }

    particleChanges->getStep()->setHit(false);
    particleChanges->getStep()->setHitPoint(NULL);
}

void TrackingHandler::trackParticle() {

    Particle * particle = this->event->getParticle();
    CustomBodyHandler * cbh = dynamic_cast<CustomBodyHandler *>(this->bodyHandler);
    PhotonProcessHandler * pph = dynamic_cast<PhotonProcessHandler *>(this->processHandler);
    cbh->setInitialBody(particle->getPosition());
    ParticleChange * particleChanges;

    /*Con output handler*/
    if(cbh->getCurrentBody()->isSensitive())
        this->tracks.push_back(
            new Track(
                new Particle(particle), 
                new PhotonParticleChange(), 
                this->event->getID(),
                this->event->getTime(), 
                this->event->getSourceID()
            )
        );

    int i = 0;

    while (!(this->isDie(particle)) && 
            !(
                cbh->getCurrentBody()->getMaterial()->getMaterialProperties()->getProperty("absorption_coefficient") == 0 && 
                cbh->getCurrentBody()->getMaterial()->getMaterialProperties()->getProperty("scattering_coefficient") == 0 && 
                cbh->getCurrentBody()->getMaterial()->getMaterialProperties()->getProperty("anisotropy") == 0
            )
        ) {

        i++;

        // Si queda algo de step no se recalculan los cambios a la particula
        if (particleChanges == NULL || fabs(particleChanges->getStep()->getStep_size()) < DBL_EPSILON) {
            particleChanges = pph->getParticleChange(particle, cbh->getCurrentBody());
        }

        this->step(particle, particleChanges);

        if (particleChanges->getStep()->getHit()) {
            this->onHitBoundary(particle, cbh, particleChanges);
        } 
        else {
            this->applyParticlesChanges(particle, particleChanges);

            /*
             * Se agrega la particula a los tracks solo cuando los cambios han sido aplicados
             */
            if (cbh->getCurrentBody()->isSensitive())
                this->tracks.push_back(
                    new Track(new Particle(particle),
                        new PhotonParticleChange( particleChanges ), 
                        this->event->getID(), 
                        this->event->getTime(), 
                        this->event->getSourceID()
                    )
                );
        }

        if (fabs(particleChanges->getStep()->getStep_size()) < DBL_EPSILON) {
            delete particleChanges;
            particleChanges = NULL;
        }
    }

     /*Con writer*/
    this->coroutineWriter->addTracks(tracks);

    tracks.clear();
    this->particles_simulated++;
}