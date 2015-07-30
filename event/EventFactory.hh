/*
 * EventFactory.hh
 *
 *  Created on: 06/11/2012
 *      Author: hector
 */

#ifndef EVENTFACTORY_HH_
#define EVENTFACTORY_HH_

#include "Event.hh"
#include "SourceHandler.hh"
#include <string>
#include "../utils/Random.hh"

using namespace std;

class EventFactory{
protected:
	SourceHandler * sourceHandler;
	Random * random;
	long eventID;
public:
	EventFactory();
	EventFactory(SourceHandler * sourceHandler, Random * random);
	SourceHandler * getSourceHandler();
	void setSourceHandler(SourceHandler * sourceHandler);
	virtual ~EventFactory();
	virtual Event * getEvent(string name,long &time);
	virtual vector<Event *> getEvents(string name,unsigned int number,long &time);

};


#endif /* EVENTFACTORY_HH_ */
