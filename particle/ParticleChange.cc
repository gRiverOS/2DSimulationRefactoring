#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#endif

#include <cstddef>

#include "ParticleChange.hh"
#include "../tracking/Step.hh"

ParticleChange::ParticleChange() {
	this->step = new Step();
}

Step* ParticleChange::getStep() {
	return this->step;
}


void ParticleChange::setStep(Step* step) {
	delete this->step;
	this->step = step;
}
/*
 * ParticleChange.cc
 *
 *  Created on: 10/11/2012
 *      Author: hector
 */




