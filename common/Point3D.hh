#ifndef POINT3D_HH_
#define POINT3D_HH_

#include <stdlib.h>
#include <iostream>

#include "Point.hh"

class Point3D : public Point{
	private:
		double x;
		double y;
		double z;
	public:
		Point3D();
		Point3D(double n_x, double n_y, double n_z);
		Point3D(Point3D * v);

		double getX() const;
		void setX(double x);
		double getY() const;
		void setY(double y);
		double getZ() const;
		void setZ(double z);
		double length();

		virtual ~Point3D() {
		};

		virtual Point3D * operator+(const Point * v) {
			return new Point3D(
				(x + dynamic_cast<const Point3D*>(v)->getX()), 
				(y + dynamic_cast<const Point3D*>(v)->getY()), 
				(z + dynamic_cast<const Point3D*>(v)->getZ()) 
			);
		};
		virtual Point3D * operator-(const Point * v) {
			return new Point3D(
				(x - dynamic_cast<const Point3D*>(v)->getX()), 
				(y - dynamic_cast<const Point3D*>(v)->getY()),
				(z - dynamic_cast<const Point3D*>(v)->getZ())
			);
		};
		virtual Point3D * operator*(double w) {
			return new Point3D((x * w), (y * w), (z * w));
		};
		virtual Point3D * operator/(double w) {
			return new Point3D((x / w), (y / w), (z / w));
		};
		virtual Point3D * operator=(const Point * v) {
			x = dynamic_cast<const Point3D*>(v)->getX();
			y = dynamic_cast<const Point3D*>(v)->getY();
			z = dynamic_cast<const Point3D*>(v)->getZ();
			return this;
		};
		virtual string toString() {
			stringstream s;
			s << x << " " << y << " " << z;
			return s.str();
		};
};

#endif /* POINT3D_HH_ */
