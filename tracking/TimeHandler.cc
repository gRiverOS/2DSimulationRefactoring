/*
 * TimeHandler.cc
 *
 *  Created on: 05/12/2012
 *      Author: hector
 */

#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#endif


#include "TimeHandler.hh"

TimeHandler::TimeHandler() {
	this->time = 1;
}

unsigned int TimeHandler::getTime() {
	return this->time;
}

void TimeHandler::addTime(unsigned int ntime) {
	this->time+= ntime;
}

void TimeHandler::setNewTime(unsigned int ntime) {
	this->time = ntime;
}




