/*
 * Event.hh
 *
 *  Created on: 06/11/2012
 *      Author: hector
 */

#ifndef EVENT_HH_
#define EVENT_HH_

#include "../common/Point.hh"
#include "../particle/Particle.hh"

using namespace std;

class Event {
private:
	long ID;
	int sourceID;
	Point * position;
	Particle * particle;
	long time;
public:
	Event();
	Event(long ID,Point * position,Particle * particle, long time,int sourceID);
	~Event(){
		delete position;
		delete particle;
	};
	long getID();
	Point * getPosition();
	void setPosition(Point * position);
	Particle * getParticle();
	void setParticle(Particle * particle);
	long getTime();
	void setTime(long time);
	int getSourceID();
	void setSourceID(int sourceID);
};


#endif /* EVENT_HH_ */
