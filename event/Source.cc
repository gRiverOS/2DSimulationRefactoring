#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#endif

#include "Source.hh"
#include "../body/Geometry.hh"

#include <cstddef>

using namespace std;

Source::Source() {
	this->geometry = NULL;
	this->particleNumbers = 0;
	this->emitedParticles = 0;
	this->ID = 0;
}

Source::~Source() {
	delete this->geometry;
}

Geometry* Source::getGemeotry() {
	return this->geometry;
}

void Source::setGeometry(Geometry* geometry) {
	this->geometry = geometry;
}

int Source::getParticleNumbers() {
	return this->particleNumbers;
}

void Source::setParticleNumbers(int partucleNumbers) {
	this->particleNumbers = partucleNumbers;
}

int Source::getEmitedParticles() {
	return this->emitedParticles;
}

void Source::setEmitedParticles(int emitedParticles) {
	this->emitedParticles = emitedParticles;
}

int Source::getID(){
	return this->ID;
}
void Source::setID(int ID){
	this->ID = ID;
}

Point* Source::getDirection(){
	return this->direction;
}
void Source::setDirection(Point* direction){
	this->direction = direction;
}
double Source::getAngularAperture(){
	return this->angularAperture;
}
void Source::setAngularAperture(double angularAperture){
	this->angularAperture = angularAperture;
}

Point * Source::getRandomDirection() {
	if (this->direction == NULL) {
		return this->geometry->getRandomDirection();
	}
	else {
		return this->geometry->getRandomDirection(this->direction, this->angularAperture);
	}
}