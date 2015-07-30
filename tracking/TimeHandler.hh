/*
 * TimeHandler.hh
 *
 *  Created on: 05/12/2012
 *      Author: hector
 */

#ifndef TIMEHANDLER_HH_
#define TIMEHANDLER_HH_

class TimeHandler{
private:
	unsigned int time;
public:
	TimeHandler();
	unsigned int getTime();
	void addTime(unsigned int ntime);
	void setNewTime(unsigned int ntime);
};




#endif /* TIMEHANDLER_HH_ */
