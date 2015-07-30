/*
 * ScatteringProcess.hh
 *
 *  Created on: 10/11/2012
 *      Author: hector
 */

#ifndef SCATTERINGPROCESS_HH_
#define SCATTERINGPROCESS_HH_

#include "Process.hh"
#include "ParticleChange.hh"
#include "PhotonParticleChange.hh"
#include "../utils/Random.hh"
#include "../common/PointFactory.hh"
#include "../common/Point2D.hh"
#include "../common/Point3D.hh"
#include <math.h>

#define PI 3.1415926

class ScatteringProcess {
private:
    Random * random;
public:
    ScatteringProcess(Random * random);
    virtual ~ScatteringProcess() {

    }
    ;
    virtual Point * getParticleChange(Particle * particle,
            Body * body) {

        /*
         * Esto debe ser cambiado, no se deberia preguntar a la PointFactory
         * por la dimension de la simulacion. Solo se ha implementado por razones
         * de tiempo
         */
        if (PointFactory::dimensions == 2) {
            double ux = dynamic_cast<Point2D *>(particle->getDirection())->getX();
            double uy = dynamic_cast<Point2D *>(particle->getDirection())->getY();
            double cost, sint;
            double g = body->getMaterial()->getMaterialProperties()->getProperty("anisotropy");
            Point2D * scattering = new Point2D();

            /***********************************************************
             *  Choose (sample) a new theta angle for photon propagation
             *  according to the anisotropy.
             *
             *  If anisotropy g is 0, then
             *      cos(theta) = 2*rand-1.
             *  otherwise
             *      sample according to the Henyey-Greenstein function.
             *
             *  Returns the cosine of the polar deflection angle theta.
             ****/

            if (g == 0.0)
                cost = 2 * this->random->RandomNumBetweenZeroOne() - 1;
            else {
                double temp = (1 - g * g) / (1 - g + 2 * g * this->random->RandomNumBetweenZeroOne());
                cost = (1 + g * g - temp * temp) / (2 * g);

                if (cost < -1)
                    cost = -1;
                else if (cost > 1)
                    cost = 1;
            }

            sint = sqrt(1.0 - cost * cost);

            double theta = acos(cost);

            /*Se determina de manera aleatoria el signo de teta ya que la funcion acos siempre retorna valores entre 0 y PI obviando los valores entre
              PI y 2PI los cuales determinan valores negativos para el sin*/

            if(this->random->RandomNumBetweenZeroOne() >= 0.5)
                theta=-theta;

            sint = sin(theta);
            if(cost == 1){
                sint = 0;
            }

            scattering->setX(-sint*uy + ux*cost);
            scattering->setY(sint*ux + uy*cost);

            return scattering;
        }
        else if (PointFactory::dimensions == 3) {

            double ux = dynamic_cast<Point3D *>(particle->getDirection())->getX();
            double uy = dynamic_cast<Point3D *>(particle->getDirection())->getY();
            double uz = dynamic_cast<Point3D *>(particle->getDirection())->getZ();

            double sign;
            double new_ux;
            double new_uy;
            double new_uz;

            double cost;
            double g = body->getMaterial()->getMaterialProperties()->getProperty("anisotropy");
            Point3D * scattering = new Point3D();

            /***********************************************************
             *  Choose (sample) a new theta angle for photon propagation
             *  according to the anisotropy.
             *
             *  If anisotropy g is 0, then
             *      cos(theta) = 2*rand-1.
             *  otherwise
             *      sample according to the Henyey-Greenstein function.
             *
             *  Returns the cosine of the polar deflection angle theta.
             ****/

            if (g == 0.0)
                cost = 2 * this->random->RandomNumBetweenZeroOne() - 1;
            else {
                double temp = (1 - g * g) / (1 - g + 2 * g * this->random->RandomNumBetweenZeroOne());
                cost = (1 + g * g - temp * temp) / (2 * g);

                if (cost < -1)
                    cost = -1;
                else if (cost > 1)
                    cost = 1;
            }

            double theta = acos(cost);

            /* Se determina de manera aleatoria el signo de teta ya que la 
             * funcion acos siempre retorna valores entre 0 y PI obviando los 
             * valores entre PI y 2PI los cuales determinan valores negativos 
             * para el sin
             */
            if(this->random->RandomNumBetweenZeroOne() >= 0.5)
                theta=-theta;

            /*
             * se muestrea el angulo azimutal
             */
            double psi = 2 * 3.141592653589793238462 * this->random->RandomNumBetweenZeroOne();

            /*
             * Se analiza uz para evitar division por cero
             */
            if (fabs(uz) > 0.99999) {
                if (uz < 0) sign = -1;
                else sign = 1;

                new_ux = sin(theta) * cos(psi);
                new_uy = sin(theta) * sin(psi);
                new_uz = sign * cos(theta);
            } 

            else {
                new_ux = (sin(theta) / sqrt(1 - uz*uz)) * (ux*uz*cos(psi) - uy*sin(psi)) + ux*cos(theta);
                new_uy = (sin(theta) / sqrt(1 - uz*uz)) * (uy*uz*cos(psi) + ux*sin(psi)) + uy*cos(theta);
                new_uz = -sin(theta) * cos(psi) * sqrt(1 - uz*uz) + uz*cos(theta);
            }

            scattering->setX(new_ux);
            scattering->setY(new_uy);
            scattering->setZ(new_uz);

            return scattering;
        }

        return NULL;
    };
};

#endif /* SCATTERINGPROCESS_HH_ */
