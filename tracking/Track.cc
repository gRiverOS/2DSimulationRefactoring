#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#endif


#include "Track.hh"
#include <stddef.h>

Track::Track() {
	this->particle = NULL;
	this->particleChange = NULL;
	this->eventID = 0;
	this->time = 0;
	this->sourceID = 0;
}

Track::Track(Particle* particle, ParticleChange* particleChange, int eventID, unsigned int time, int sourceID) {
	this->particle = particle;
	this->particleChange = particleChange;
	this->eventID = eventID;
	this->time = time;
	this->sourceID = sourceID;
}

Track::~Track() {
	delete this->particle;
	delete this->particleChange;
}

Particle * Track::getParticle() {
	return this->particle;
}

void Track::setParticle(Particle * particle) {
	this->particle = particle;
}

ParticleChange * Track::getParticleChange() {
	return this->particleChange;
}

void Track::setParticleChange(ParticleChange * particleChange) {
	this->particleChange = particleChange;
}

int Track::getEventID() {
	return this->eventID;
}

void Track::setEventID(int eventID) {
	this->eventID = eventID;
}

long Track::getTime() {
	return this->time;
}


int Track::getSourceID(){
	return this->sourceID;
}
void Track::setSourceID(int sourceID){
	this->sourceID = sourceID;
}

void Track::setTime(long time) {
	this->time = time;
}

/*
 * Track.cc
 *
 *  Created on: 26/11/2012
 *      Author: hector
 */


