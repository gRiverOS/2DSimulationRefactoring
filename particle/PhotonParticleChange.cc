#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#endif

#include "PhotonParticleChange.hh"
#include "ParticleChange.hh"
#include "../common/Point.hh"
#include "../common/PointFactory.hh"
#include "../tracking/Step.hh"

PhotonParticleChange::PhotonParticleChange() : ParticleChange() {
	this->absorption = 0;
	this->scatter = PointFactory::getPoint();
}

PhotonParticleChange::PhotonParticleChange(ParticleChange * particleChange){
	this->absorption = dynamic_cast<PhotonParticleChange *>(particleChange)->getAbsorption();
	this->scatter = PointFactory::getPoint(dynamic_cast<PhotonParticleChange *>(particleChange)->getScatter());
}

Step* PhotonParticleChange::getStep() {
	return ParticleChange::getStep();
}

void PhotonParticleChange::setStep(Step* step) {
	ParticleChange::setStep(step);
}

double PhotonParticleChange::getAbsorption() {
	return this->absorption;
}

void PhotonParticleChange::setAbsorption(double absorption) {
	this->absorption = absorption;
}

Point* PhotonParticleChange::getScatter() {
	return this->scatter;
}

void PhotonParticleChange::setScatter(Point* scatter) {
	delete this->scatter;
	this->scatter = scatter;
}
