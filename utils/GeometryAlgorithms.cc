#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#endif

#include "../common/Point2D.hh"
#include "GeometryAlgorithms.hh"

#include <stdlib.h>
#include <limits>
#include <vector>
#include <math.h>

#include <float.h>
#include <stdio.h>

float GeometryAlgorithms::Determinant(float x1, float x2, float y1, float y2) {
    return (x1 * y2 - y1 * x2);
}

GeometryAlgorithms::GeometryAlgorithms() {
}

GeometryAlgorithms::~GeometryAlgorithms() {
}

Point2D * GeometryAlgorithms::getLineLineIntersection(Point2D * pointOne,
        Point2D * pointTwo, Point2D * pointThree, Point2D * pointFour) {

    /*  double x1 = pointOne->getX() , y1 = pointOne->getY() , x2 = pointTwo->getX(), y2 = pointTwo->getY(),
     x3 = pointThree->getX() , y3 = pointThree->getY(), x4 = pointFour->getX(), y4 = pointFour->getY();
     double  d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
     if (d == 0)
     return NULL;

     double xi = ((x3 - x4) * (x1 * y2 - y1 * x2) - (x1 - x2) * (x3 * y4 - y3 * x4))
     / d;
     double yi = ((y3 - y4) * (x1 * y2 - y1 * x2) - (y1 - y2) * (x3 * y4 - y3 * x4))
     / d;

     cout << "interseccion: (" << xi << "," << yi << ")" << endl;
     return new Point2D(xi, yi);*/

    // Store the values for fast access and easy
    // equations-to-code conversion
    /* double x1 = pointOne->getX(), x2 = pointTwo->getX(), x3 = pointThree->getX(), x4 = pointFour->getX();
     double y1 =pointOne->getY(), y2 = pointTwo->getY(), y3 = pointThree->getY(), y4 = pointFour->getY();

     cout << "linea: (" << x3 << "," << y3 <<"),(" << x4 << "," << y4 << ")" << endl;
     cout << "tofind: (" << x1 << "," << y1 <<"),(" << x2 << "," << y2 << ")" << endl;
     double d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
     // If d is zero, there is no intersection
     if (d == 0) return NULL;

     // Get the x and y
     double pre = (x1*y2 - y1*x2), post = (x3*y4 - y3*x4);
     double x = ( pre * (x3 - x4) - (x1 - x2) * post ) / d;
     double y = ( pre * (y3 - y4) - (y1 - y2) * post ) / d;

     // Check if the x and y coordinates are within both lines
     if ( x < min(x1, x2) || x > max(x1, x2) ||
     x < min(x3, x4) || x > max(x3, x4) ) return NULL;
     if ( y < min(y1, y2) || y > max(y1, y2) ||
     y < min(y3, y4) || y > max(y3, y4) ) return NULL;*/

    /* double m1, c1, m2, c2;    float s1_x, s1_y, s2_x, s2_y;
    s1_x = p1_x - p0_x;     s1_y = p1_y - p0_y;
    s2_x = p3_x - p2_x;     s2_y = p3_y - p2_y;

    float s, t;
    s = (-s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y)) / (-s2_x * s1_y + s1_x * s2_y);
    t = ( s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x)) / (-s2_x * s1_y + s1_x * s2_y);

    if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
    {
        // Collision detected
        if (i_x != NULL)
            *i_x = p0_x + (t * s1_x);
        if (i_y != NULL)
            *i_y = p0_y + (t * s1_y);
        return 1;
    }

    return 0; // No collision
    double x1, y1, x2, y2;
    double dx, dy;
    double intersection_X, intersection_Y;

    x1 = pointOne->getX();
    y1 = pointOne->getY();

    x2 = pointTwo->getX();
    y2 = pointTwo->getY();

    cout << "tofind: (" << pointOne->getX() << "," << pointOne->getY() << "),("
            <<  pointTwo->getX() << "," << pointTwo->getY() << ")" << endl;

    dx = x2 - x1;
    dy = y2 - y1;
    m1 = dy / dx;

    c1 = y1 - m1 * x1; // which is same as y2 - slope * x2

    cout << "lane: (" << pointThree->getX() << "," << pointThree->getY() << "),("
            << pointFour->getX() << "," << pointFour->getY() << ")" << endl;

    x1 = pointThree->getX();
    y1 = pointThree->getY();

    x2 = pointFour->getX();
    y2 = pointFour->getY();

    dx = x2 - x1;
    dy = y2 - y1;

    m2 = dy / dx;
    c2 = y2 - m2 * x2; // which is same as y2 - slope * x2

    cout << "c1: " << c1 << ",c2" << c2 << ",m1" << m1 << ",m2" << m2 << endl;
    if( (m1 - m2) == 0)
            return NULL;
        else
        {
            intersection_X = (c2 - c1) / (m1 - m2);
            intersection_Y = m1 * intersection_X + c1;
            cout << "interseccion: (" << intersection_X << "," << intersection_Y << ")" << endl;
                return new Point2D(intersection_X, intersection_Y);
        }*/

    // Return the point of intersection
    
    /////////////////////////////////////////////////////////////////////////////////////

    /* Codigo hector */
    // double p0_x = pointOne->getX() , p0_y = pointOne->getY() , p1_x = pointTwo->getX(), p1_y = pointTwo->getY(),
    //         p2_x = pointThree->getX() , p2_y = pointThree->getY(), p3_x = pointFour->getX(), p3_y = pointFour->getY();

    // double i_x,i_y;
    // double s1_x, s1_y, s2_x, s2_y;
    // s1_x = p1_x - p0_x;     s1_y = p1_y - p0_y;
    // s2_x = p3_x - p2_x;     s2_y = p3_y - p2_y;

    // double s, t;
    // s = (-s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y)) / (-s2_x * s1_y + s1_x * s2_y);
    // t = ( s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x)) / (-s2_x * s1_y + s1_x * s2_y);

    // if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
    // {
    //     // Collision detected
    //     i_x = p0_x + (t * s1_x);
    //     i_y = p0_y + (t * s1_y);

    //     return new Point2D(i_x,i_y);
    // }

    // return NULL; // No collision

    //////////////////////////////////////////////////////////////////////////////////

    // Se obtiene la interseccion a traves de la ecuacion de la recta

    double x1, x2, x3, x4, y1, y2, y3, y4;
    double m1, m2;
    double x, y;

    // Se definen los puntos  
    x1 = pointOne->getX();
    y1 = pointOne->getY();

    x2 = pointTwo->getX();
    y2 = pointTwo->getY();

    x3 = pointThree->getX();
    y3 = pointThree->getY();

    x4 = pointFour->getX();
    y4 = pointFour->getY();


    // Dos rectas paralelas verticales
    if (fabs(x2 - x1) < DBL_EPSILON && fabs(x4 - x3) < DBL_EPSILON) {
    // if ((x2 - x1) == 0 && (x4 - x3) == 0) {
        return NULL;
    }

    // Una recta vertical y otra no
    else if (fabs(x2 - x1) < DBL_EPSILON && fabs(x4 - x3) > DBL_EPSILON) {
    // else if ((x2 - x1) == 0 && (x4 - x3) != 0) {
        // m1 -> infinito  and  m2 pertenece a los reales
        m2 = (y4 - y3) / (x4 - x3);
        x = x1;
        y = m2 * (x1 - x3) + y3;
        return new Point2D(x, y);
    }

    else if (fabs(x2 - x1) > DBL_EPSILON && fabs(x4 - x3) < DBL_EPSILON) {
    // else if ((x2 - x1) != 0 && (x4 - x3) == 0) {
        // m2 -> infinito  and  m1 pertenece a los reales
        m1 = (y2 - y1) / (x2 - x1);
        x = x3;
        y = m1 * (x3 - x1) + y1;
        return new Point2D(x, y);
    }

    else {
        m1 = (y2 - y1) / (x2 - x1);
        m2 = (y4 - y3) / (x4 - x3);

        // Rectas paralelas
        if (fabs(m1 - m2) < DBL_EPSILON) {
        // if (m1 == m2) {
            return NULL;
        }
        else {
            x = (m1 * x1 - y1 + y3 - m2 * x3) / (m1 - m2);
            y = (m1 * m2 * (x1 - x3) + y3 * m1 - y1 * m2) / (m1 - m2);
            return new Point2D(x, y);
        }
    }

}

