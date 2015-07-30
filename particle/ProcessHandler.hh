/*
 * ProcessHandler.hh
 *
 *  Created on: 10/11/2012
 *      Author: hector
 */

#ifndef PROCESSHANDLER_HH_
#define PROCESSHANDLER_HH_

#include "ParticleChange.hh"
#include "../body/Body.hh"
#include "Particle.hh"

class ProcessHandler{
public:
	virtual ~ProcessHandler(){
	};
	virtual ParticleChange * getParticleChange(Particle * particle, Body * body) = 0;
};

#endif /* PROCESSHANDLER_HH_ */
