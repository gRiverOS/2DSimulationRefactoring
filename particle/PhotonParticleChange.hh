/*
 * PhotonParticleChange.hh
 *
 *  Created on: 10/11/2012
 *      Author: hector
 */

#ifndef PHOTONPARTICLECHANGE_HH_
#define PHOTONPARTICLECHANGE_HH_

#include "ParticleChange.hh"

#include "../common/Point.hh"
#include "../tracking/Step.hh"

class PhotonParticleChange : public ParticleChange{
private:
	double absorption;
	Point * scatter;
public:
	PhotonParticleChange();
	PhotonParticleChange(ParticleChange * particleChange);
	virtual ~PhotonParticleChange() {
		delete this->scatter;
	};
	Step * getStep();
	void setStep(Step * step);
	double getAbsorption();
	void setAbsorption(double absorption);
	Point * getScatter();
	void setScatter(Point * scatter);
};

#endif /* PHOTONPARTICLECHANGE_HH_ */
