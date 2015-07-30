/*
 * Vector.hh
 *
 *  Created on: 09/10/2012
 *      Author: hector
 */

#ifndef GEOMETRYALGORITHM_HH_
#define GEOMETRYALGORITHM_HH_

#include "../common/Point2D.hh"
#include "../common/Point3D.hh"
#include <vector>

using namespace std;

class GeometryAlgorithms {
private:
	float Determinant(float x1, float x2, float y1, float y2);
public:
	GeometryAlgorithms();
	~GeometryAlgorithms();
	Point2D * getLineLineIntersection(Point2D * pointOne, Point2D * pointTwo, Point2D * pointThree, Point2D * pointFour);
	vector<Point2D *> getLineCircumferenceIntersection(Point2D * pointOne, Point2D * pointTwo, Point2D * center, double radius);
	double distanceBetweenPoints(Point2D * pointOne, Point2D * pointTwo);
	double distanceBetweenPoints(Point3D * pointOne, Point3D * pointTwo);
	double Fresnel(double n1, double n2, double coshit);
};

#endif /* BODYHANDLER_HH_ */
