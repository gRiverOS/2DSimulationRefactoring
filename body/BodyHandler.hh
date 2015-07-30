/*
 * Vector.hh
 *
 *  Created on: 09/10/2012
 *      Author: hector
 */

#ifndef BODYHANDLER_HH_
#define BODYHANDLER_HH_

#include "Body.hh"
#include "../common/Point.hh"
#include "../tracking/Step.hh"

using namespace std;

class BodyHandler {
public:
	virtual ~BodyHandler(){
	};
	virtual Body * getBody(Point * position) = 0;
	virtual Point * getNextPosition(Point * position, Point * direction, Step * step) = 0;
};

#endif /* BODYHANDLER_HH_ */