/* Point2D * GeometryAlgorithms::getLineLineIntersection(Point2D * pointOne,
 Point2D * pointTwo, Point2D * pointThree, Point2D * pointFour) {

 float a = Determinant(pointOne->getX() - pointTwo->getX(), pointOne->getY() - pointTwo->getY(), pointThree->getX() - pointFour->getX(), pointThree->getY() - pointFour->getY());
 if (abs(a) < numeric_limits<float>::epsilon( ) ) return NULL; // Lines are parallel

 float d1 = Determinant(pointOne->getX(), pointOne->getY(), pointTwo->getX(), pointTwo->getY());
 float d2 = Determinant(pointThree->getX(), pointThree->getY(), pointFour->getX(), pointFour->getY());
 float x = Determinant(d1, pointOne->getX() - pointTwo->getX(), d2, pointThree->getX() - pointFour->getX()) / a;
 float y = Determinant(d1, pointOne->getY() - pointTwo->getY(), d2, pointThree->getY() - pointFour->getY()) / a;

 if (x < min(pointOne->getX(), pointTwo->getX()) || x > max(pointOne->getX(), pointTwo->getX())) return NULL;
 if (y < min(pointOne->getY(), pointTwo->getY()) || y > max(pointOne->getY(), pointTwo->getY())) return NULL;
 if (x < min(pointThree->getX(), pointFour->getX()) || x > max(pointThree->getX(), pointFour->getX())) return NULL;
 if (y < min(pointThree->getY(), pointFour->getY()) || y > max(pointThree->getY(), pointFour->getY())) return NULL;

 return new Point2D(x, y);


 } */

