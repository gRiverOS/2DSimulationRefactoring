#ifndef POINTFACTORY_HH_
#define POINTFACTORY_HH_

#include <stdlib.h>
#include <iostream>

#include "Point.hh"
#include "Point2D.hh"
#include "Point3D.hh"

class PointFactory {
    private:
        
    public:
        static int dimensions;
        PointFactory();
        static Point* getPoint();
        static Point* getPoint(int dim);
        // static Point* getPoint(string dim);
        static Point* getPoint(double n_x, double n_y);
        static Point* getPoint(double n_x, double n_y, double n_z);
        static Point* getPoint(Point* p);
};

#endif /* POINTFACTORY_HH_ */