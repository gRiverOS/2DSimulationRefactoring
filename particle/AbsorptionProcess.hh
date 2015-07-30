/*
 * AbsorptionProcess.hh
 *
 *  Created on: 10/11/2012
 *      Author: hector
 */

#ifndef ABSORPTIONPROCESS_HH_
#define ABSORPTIONPROCESS_HH_

#include "Process.hh"
#include "ParticleChange.hh"
#include "PhotonParticleChange.hh"

class AbsorptionProcess{
public:
	AbsorptionProcess();
	virtual ~AbsorptionProcess(){

	};
	virtual double getParticleChange(Particle * particle, Body * body){

		double mua = body->getMaterial()->getMaterialProperties()->getProperty("absorption_coefficient");
		double mus = body->getMaterial()->getMaterialProperties()->getProperty("scattering_coefficient");
		double abs = particle->getEnergy() * mua/(mua+mus);
		// cout << "AbsorptionProcess.hh: " << abs << endl;
		return abs;
	};
};


#endif /* ABSORPTIONPROCESS_HH_ */
