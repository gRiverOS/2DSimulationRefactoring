#ifndef CIRCUMFERENCE_HH
#define CIRCUMFERENCE_HH

#include <iostream>
#include <string>
#include "../../common/Point2D.hh"
#include "../../common/Point.hh"
#include "../../utils/GeometryAlgorithms.hh"
#include "../../utils/Random.hh"
#include "../Geometry.hh"
#include <math.h>
#include <float.h>
#include <stddef.h>

using namespace std;

class Circumference: public Geometry {
private:
    string name;
    Point2D * center;
    double radius;
public:
    Circumference();
    Circumference(string n_Name);
    Circumference(string n_Name, Point2D * n_Center, double n_Radio);
    ~Circumference();
    Point2D * getCenter();
    double getRadius();
    void setRadius(double n_Radio);
    void setCenter(Point2D * n_Center);

    virtual bool insideGeometry(Point * n_point) {
        double deltaX = dynamic_cast<Point2D *>(n_point)->getX() - center->getX();
        double deltaY = dynamic_cast<Point2D *>(n_point)->getY() - center->getY();

        double deltaR = sqrt((double) (deltaX * deltaX + deltaY * deltaY));
        if (deltaR <= radius)
            return true;
        else
            return false;
    }
    
    virtual Point * getIntersectionPoint(Point * pointOne, Point * pointTwo){
        GeometryAlgorithms * algorithm = new GeometryAlgorithms();
        vector <Point2D *> intersectionPoints = algorithm->getLineCircumferenceIntersection(
                dynamic_cast<Point2D*>(pointOne),
                dynamic_cast<Point2D*>(pointTwo),
                dynamic_cast<Point2D*>(center),
                radius);

        if(intersectionPoints.size() == 0)
            return NULL;
        else if(intersectionPoints.size() == 1){
            Point2D * intersection = new Point2D(intersectionPoints[0]);
            delete intersectionPoints[0];
            return intersection;
        }
        else{
            if(algorithm->distanceBetweenPoints(dynamic_cast<Point2D*>(pointOne),intersectionPoints[0]) >
                algorithm->distanceBetweenPoints(dynamic_cast<Point2D*>(pointOne),intersectionPoints[1])){
                delete algorithm;
                Point2D * intersection = new Point2D(intersectionPoints[1]);
                delete intersectionPoints[0];
                delete intersectionPoints[1];
                return intersection;
            }
            else{
                delete algorithm;
                Point2D * intersection = new Point2D(intersectionPoints[0]);
                delete intersectionPoints[0];
                delete intersectionPoints[1];
                return intersection;
            }
        }
    }

    virtual Point * getRandomPoint(){
        Random * random = new Random();
        double rand = random->RandomNumBetweenZeroOne() ;
        double radiusrand = random->RandomNumBetweenZeroOne();
        double x = center->getX() + radius * radiusrand * cos (rand * 2 * 3.141592);
        double y = center->getY() + radius * radiusrand * sin (rand* 2 * 3.141592);
        delete random;
        return new Point2D(x,y);
    }

    virtual Point * getRandomDirection() {
        Random * random = new Random();
        double r = 2 * 3.141592653589793238462 * random->RandomNumBetweenZeroOne();
        double y = sin(r);
        double x = cos(r);
        delete random;

        return new Point2D(x, y);
    }
    
    virtual Point * getRandomDirection(Point * direction, double angularAperture) {
        cerr << "Error: La clase Circumference no aun no puede ser usada para fuentes direccionadas" << endl;
        exit(-1);
        return NULL;
    }

