/*
 * SystemTime.hh
 *
 *  Created on: 05/12/2012
 *      Author: hector
 */

#ifndef SYSTEMTIME_HH_
#define SYSTEMTIME_HH_

class SystemTime{
private:
	long time;
public:
	SystemTime();
	long getTime();
	void addTime(long ntime);
	void setNewTime(long ntime);
};


#endif /* SYSTEMTIME_HH_ */
