/*
 * CustomBodyHandler.hh
 *
 *  Created on: 20/10/2012
 *      Author: hector
 */

#ifndef CUSTOMBODYHANDLER_HH_
#define CUSTOMBODYHANDLER_HH_

#include "Body.hh"
#include "BodyHandler.hh"
#include "../common/Point.hh"
#include "../common/PointFactory.hh"
#include "../tracking/Step.hh"
#include "../utils/BodyContainerNode.hh"
#include "BodyContainer.hh"
#include <iomanip>
#include <stddef.h>

#include <stdio.h>
#include <unistd.h>

using namespace std;

class CustomBodyHandler: public BodyHandler {
private:
    BodyContainer * body_container;
    BodyContainerNode * current_body;
    BodyContainerNode * next_body;
    Point * lastPosition;
    bool joiningToFather;
public:
    CustomBodyHandler();
    CustomBodyHandler(BodyContainer * body_container);
    virtual ~CustomBodyHandler(){
        if(lastPosition != NULL)
            delete lastPosition;
    };
    Body * getCurrentBody();
    void setCurrentBody(Point * vector);
    void setUniverseAsCurrentBody();
    void setCurrentBodyAsNextBody();
    Point * getLastPosition();
    Body * getNextBody();
    bool getJoiningToFather(){
        return this->joiningToFather;
    };

    virtual Body * getBody(Point * position) {
        return this->body_container->getBody(position)->getBody();
    }
    ;

    bool setInitialBody(Point * position) {
        this->setUniverseAsCurrentBody();
        BodyContainerNode * body = this->body_container->getBody(position);
        if (body != NULL) {
            current_body = body;
            return true;
        } else {
            this->setUniverseAsCurrentBody();
            return false;
        }
    }

    virtual Point * getNextPosition(Point * position, Point * direction, Step * step) {
        
        step->setPosition(position);
        step->setDirection(direction);

        Point * move = direction->operator *(step->getStep_size());
        Point * next = position->operator +(move);
        delete move;

        if (this->getCurrentBody()->getGeometry()->insideGeometry(next)) {

            for (unsigned int i = 0; i < this->current_body->getChildrenBodys().size(); i++) {

                if (current_body->getChildrenBodys()[i]->getBody()->getGeometry()->insideGeometry(next)) {
                    Point * r = current_body->getChildrenBodys()[i]->getBody()->getGeometry()->getIntersectionPoint(position, next);
                    
                    step->setHit(true);
                    step->setHitPoint(r);

                    double ut1 = current_body->getBody()->getMaterial()->getMaterialProperties()->getProperty("absorption_coefficient") + 
                                 current_body->getBody()->getMaterial()->getMaterialProperties()->getProperty("scattering_coefficient");

                    double ut2 = current_body->getChildrenBodys()[i]->getBody()->getMaterial()->getMaterialProperties()->getProperty("absorption_coefficient") + 
                                 current_body->getChildrenBodys()[i]->getBody()->getMaterial()->getMaterialProperties()->getProperty("scattering_coefficient");

                    if (ut2 > 0)
                        step->setInteractionRatio(ut1/ut2);
                    else
                        step->setInteractionRatio(1);

                    this->joiningToFather = false;
                    next_body = current_body->getChildrenBodys()[i];
                    if(this->lastPosition != NULL)
                        delete this->lastPosition;
                    this->lastPosition = PointFactory::getPoint(position);
                    if(r == NULL){
                        cerr << "CustomBodyHandler: Error no se encontro punto de interseccion entre las rectas entrando a un children body: current body - " << current_body->getBody()->getID() << endl;
                        cerr << "Step Size: " << step->getStep_size() << endl;
                        exit(-1);
                    }

                    delete next;
                    return r;
                }
            }
            
            step->setHit(false);
            return next;
        } else {

            Point * r = current_body->getBody()->getGeometry()->getIntersectionPoint(position, next);
            
            step->setHit(true);
            step->setHitPoint(r);

            double ut1 = current_body->getBody()->getMaterial()->getMaterialProperties()->getProperty("absorption_coefficient") + 
                         current_body->getBody()->getMaterial()->getMaterialProperties()->getProperty("scattering_coefficient");

            double ut2 = current_body->getMotherBody()->getBody()->getMaterial()->getMaterialProperties()->getProperty("absorption_coefficient") + 
                         current_body->getMotherBody()->getBody()->getMaterial()->getMaterialProperties()->getProperty("scattering_coefficient");

            if (ut2 > 0) 
                step->setInteractionRatio(ut1/ut2);
            else
                step->setInteractionRatio(1);

            if(this->lastPosition != NULL)
                delete this->lastPosition;
            this->lastPosition = PointFactory::getPoint(position);
            this->joiningToFather = true;
            if (r == NULL){
                cerr << "CustomBodyHandler: Error no se encontro punto de interseccion entre las rectas saliendo a un padre: current body - " << current_body->getBody()->getID() << endl;
                cerr << "Step Size: " << step->getStep_size() << endl;
                exit(-1);
            }

            next_body = current_body->getMotherBody();
            delete next;
            return r;
        }
    };

};

#endif /* CUSTOMBODYHANDLER_HH_ */
