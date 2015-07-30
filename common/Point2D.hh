#ifndef POINT2D_HH_
#define POINT2D_HH_

#include <stdlib.h>
#include <iostream>

#include "Point.hh"

class Point2D : public Point{
	private:
		double x;
		double y;
	public:
		Point2D();
		Point2D(double n_x, double n_y);
		Point2D(Point2D * v);

		double getX() const;
		void setX(double x);
		double getY() const;
		void setY(double y);
		double length();

		virtual ~Point2D() {
		};

		virtual Point2D * operator+(const Point * v) {
			return new Point2D((x + dynamic_cast<const Point2D*>(v)->getX()), (y + dynamic_cast<const Point2D*>(v)->getY()));
		};
		virtual Point2D * operator-(const Point * v) {
			return new Point2D((x - dynamic_cast<const Point2D*>(v)->getX()), (y - dynamic_cast<const Point2D*>(v)->getY()));
		};
		virtual Point2D * operator*(double w) {
			return new Point2D((x * w), (y * w));
		};
		virtual Point2D * operator/(double w) {
			return new Point2D((x / w), (y / w));
		};
		virtual Point2D * operator=(const Point * v) {
			x = dynamic_cast<const Point2D*>(v)->getX();
			y = dynamic_cast<const Point2D*>(v)->getY();
			return this;
		};
		virtual string toString() {
			stringstream s;
			s << x << " " << y;
			return s.str();
		};
};

#endif /* POINT2D_HH_ */
