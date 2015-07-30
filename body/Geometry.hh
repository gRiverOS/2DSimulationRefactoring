/*
 * Geometry.hh
 *
 *  Created on: 09/10/2012
 *      Author: hector
 */

#ifndef GEOMETRY_HH_
#define GEOMETRY_HH_

#include <iostream>
#include <string>
#include "../common/Point.hh"

using namespace std;

class Geometry {
private:
	string name;
public:
	Geometry();
	Geometry(string n_Name);
	virtual ~Geometry();
	void setName(string n_Name);
	string getName();
	virtual bool insideGeometry(Point * point) = 0;
	virtual Point * getIntersectionPoint(Point * pointOne, Point * pointTwo) = 0;
	virtual Point * getRandomPoint() = 0;
	virtual Point * getRandomDirection() = 0;
	virtual Point * getRandomDirection(Point * direction, double angularAperture) = 0;
	virtual Point * getReflection(Point * pointone, Point * pointtwo, Point * direction) = 0;
	virtual double getIncidenceAngle(Point * point, Point * direction) = 0;
};

#endif /* GEOMETRY_HH_ */