    virtual Point * getReflection(Point * pointone, Point * pointtwo, Point * direction){
        if(this->insideGeometry(pointone)){
            Point2D * normal = new Point2D(dynamic_cast<Point2D *>(pointtwo)->getX() - center->getX() ,
                                           dynamic_cast<Point2D *>(pointtwo)->getY() - center->getY());
            double lenght = sqrt(normal->getX() * normal->getX() + normal->getY() * normal->getY());
            if(lenght == 0){
                cerr << "Error no se pudo calcular la reflexion de la circunferencia" << endl;
                exit(-1);
            }
            normal->setX((normal->getX() / lenght) * -1);
            normal->setY((normal->getY() / lenght) * -1);
            double escalar = 2 * (dynamic_cast<Point2D *>(direction)->getX() * normal->getX() + dynamic_cast<Point2D *>(direction)->getY() * normal->getY());
            normal->setX(normal->getX() * escalar);
            normal->setY(normal->getY() * escalar);
            Point2D * r = new Point2D(dynamic_cast<Point2D *>(direction)->getX() - normal->getX(), dynamic_cast<Point2D *>(direction)->getY() - normal->getY());
            delete normal;
            return r;

        } else{
            Point2D * normal = new Point2D(dynamic_cast<Point2D *>(pointtwo)->getX() - center->getX() ,
                                           dynamic_cast<Point2D *>(pointtwo)->getY() - center->getY());
            double lenght = sqrt(normal->getX() * normal->getX() + normal->getY() * normal->getY());
            if(lenght == 0){
                cerr << "Error no se pudo calcular la reflexion de la circunferencia" << endl;
                exit(-1);
            }
            normal->setX(normal->getX() / lenght);
            normal->setY(normal->getY() / lenght);
            double escalar = 2 * (dynamic_cast<Point2D *>(direction)->getX() * normal->getX() + dynamic_cast<Point2D *>(direction)->getY() * normal->getY());
            normal->setX(normal->getX() * escalar);
            normal->setY(normal->getY() * escalar);
            Point2D * r = new Point2D(dynamic_cast<Point2D *>(direction)->getX() - normal->getX(), dynamic_cast<Point2D *>(direction)->getY() - normal->getY());
            delete normal;
            return r;
        }
    }

    /*
     * El calculo del angulo de incidencia ha sido obtenido desde el siguiente enlace:
     * http://www.vitutor.com/analitica/distancias/angulos.html
     */
    virtual double getIncidenceAngle(Point * point, Point * direction) {
        
        /*
         * Para calcular el ángulo de incidencia se determina la recta 
         * tangente a la circunferencia que pasa por 'point'. Dicha recta
         * es perpendicular a la que va desde el centro hasta 'point'
         */

        double px = dynamic_cast<Point2D *>(point)->getX();
        double py = dynamic_cast<Point2D *>(point)->getY();

        // Dirección de la recta que va desde center hasta point (vector n)
        double nx = (px - center->getX()) / radius;
        double ny = (py - center->getY()) / radius;

        // Vector unitario perpendicular al vector n (dirección de la recta tangente rt)
        // Dos rectas son perpendiculares si su producto punto es 0
        // por lo tanto nx * rtx + ny*rty = 0

        double rtx;
        double rty;

        if (fabs(nx) < DBL_EPSILON) {
            rtx = 1;
            rty = 0;
        }
        else if (fabs(ny) < DBL_EPSILON) {
            rtx = 0;
            rty = 1;
        }
        else {

            // Dirección de rt no normalizada
            rtx = 1;
            rty = nx * rtx / ny;

            // Dirección de rt normalizada
            double modulo_rt = sqrt(rtx*rtx + rty*rty);
            rtx = rtx / modulo_rt;
            rty = rty / modulo_rt;
        }
        
        // Direccion de la recta por donde avanza la particula
        double ux = dynamic_cast<Point2D *>(direction)->getX();
        double uy = dynamic_cast<Point2D *>(direction)->getY();

        /* 
         * si rtx*ux + rty*uy == 0 --> vectores perpendiculares y en este caso el angulo
         * de incidencia debe ser cero, acos(0) = pi/2.
         */
        double pi_medio = 3.141592653589793238462 / 2.0;
        return pi_medio - acos(fabs(rtx*ux + rty*uy) / (sqrt(rtx*rtx + rty*rty) + sqrt(ux*ux + uy*uy)));
    }
};

#endif
