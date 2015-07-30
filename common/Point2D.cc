#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#endif


#include <stdlib.h>
#include <iostream>
#include <math.h>

#include "Point2D.hh"

Point2D::Point2D() {
   x = y = 0;
}

Point2D::Point2D(double n_x, double n_y) {
   x = n_x;
   y = n_y;
}

Point2D::Point2D(Point2D * v) {
   x = v->getX();
   y = v->getY();
}

double Point2D::getX() const {
	return x;
}

void Point2D::setX(double x) {
	this->x = x;
}

double Point2D::getY() const {
	return y;
}

void Point2D::setY(double y) {
	this->y = y;
}

double Point2D::length() {
	return sqrt((x * x) + (y * y));
}
