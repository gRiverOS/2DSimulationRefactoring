#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#endif


#include <iostream>
#include <math.h>
#include "Circumference.hh"
#include "../../common/Point2D.hh"
#include "../../common/Point.hh"

using namespace std;

Circumference::Circumference(){
	radius = 1;
	center = new Point2D(0.0,0.0);
}

Circumference::Circumference(string n_Name) : Geometry(n_Name){
	center = new Point2D(0.0,0.0);
	radius = 1;
}
Circumference::Circumference(string n_Name, Point2D * n_Center, double n_Radio) : Geometry(n_Name){
	center = n_Center;
	radius = n_Radio;
}

Circumference::~Circumference(){
	delete center;
}

Point2D * Circumference::getCenter(){
	return center;
}

double Circumference::getRadius(){
	return radius;
}

void Circumference::setRadius(double n_Radio){
	radius = n_Radio;
}

void Circumference::setCenter(Point2D * n_Center){
	center = n_Center;
}
