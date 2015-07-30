#include "SystemTime.hh"

SystemTime::SystemTime() {
	this->time = 0;
}

long SystemTime::getTime() {
	return this->time;
}

void SystemTime::addTime(long ntime) {
	this->time+= ntime;
}

void SystemTime::setNewTime(long ntime) {
	this->time = ntime;
}
