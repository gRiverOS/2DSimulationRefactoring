#ifndef SPHERE_HH
#define SPHERE_HH

#include <iostream>
#include <string>
#include "../../common/Point3D.hh"
#include "../../common/Point.hh"
#include "../../utils/GeometryAlgorithms.hh"
#include "../../utils/Random.hh"
#include "../Geometry.hh"
#include <math.h>
#include <stddef.h>

using namespace std;

class Sphere: public Geometry {
private:
	string name;
	Point3D * center;
	double radius;
public:
	Sphere();
	Sphere(string n_Name);
	Sphere(string n_Name, Point3D * n_Center, double n_Radio);
	~Sphere();
	Point3D * getCenter();
	double getRadius();
	void setRadius(double n_Radio);
	void setCenter(Point3D * n_Center);

	virtual bool insideGeometry(Point * n_point) {
		double deltaX = dynamic_cast<Point3D *>(n_point)->getX() - center->getX();
		double deltaY = dynamic_cast<Point3D *>(n_point)->getY() - center->getY();
		double deltaZ = dynamic_cast<Point3D *>(n_point)->getZ() - center->getZ();

		double deltaR = sqrt((double) (deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ));
		if (deltaR <= radius)
			return true;
		else
			return false;
	}
	
	virtual Point * getIntersectionPoint(Point * pointOne, Point * pointTwo){
		return NULL;
	}

	virtual Point * getRandomPoint(){
		return NULL;
	}

	virtual Point * getReflection(Point * pointone, Point * pointtwo, Point * direction){
		return NULL;	
	}
};

#endif
