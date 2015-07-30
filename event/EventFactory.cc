/*
 * EventFactory.cc
 *
 *  Created on: 06/11/2012
 *      Author: hector
 */

#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#endif

#include <cstddef>
#include "EventFactory.hh"
#include "SourceHandler.hh"
#include "Source.hh"
#include "../common/Point.hh"
#include "../common/PointFactory.hh"
#include <math.h>

#define PARTICLEENERGY 1

EventFactory::EventFactory() {
    eventID = 1;
    sourceHandler = NULL;
    random = NULL;
}

EventFactory::EventFactory(SourceHandler* sourceHandler, Random * random) {
    eventID = 1;
    this->random = random;
    this->sourceHandler = sourceHandler;
}

SourceHandler* EventFactory::getSourceHandler() {
    return this->sourceHandler;
}

void EventFactory::setSourceHandler(SourceHandler* sourceHandler) {
    this->sourceHandler = sourceHandler;
}

EventFactory::~EventFactory() {
    delete this->sourceHandler;
}

Event* EventFactory::getEvent(string name,long &time) {
    if (name.compare("photon") == 0) {
        Source * source = this->sourceHandler->getNextSource();
        if (source != NULL) {
            Point * position = source->getGemeotry()->getRandomPoint();
            Point * position2 = PointFactory::getPoint(position);
            
            // double rand1 = this->random->RandomNumBetweenZeroOne() * 2 * 3.141592;
            // int x = sin(rand1);
            // int y = cos(rand1);

            //Point * direction = source->getGemeotry()->getRandomDirection();
            Point * direction = source->getRandomDirection();
            
            Event * e = new Event(eventID, position,new Particle(position2, direction, PARTICLEENERGY), time, source->getID());
            time++;
            this->eventID = this->eventID + 1;
            return e;
        }
        else
            return NULL;
    } else {
        cerr
                << "El nombre de evento ingresado no se encuentra definido en el EventFactory"
                << endl;
        exit(-1);
    }
    return NULL;
}


vector<Event *> EventFactory::getEvents(string name,unsigned int number,long &time) {
    //cout << "Entrando a EventFactory::getEvents" << endl;
    vector<Event *> events;
    Event * e;
    if (name.compare("photon") == 0) {
        for(unsigned int i = 0; i < number; i++){
            Source * source = this->sourceHandler->getNextSource();
            if (source != NULL) {
                Point * position = source->getGemeotry()->getRandomPoint();
                Point * position2 = PointFactory::getPoint(position);
                //cout << position->toString() << endl;

                // double rand1 = this->random->RandomNumBetweenZeroOne();
                // double x = rand1 - 1;
                // double y = rand1;
                // double rand2 = this->random->RandomNumBetweenZeroOne();
                // double rand3 = this->random->RandomNumBetweenZeroOne();
                // if (rand2 <= .5)
                //     x = -x;
                // if (rand3 <= .5)
                //     y = -y;

                /*Método alternativo*/
                // x = 2 * 3.141592653589793238462 * this->random->RandomNumBetweenZeroOne();
                // y = sin(x);
                // x = cos(x);
                /*Hasta aca*/

                //Point * direction = source->getGemeotry()->getRandomDirection();
                Point * direction = source->getRandomDirection();

                e = new Event(eventID, position,new Particle(position2, direction, PARTICLEENERGY), time , source->getID());
                time++;
                this->eventID = this->eventID + 1;
                events.push_back(e);
            }
            else
                break;
        }
        return events;
    } else {
        cerr
                << "El nombre de evento ingresado no se encuentra definido en el EventFactory"
                << endl;
        exit(-1);
    }
}

