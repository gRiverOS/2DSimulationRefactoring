/*
 * Track.hh
 *
 *  Created on: 26/11/2012
 *      Author: hector
 */

#ifndef TRACK_HH_
#define TRACK_HH_

#include "../particle/ParticleChange.hh"
#include "../particle/Particle.hh"
using namespace std;

class Track{
private:
	int eventID;
	int sourceID;
	long time;
	Particle * particle;
	ParticleChange * particleChange;
public:
	Track();
	Track(Particle * particle, ParticleChange * particleChange, int eventID, unsigned int time, int sourceID);
	~Track();
	Particle * getParticle();
	void setParticle(Particle * particle);
	ParticleChange * getParticleChange();
	void setParticleChange(ParticleChange * particleChange);
	int getEventID();
	void setEventID(int eventID);
	long getTime();
	void setTime(long time);
	int getSourceID();
	void setSourceID(int sourceID);
};


#endif /* TRACK_HH_ */
