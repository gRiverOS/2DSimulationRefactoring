/*
 * Particle.hh
 *
 *  Created on: 21/10/2012
 *      Author: hector
 */

#ifndef PARTICLE_HH_
#define PARTICLE_HH_

#include "../common/Point.hh"

using namespace std;

class Particle {
private:
	Point * position;
	Point * direction;
	double energy;
public:
	Particle();
	Particle(double energy);
	Particle(Point * position, Point * direction, double energy);
	Particle(Particle * particle);
	Point * getPosition();
	void setPosition(Point * position);
	Point *getDirection();
	void setDirection(Point * direction);
	double getEnergy();
	void setEnergy(double energy);
	~Particle();
};


#endif /* PARTICLE_HH_ */
