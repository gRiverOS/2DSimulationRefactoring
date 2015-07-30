#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#endif

#include "Event.hh"
#include <cstddef>

using namespace std;

Event::Event() {
	this->ID = 0;
	this->particle = NULL;
	this->position = NULL;
	this->time = 0;
	this->sourceID = 0;
}

Event::Event(long ID, Point* position, Particle* particle, long time, int sourceID) {
	this->ID = ID;
	this->position = position;
	this->particle = particle;
	this->time =time;
	this->sourceID = sourceID;
}

long Event::getID() {
	return this->ID;
}

Point* Event::getPosition() {
	return this->position;
}

void Event::setPosition(Point* position) {
	this->position = position;
}

Particle* Event::getParticle() {
	return this->particle;
}

void Event::setParticle(Particle* particle) {
	this->particle = particle;
}

long Event::getTime() {
	return this->time;
}

void Event::setTime(long time) {
	this->time = time;
}

int Event::getSourceID(){
	return this->sourceID;
}
void Event::setSourceID(int sourceID){
	this->sourceID = sourceID;
}

