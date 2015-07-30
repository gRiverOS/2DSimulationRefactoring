/*
 * PhotonParticleHandler.hh
 *
 *  Created on: 10/11/2012
 *      Author: hector
 */

#ifndef PHOTONPROCESSHANDLER_HH_
#define PHOTONPROCESSHANDLER_HH_

#include "AbsorptionProcess.hh"
#include "ScatteringProcess.hh"
#include "../utils/Random.hh"
#include "ProcessHandler.hh"

#include <math.h>

class PhotonProcessHandler : public ProcessHandler{
private:
	AbsorptionProcess * absoptionProcess;
	ScatteringProcess * scatteringProcess;
	Random * random;

public:
	PhotonProcessHandler(AbsorptionProcess * absoptionProcess, ScatteringProcess * scatteringProcess, Random * random);
	virtual ~PhotonProcessHandler() {
		if(absoptionProcess != NULL)
			delete absoptionProcess;
		if(scatteringProcess  != NULL)
			delete scatteringProcess;
	};

	virtual ParticleChange * getParticleChange(Particle * particle, Body * body){
		PhotonParticleChange * photonParticleChange = new PhotonParticleChange();

		double mua = body->getMaterial()->getMaterialProperties()->getProperty("absorption_coefficient");
		double mus = body->getMaterial()->getMaterialProperties()->getProperty("scattering_coefficient");
		
		double steps = -log(random->RandomNumBetweenZeroOne())/(mua+mus);
		Step * step = new Step(steps);

		photonParticleChange->setScatter(scatteringProcess->getParticleChange(particle,body));
		photonParticleChange->setAbsorption(absoptionProcess->getParticleChange(particle,body));
		photonParticleChange->setStep(step);
		
		return photonParticleChange;
	};

	bool isReflected(Particle * p, Body * b, Body * nextb);
	AbsorptionProcess * getAbsoptionProcess();
	void setAbsoptionProcess(AbsorptionProcess * absoptionProcess);
	ScatteringProcess * getScatteringProcess();
	void setScatteringProcess(ScatteringProcess * scatteringProcess);
};

#endif /* PHOTONPARTICLEHANDLER_HH_ */
