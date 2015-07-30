/*
 * Point.hh
 *
 *  Created on: 09/10/2012
 *      Author: hector
 */

#ifndef POINT_HH_
#define POINT_HH_

#include <sstream>
using namespace std;

class Point {
	public:
		virtual ~Point() {} ;
		virtual Point * operator+(const Point * v) = 0;
		virtual Point * operator-(const Point * v) = 0;
		virtual Point * operator*(double v) = 0;
		virtual Point * operator/(double v) = 0;
		virtual Point * operator=(const Point * v) = 0;

		/*
		 * Analizar si corresponde reemplazar por el operador '<<'
		 */
		virtual string toString() = 0;
};

#endif /* POINT_HH_ */
