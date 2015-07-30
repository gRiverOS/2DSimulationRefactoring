#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#endif

#include "../common/Point.hh"
#include "../common/PointFactory.hh"
#include "Particle.hh"

Particle::Particle() {
	this->energy = 0;
	this->direction = PointFactory::getPoint();
	this->position = PointFactory::getPoint();
}

Particle::Particle(double energy) {
	this->energy = energy;
	this->direction = PointFactory::getPoint();
	this->position = PointFactory::getPoint();
}

Particle::Particle(Point* position, Point* direction, double energy) {
	this->energy = energy;
	this->direction = direction;
	this->position = position;
}

Particle::Particle(Particle * particle){
	this->energy = particle->getEnergy();
	this->position = PointFactory::getPoint(particle->getPosition());
	this->direction = PointFactory::getPoint(particle->getDirection());
}

Point* Particle::getPosition() {
	return this->position;
}

void Particle::setPosition(Point* position) {
	delete this->position;
	this->position = position;
}

Point* Particle::getDirection() {
	return this->direction;
}

void Particle::setDirection(Point* direction) {
	delete this->direction;
	this->direction = direction;
}

double Particle::getEnergy() {
	return this->energy;
}

void Particle::setEnergy(double energy) {
	this->energy = energy;
}

Particle::~Particle() {
	delete this->direction;
	delete this->position;
}
