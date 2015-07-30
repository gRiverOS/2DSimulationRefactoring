/*
 * Process.hh
 *
 *  Created on: 10/11/2012
 *      Author: hector
 */

#ifndef PROCESS_HH_
#define PROCESS_HH_

#include "ParticleChange.hh"
#include "Particle.hh"
#include "../body/Body.hh"

class Process{
public:
	virtual ~Process() {
	};
	virtual ParticleChange * getParticleChange(Particle * particle, Body * body) = 0;

};


#endif /* PROCESS_HH_ */