/*Point2D * GeometryAlgorithms::getLineLineIntersection(Point2D * p1,
 Point2D * p2, Point2D * p3, Point2D * p4) {

 float x1 = p1->getX(), x2 = p2->getX(), x3 = p3->getX(), x4 = p4->getX();
 float y1 = p1->getY(), y2 = p2->getY(), y3 = p3->getY(), y4 = p4->getY();

 float d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
 // If d is zero, there is no intersection
 if (d == 0) return NULL;

 // Get the x and y
 float pre = (x1*y2 - y1*x2), post = (x3*y4 - y3*x4);
 float x = ( pre * (x3 - x4) - (x1 - x2) * post ) / d;
 float y = ( pre * (y3 - y4) - (y1 - y2) * post ) / d;

 // Check if the x and y coordinates are within both lines
 if ( x < min(x1, x2) || x > max(x1, x2) ||
 x < min(x3, x4) || x > max(x3, x4) ) return NULL;
 if ( y < min(y1, y2) || y > max(y1, y2) ||
 y < min(y3, y4) || y > max(y3, y4) ) return NULL;

 // Return the point of intersection
 Point2D * ret = new Point2D();
 ret->setX(x);
 ret->setY(y);
 return ret;


 }*/

vector<Point2D*> GeometryAlgorithms::getLineCircumferenceIntersection(
        Point2D* pointOne, Point2D* pointTwo, Point2D* center, double radius) {

    vector<Point2D *> result;
    double baX = pointTwo->getX() - pointOne->getX();
    double baY = pointTwo->getY() - pointOne->getY();
    double caX = center->getX() - pointOne->getX();
    double caY = center->getY() - pointOne->getY();

    double a = baX * baX + baY * baY;
    double bBy2 = baX * caX + baY * caY;
    double c = caX * caX + caY * caY - radius * radius;

    double pBy2 = bBy2 / a;
    double q = c / a;

    double disc = pBy2 * pBy2 - q;
    if (disc < 0) {
        return result;
    }
    // if disc == 0 ... dealt with later
    double tmpSqrt = sqrt(disc);
    double abScalingFactor1 = -pBy2 + tmpSqrt;
    double abScalingFactor2 = -pBy2 - tmpSqrt;

    Point2D * p1 = new Point2D(pointOne->getX() - baX * abScalingFactor1,
            pointOne->getY() - baY * abScalingFactor1);
    if (disc == 0) { // abScalingFactor1 == abScalingFactor2
        result.push_back(p1);
        return result;
    }

    Point2D * p2 = new Point2D(pointOne->getX() - baX * abScalingFactor2,
            pointOne->getY() - baY * abScalingFactor2);
    result.push_back(p1);
    result.push_back(p2);

    return result;
}

double GeometryAlgorithms::distanceBetweenPoints(Point2D* pointOne,
                                                 Point2D* pointTwo) {
    return sqrt(
        pow((pointTwo->getX() - pointOne->getX()), 2) +
        pow((pointTwo->getY() - pointOne->getY()), 2)
    );
}

double GeometryAlgorithms::distanceBetweenPoints(Point3D* pointOne, 
                                                 Point3D* pointTwo) {
    return sqrt(
        pow((pointTwo->getX() - pointOne->getX()), 2) +
        pow((pointTwo->getY() - pointOne->getY()), 2) +
        pow((pointTwo->getZ() - pointOne->getZ()), 2)
    );
}

/*
 * Obtenido desde "Monte Carlo Modeling of Light Transport in 
 * Multi-Layered Tissues in Standard C" Capitulo 3, página 18
 * ecuación (3.26)
 *
 * Se ha cambiado la función implementada anteriormente,
 * el algoritmo ahora recibe los indices refractivos y el angulo
 * de incidencia
 */
double GeometryAlgorithms::Fresnel(double n1, double n2, double ai){
    // cout << "GeometryAlgorithms.cc: Dentro de fresnel" << endl;
    // cout << "GeometryAlgorithms.cc: Coef refractivo 1: " << n1 << endl;
    // cout << "GeometryAlgorithms.cc: Coef refractivo 2: " << n2 << endl;
    // cout << "GeometryAlgorithms.cc: Angulo de incidencia: " << ai << endl;

    double sin_at = n1 * sin(ai) / n2;

    // cout << "GeometryAlgorithms.cc: seno de ai: " << sin(ai) << endl;
    // cout << "GeometryAlgorithms.cc: seno de at: " << sin_at << endl;

    /*
     * No estoy seguro de esta solucion parche, es necesario analizar
     * la teoria fisica: 
     * http://en.wikipedia.org/wiki/Snell%27s_law#Total_internal_reflection_and_critical_angle
     */
    if (sin_at > 1) 
        sin_at = 1;
    else if (sin_at < -1) 
        sin_at = -1;

    double at = asin(sin_at);
    // cout << "GeometryAlgorithms.cc: at: " << at << endl;

    double rai = 0.5 * (
              (sin(ai - at) * sin(ai - at)) / (sin(ai + at) * sin(ai + at)) + 
              
              (tan(ai - at) * tan(ai - at)) / (tan(ai + at) * tan(ai + at))
        );

    return rai;
};