/*
 * TrackingHandler.hh
 *
 *  Created on: 11/11/2012
 *      Author: hector
 */

#ifndef TRACKINGHANDLER_HH_
#define TRACKINGHANDLER_HH_

#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#include  <uFile.h>
#endif

#include "Buffer.cc"
#include "../io/Writer.cc"
#include "../event/Event.hh"
#include "../particle/ProcessHandler.hh"
#include "../particle/ParticleChange.hh"
#include "../body/BodyHandler.hh"
#include "Track.hh"
#include <vector>
#include "EventDispatcher.hh"
#include "EventBuffer.cc"
#include "../utils/Random.hh"

_Task TrackingHandler{
    uCluster &cl;
private:
    int ID;
    Event * event;
    ProcessHandler * processHandler;
    BodyHandler * bodyHandler;
    vector<Track *> tracks;
    Writer * coroutineWriter;
    EventDispatcher * eventDispatcher;
    EventBuffer * eventBuffer;
    Random * random;
    long particles_simulated;
    void main(){
        //_Accept(~TrackingHandler);
        vector<Event*> events;
        bool endsimulation = false;
        for( ; ; ){
            events = eventBuffer->remove(endsimulation);
            if(events.size() == 0 && endsimulation)
                break;
            if(events.size() != 0){
                // for (std::vector<Event *>::iterator it = events.begin() ; it != events.end(); ++it){
                //  event = *it;
                //  this->trackParticle();
                //  delete event;
                // }
                for(unsigned int i = 0;i < events.size();i++){
                    event = events[i];
                    // cout << "Trackeando particula" << endl;
                    this->trackParticle();
                    /*for(int t = 0;t < 10000000; t++){

                    }*/
                    delete event;
                }
                this->coroutineWriter->saveFile();
            }
        }
        this->coroutineWriter->stop();
    }
protected:
    virtual void applyParticlesChanges(Particle * particle,ParticleChange * photonParticleChanges);
    virtual bool isDie(Particle * particle);
    virtual void step(Particle * particle, ParticleChange * photonParticleChanges);
    virtual void preStep(Particle * particle);
    virtual void postStep(Particle * particle, ParticleChange * pc, bool &hitBoundary);
    void onHitBoundary(Particle * particle, BodyHandler * bodyHandler,ParticleChange * particleChanges);
public:
    TrackingHandler(ProcessHandler * processHandler, BodyHandler * bodyHandler, int ID,  EventBuffer * rb, Writer * cw, Random * random, uCluster &cl);
    virtual ~TrackingHandler();
    void trackParticle();
};


#endif /* TRACKINGHANDLER_HH_ */
