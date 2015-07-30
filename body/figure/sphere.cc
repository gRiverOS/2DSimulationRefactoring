#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#endif


#include <iostream>
#include <math.h>
#include "Sphere.hh"
#include "../../common/Point3D.hh"
#include "../../common/Point.hh"

using namespace std;

Sphere::Sphere(){
	radius = 1;
	center = new Point3D(0.0,0.0,0.0);
}

Sphere::Sphere(string n_Name) : Geometry(n_Name){
	center = new Point3D(0.0,0.0, 0.0);
	radius = 1;
}
Sphere::Sphere(string n_Name, Point3D * n_Center, double n_Radio) : Geometry(n_Name){
	center = n_Center;
	radius = n_Radio;
}

Sphere::~Sphere(){
	delete center;
}

Point3D * Sphere::getCenter(){
	return center;
}

double Sphere::getRadius(){
	return radius;
}

void Sphere::setRadius(double n_Radio){
	radius = n_Radio;
}

void Sphere::setCenter(Point3D * n_Center){
	center = n_Center;
}
