/*
 * EVENTBUFFER_CC_.cc
 *
 *  Created on: 29/11/2012
 *      Author: hector
 */

#ifndef EVENTBUFFER_CC_
#define EVENTBUFFER_CC_

/*
 * EventBuffer.hh
 *
 *  Created on: 11/11/2012
 *      Author: hector
 */

#define UC_PLUSPLUS

#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#include  <uFile.h>
#endif
#include <iostream>
#include <vector>
#include "../event/Event.hh"

using namespace std;

_Monitor EventBuffer {
	vector<Event *> events;
	bool end_simulation;
	uCondition BufEmpty;
  public:
	EventBuffer(){
		end_simulation = false;
	};
	~EventBuffer() {
	};
	//Falta agregar no mutex
	int count() {
		return events.size();
	};

	void endSimulation(){
		this->end_simulation = true;
		BufEmpty.signal();
	}

	bool insert( vector<Event *> elem ){
		if(events.size() < 1){
			BufEmpty.signal();
			events = elem;
			return true;
		} else
			return false;
	};
	vector<Event *> remove(bool &endSimulation){
		vector<Event *> elem;

		if(this->end_simulation){
			if(events.size() > 0){
				elem = events;
				events.clear();
			}
			endSimulation = this->end_simulation;
			return elem;
		}

		if(events.size() < 1)
			BufEmpty.wait();

		endSimulation = this->end_simulation;

		if(this->end_simulation){
			if(events.size() > 0 ){
				elem = events;
				events.clear();
			}
			return elem;
		}

		elem = events;
		events.clear();
		return elem;
	}
};

#endif /* EVENTBUFFER_CC_ */
