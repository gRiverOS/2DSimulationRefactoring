/*
 * EventDispatcher.hh
 *
 *  Created on: 09/11/2012
 *      Author: hector
 */

#ifndef EVENTDISPATCHER_HH_
#define EVENTDISPATCHER_HH_

#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#include  <uFile.h>
#endif

#include "Buffer.cc"
#include "../event/EventFactory.hh"
#include "EventBuffer.cc"
#include "TimeHandler.hh"

_Task EventDispatcher {
private:
	EventFactory * eventFactory;
	vector<EventBuffer *> buffers;
	TimeHandler * clock;
	int buffersize;
    void main(){
    	long time = clock->getTime();
    	vector<Event *> events;
    	events = eventFactory->getEvents("photon",buffersize,time);
    	int k = 0;
    	while(events.size() != 0){
    		//if(k % 10 == 0)
    			//cout << "Dispatched: "  << ((k + 10)/10) * 10000 << endl;
    		for(unsigned int i = k; ; i++){
    			if(i == buffers.size()){
    				i = 0;
    				k = 0;
    			}
    			k++;
    			if(buffers[i]->insert(events)){
    				break;
    			}
    		}

    		this->clock->setNewTime(time);
    		events = eventFactory->getEvents("photon",buffersize,time);
    		//k++;

    	}

    	for(unsigned int j = 0;j < buffers.size(); j++)
    		buffers[j]->endSimulation();

    	cout << "dispatcher done!" << endl;
    };
  public:
    EventDispatcher( EventFactory * ef , vector<EventBuffer * > buf, int buffersize);
    ~EventDispatcher();
};

#endif /* EVENTDISPATCHER_HH_ */
