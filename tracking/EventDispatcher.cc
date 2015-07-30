#include "EventDispatcher.hh"
#include "EventBuffer.cc"

#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#include  <uFile.h>
#endif

EventDispatcher::EventDispatcher( EventFactory * ef , vector<EventBuffer * > buf, int buffersize)
: eventFactory( ef ) , buffers (buf){
	this->clock = new TimeHandler();
	this->buffersize = buffersize;
}

EventDispatcher::~EventDispatcher(){
	delete eventFactory;
	delete clock;
}

