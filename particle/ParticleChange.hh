/*
 * ParticleChange.hh
 *
 *  Created on: 10/11/2012
 *      Author: hector
 */

#ifndef PARTICLECHANGE_HH_
#define PARTICLECHANGE_HH_

#include "../tracking/Step.hh"

class ParticleChange{
private:
	Step * step;
public:
	ParticleChange();
	virtual ~ParticleChange(){
		delete this->step;
	};
	Step * getStep();
	void setStep(Step * step);
};


#endif /* PARTICLECHANGE_HH_ */
