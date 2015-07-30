#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#endif


#include <stdlib.h>
#include <iostream>
#include <math.h>

#include "Point.hh"
#include "Point2D.hh"
#include "Point3D.hh"
#include "PointFactory.hh"

PointFactory::PointFactory() {
}
Point* PointFactory::getPoint() {
    if (dimensions == 2) return new Point2D();
    if (dimensions == 3) return new Point3D();
    return NULL;
}

Point* PointFactory::getPoint(int dim) {
    if (dim == 2) return new Point2D();
    if (dim == 3) return new Point3D();
    return NULL;
}

Point* PointFactory::getPoint(double n_x, double n_y) {
    return new Point2D(n_x, n_y);
}

Point* PointFactory::getPoint(double n_x, double n_y, double n_z) {
    return new Point3D(n_x, n_y, n_z);
}

Point* PointFactory::getPoint(Point* p) {
    if (p == NULL) return NULL;
    if (dimensions == 2) return new Point2D(dynamic_cast<Point2D *>(p));
    if (dimensions == 3) return new Point3D(dynamic_cast<Point3D *>(p));
    return NULL;
}