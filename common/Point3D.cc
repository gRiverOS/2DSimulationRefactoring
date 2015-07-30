#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#endif


#include <stdlib.h>
#include <iostream>
#include <math.h>

#include "Point3D.hh"

Point3D::Point3D() {
   x = y = z = 0;
}

Point3D::Point3D(double n_x, double n_y, double n_z) {
   x = n_x;
   y = n_y;
   z = n_z;
}

Point3D::Point3D(Point3D * v) {
   x = v->getX();
   y = v->getY();
   z = v->getZ();
}
double Point3D::getX() const {
	return x;
}

void Point3D::setX(double x) {
	this->x = x;
}

double Point3D::getY() const {
	return y;
}

void Point3D::setY(double y) {
	this->y = y;
}

double Point3D::getZ() const {
	return z;
}

void Point3D::setZ(double z) {
	this->z = z;
}

double Point3D::length() {
	return sqrt((x * x) + (y * y) + (z * z));
}
