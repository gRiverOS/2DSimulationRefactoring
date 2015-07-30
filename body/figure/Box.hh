#ifndef BOX_HH
#define BOX_HH

#include <iostream>
#include <string>
#include <math.h>
#include <float.h>
#include "../../common/Point3D.hh"
#include "../../common/Point.hh"
#include "../../utils/GeometryAlgorithms.hh"
#include "../Geometry.hh"
#include "../../utils/Random.hh"
#include <cmath>

#include <stdio.h>

using namespace std;

class Box: public Geometry {
private:
    string name;
    Point3D * vertex;
    double height;
    double width;
    double depth;
public:
    Box();
    Box(string n_Name);
    Box(string n_Name, Point3D * n_Vertex, double n_Width, double n_Height, double n_Depth);
    ~Box();
    double getWidth();
    double getHeight();
    double getDepth();
    Point3D * getVertex();

    void setWidth(double n_Width);
    void setHeight(double n_Height);
    void setDepth(double n_Depth);
    void setVertex(Point3D * n_Vertex);

    virtual bool insideGeometry(Point * n_point) {
    	double x = dynamic_cast<Point3D *>(n_point)->getX();
        double y = dynamic_cast<Point3D *>(n_point)->getY();
        double z = dynamic_cast<Point3D *>(n_point)->getZ();

        double left =   this->getVertex()->getX();
        double right =  this->getVertex()->getX() + this->getWidth();
        
        double top =    this->getVertex()->getY() + this->getHeight();
        double bottom = this->getVertex()->getY();

        double front =  this->getVertex()->getZ() + this->getDepth();
        double back =   this->getVertex()->getZ();


        if ((x > left || fabs(x - left) < DBL_EPSILON) && 
            (x < right || fabs(x - right) < DBL_EPSILON) && 
            (y > bottom || fabs(y - bottom) < DBL_EPSILON) && 
            (y < top || fabs(y - top) < DBL_EPSILON) &&
            (z > back || fabs(z - back) < DBL_EPSILON) && 
            (z < front || fabs(z - front) < DBL_EPSILON)) {
            
            return true;
        }
        else{
            return false;
        }
    }

    virtual Point * getIntersectionPoint(Point * pointOne, Point * pointTwo) {

    	// Objeto utilizado para calcular distancias
    	GeometryAlgorithms * algorithm = new GeometryAlgorithms();
    	
    	// Atajo para pointOne y pointTwo
        double x1 = dynamic_cast<Point3D *>(pointOne)->getX();    
        double y1 = dynamic_cast<Point3D *>(pointOne)->getY();    
        double z1 = dynamic_cast<Point3D *>(pointOne)->getZ();
        double x2 = dynamic_cast<Point3D *>(pointTwo)->getX();
        double y2 = dynamic_cast<Point3D *>(pointTwo)->getY();
        double z2 = dynamic_cast<Point3D *>(pointTwo)->getZ();

        // Utilizados para definir puntos de interseccion
        double x3;
        double y3;
        double z3;

        // Distancia desde P1 a un punto de interseccion
        double modulo_p1p3;

        // Estos valores (dos puntos) definen el espacio entre pointOne y pointTwo
        // P3 (interseccion) debe encontrarse en este espacio
        double min_x = min(x1, x2);
        double min_y = min(y1, y2);
        double min_z = min(z1, z2);

        double max_x = max(x1, x2);
        double max_y = max(y1, y2);
        double max_z = max(z1, z2);

        // Se define la dirección desde pointOne hacia pointTwo
        double modulo_p1p2 = algorithm->distanceBetweenPoints(dynamic_cast<Point3D *>(pointOne), dynamic_cast<Point3D *>(pointTwo));
        double ux = (x2 - x1) / modulo_p1p2;
        double uy = (y2 - y1) / modulo_p1p2;
        double uz = (z2 - z1) / modulo_p1p2;

        // Planos que definen la caja
        double top_plane = vertex->getY() + height;
        double bottom_plane = vertex->getY();
        double left_plane = vertex->getX();
        double right_plane = vertex->getX() + width;
        double front_plane = vertex->getZ() + depth;
        double back_plane = vertex->getZ();

        // Punto de intersección
        vector<Point3D *> intersections;
        Point3D * intersect;
        
        // Interseccion con el plano superior?
        if ((fabs(y2 - y1) > DBL_EPSILON) &&
            (min_y < top_plane || (min_y - top_plane) < DBL_EPSILON) &&
            (max_y > top_plane || (min_y - top_plane) < DBL_EPSILON)) {

            // x3;
            y3 = top_plane;
            // z3;

            modulo_p1p3 = fabs((y3 - y1) / uy);
            x3 = x1 + ux * modulo_p1p3;
            z3 = z1 + uz * modulo_p1p3;

            intersect = new Point3D(x3, y3, z3);
            
            if (this->insideGeometry(intersect))
                intersections.push_back(intersect);
        }

        // Interseccion con el plano inferior?
        if ((fabs(y2 - y1) > DBL_EPSILON) &&
            (min_y < bottom_plane || (min_y - bottom_plane) < DBL_EPSILON) &&
            (max_y > bottom_plane || (min_y - bottom_plane) < DBL_EPSILON)) {
            
            // x3;
            y3 = bottom_plane;
            // z3;
            
            modulo_p1p3 = fabs((y3 - y1) / uy);
            x3 = x1 + ux * modulo_p1p3;
            z3 = z1 + uz * modulo_p1p3;

            intersect = new Point3D(x3, y3, z3);
            
            if (this->insideGeometry(intersect))
                intersections.push_back(intersect);
        }

        // Interseccion con el plano izquierdo?
        if ((fabs(x2 - x1) > DBL_EPSILON) &&
            (min_x < left_plane || (min_x - left_plane) < DBL_EPSILON) &&
            (max_x > left_plane || (min_x - left_plane) < DBL_EPSILON)) {

            x3 = left_plane;
            // y3;
            // z3;

            modulo_p1p3 = fabs((x3 - x1) / ux);
            y3 = y1 + uy * modulo_p1p3;
            z3 = z1 + uz * modulo_p1p3;

            intersect = new Point3D(x3, y3, z3);
            
            if (this->insideGeometry(intersect))
                intersections.push_back(intersect);
        }

        // Interseccion con el plano derecho?
        if ((fabs(x2 - x1) > DBL_EPSILON) &&
            (min_x < right_plane || (min_x - right_plane) < DBL_EPSILON) &&
            (max_x > right_plane || (min_x - right_plane) < DBL_EPSILON)) {

            x3 = right_plane;
            // y3;
            // z3;

            modulo_p1p3 = fabs((x3 - x1) / ux);
            y3 = y1 + uy * modulo_p1p3;
            z3 = z1 + uz * modulo_p1p3;

            intersect = new Point3D(x3, y3, z3);
            
            if (this->insideGeometry(intersect))
                intersections.push_back(intersect);
        }

        // Interseccion con el plano frontal?
        if ((fabs(z2 - z1) > DBL_EPSILON) &&
            (min_z < front_plane || (min_z - front_plane) < DBL_EPSILON) &&
            (max_z > front_plane || (min_z - front_plane) < DBL_EPSILON)) {

            // x3;
            // y3;
            z3 = front_plane;

            modulo_p1p3 = fabs((z3 - z1) / uz);
            x3 = x1 + ux * modulo_p1p3;
            y3 = y1 + uy * modulo_p1p3;

            intersect = new Point3D(x3, y3, z3);
            
            if (this->insideGeometry(intersect))
                intersections.push_back(intersect);
        }

        // Interseccion con el plano posterior?
        if ((fabs(z2 - z1) > DBL_EPSILON) &&
            (min_z < back_plane || (min_z - back_plane) < DBL_EPSILON) &&
            (max_z > back_plane || (min_z - back_plane) < DBL_EPSILON)) {

            // x3;
            // y3;
            z3 = back_plane;

            modulo_p1p3 = fabs((z3 - z1) / uz);
            x3 = x1 + ux * modulo_p1p3;
            y3 = y1 + uy * modulo_p1p3;

            intersect = new Point3D(x3, y3, z3);
            
            if (this->insideGeometry(intersect))
                intersections.push_back(intersect);
        }

        if (intersections.size() == 0) {
            return new Point3D(dynamic_cast<Point3D *>(pointTwo));
        }

        // Sea p el primer punto de pi mas cercano a pointOne y distinto de pointOne (distancia>0)
        double mejor_distancia = -1;
        double distancia;
        for (unsigned int i = 0; i < intersections.size(); i++) {
            distancia = algorithm->distanceBetweenPoints(dynamic_cast<Point3D *>(pointOne), dynamic_cast<Point3D *>(intersections[i]));
            if (distancia > 0) {
                if (mejor_distancia == -1) {
                    mejor_distancia = distancia;
                    intersect = intersections[i];
                }
                else if (distancia < mejor_distancia) {
                    mejor_distancia = distancia;
                    intersect = intersections[i];
                }

            }
        }

        // Si mejor distancia sigue siendo -1, todos los puntos de interseccinon 
        // son iguales a pointOne en dicho caso se retorna pointOne
        if (mejor_distancia == -1) {
        	
        	delete algorithm;
            for(unsigned int i = 0; i < intersections.size(); i++)
                delete intersections[i];

            // cout << "P1: Linea definida por: " << endl;
            // cout << "(" << x1 << ", " << y1 << "," << z1 << ")" << endl;
            // cout << "(" << x2 << ", " << y2 << "," << z2 << ")" << endl;
            // cout << "Dirección: (" << ux << ", " << uy << "," << uz << ")" << endl;
            // cout << "Punto de intersección encontrado en: " << endl;
            // cout << "(" << dynamic_cast<Point3D *>(pointOne)->toString() << ")" << endl;
            return new Point3D(dynamic_cast<Point3D *>(pointOne));
        }

        Point3D * intersection_point = new Point3D(intersect);
        delete algorithm;
        for(unsigned int i = 0; i < intersections.size(); i++)
            delete intersections[i];
        
        // cout << "Inter:Linea definida por: " << endl;
        // cout << "(" << x1 << ", " << y1 << "," << z1 << ")" << endl;
        // cout << "(" << x2 << ", " << y2 << "," << z2 << ")" << endl;
        // cout << "Dirección: (" << ux << ", " << uy << "," << uz << ")" << endl;
        // cout << "Punto de intersección encontrado en: " << endl;
        // cout << "(" << dynamic_cast<Point3D *>(intersection_point)->toString() << ")" << endl;

        return intersection_point;
    }

    virtual Point * getRandomPoint() {
    	Random * random = new Random();
        double x = vertex->getX() + (random->RandomNumBetweenZeroOne() * width);
        double y = vertex->getY() + (random->RandomNumBetweenZeroOne() * height);
        double z = vertex->getZ() + (random->RandomNumBetweenZeroOne() * depth);
        delete random;
        return new Point3D(x, y, z);
    }

    virtual Point * getRandomDirection() {
        Random * random = new Random();
        double x = vertex->getX() + (random->RandomNumBetweenZeroOne() * width);
        double y = vertex->getY() + (random->RandomNumBetweenZeroOne() * height);
        double z = vertex->getZ() + (random->RandomNumBetweenZeroOne() * depth);
        delete random;

        double modulo = sqrt(x*x + y*y + z*z);


        return new Point3D(x/modulo, y/modulo, z/modulo);
    }

    virtual Point * getRandomDirection(Point * direction, double angularAperture) {
        // cout << direction->toString() << endl;
        // cout << angularAperture << endl;
        
        double ux = dynamic_cast<Point3D *>(direction)->getX();
        
        double uy = dynamic_cast<Point3D *>(direction)->getY();
        double uz = dynamic_cast<Point3D *>(direction)->getZ();
        
        double new_ux;
        double new_uy;
        double new_uz;
        double sign;

        Random * random = new Random();
        
        /*
         * Se genera un ángulo de defleccion aleatorio que va entre
         * [-angularAperture, angularAperture]
         */
        double theta = random->RandomNumBetweenZeroOne() * angularAperture;
        if(random->RandomNumBetweenZeroOne() >= 0.5)
            theta = -theta;

        // cout << "Angulo theta obtenido..." << endl;
        /*
         * se muestrea el angulo azimutal
         */
        double psi = 2 * 3.141592653589793238462 * random->RandomNumBetweenZeroOne();

        /*
         * Se analiza uz para evitar division por cero
         */
        if (fabs(uz) > 0.99999) {
            if (uz < 0) sign = -1;
            else sign = 1;

            new_ux = sin(theta) * cos(psi);
            new_uy = sin(theta) * sin(psi);
            new_uz = sign * cos(theta);
        } 
        else {
            new_ux = (sin(theta) / sqrt(1 - uz*uz)) * (ux*uz*cos(psi) - uy*sin(psi)) + ux*cos(theta);
            new_uy = (sin(theta) / sqrt(1 - uz*uz)) * (uy*uz*cos(psi) + ux*sin(psi)) + uy*cos(theta);
            new_uz = -sin(theta) * cos(psi) * sqrt(1 - uz*uz) + uz*cos(theta);
        }

        delete random;
        // cout << "Nueva direccion obtenida..." << endl;
        return new Point3D(new_ux, new_uy, new_uz);
    }

    virtual Point * getReflection(Point * pointOne, Point * pointTwo, Point * direction){ 
    	if(dynamic_cast<Point3D *>(pointTwo)->getX() == this->vertex->getX()){
            return new Point3D(
            	dynamic_cast<Point3D *>(direction)->getX() * -1, 
            	dynamic_cast<Point3D *>(direction)->getY(),
            	dynamic_cast<Point3D *>(direction)->getZ()
            );
        }
        else if(dynamic_cast<Point3D *>(pointTwo)->getX() == (this->vertex->getX() + width)){
            return new Point3D(
            	dynamic_cast<Point3D *>(direction)->getX() * -1, 
            	dynamic_cast<Point3D *>(direction)->getY(),
            	dynamic_cast<Point3D *>(direction)->getZ()
            );
        }
        else if(dynamic_cast<Point3D *>(pointTwo)->getY() == (this->vertex->getY())){
            return new Point3D(
            	dynamic_cast<Point3D *>(direction)->getX(), 
            	dynamic_cast<Point3D *>(direction)->getY() * -1,
            	dynamic_cast<Point3D *>(direction)->getZ()
            );
        }
        else if(dynamic_cast<Point3D *>(pointTwo)->getY() == (this->vertex->getY() + height)){
            return new Point3D(
            	dynamic_cast<Point3D *>(direction)->getX(),  
            	dynamic_cast<Point3D *>(direction)->getY() * -1,
            	dynamic_cast<Point3D *>(direction)->getZ()
            );
        }

        else if(dynamic_cast<Point3D *>(pointTwo)->getZ() == (this->vertex->getZ())){
            return new Point3D(
            	dynamic_cast<Point3D *>(direction)->getX(),
            	dynamic_cast<Point3D *>(direction)->getY(),  
            	dynamic_cast<Point3D *>(direction)->getZ() * -1
            );
        }

        else if(dynamic_cast<Point3D *>(pointTwo)->getZ() == (this->vertex->getZ() + depth)){
            return new Point3D(
            	dynamic_cast<Point3D *>(direction)->getX(), 
            	dynamic_cast<Point3D *>(direction)->getY(),  
            	dynamic_cast<Point3D *>(direction)->getZ() * -1
            );
        }

        else{
            
            /*
             * Si no se encontró reflexión, el eje de reflexión es el más cercano a P2
             */

            double x;
            double y;
            double z;

            if(abs(dynamic_cast<Point3D *>(pointTwo)->getX() - this->vertex->getX()) < abs(dynamic_cast<Point3D *>(pointTwo)->getX() - this->vertex->getX() + width))
                x = abs(dynamic_cast<Point3D *>(pointTwo)->getX() - this->vertex->getX());
            else
                x = abs(dynamic_cast<Point3D *>(pointTwo)->getX() - this->vertex->getX() + width);

            if(abs(dynamic_cast<Point3D *>(pointTwo)->getY() - this->vertex->getY()) < abs(dynamic_cast<Point3D *>(pointTwo)->getY() - this->vertex->getY() + height))
                y = abs(dynamic_cast<Point3D *>(pointTwo)->getY() - this->vertex->getY());
            else
                y = abs(dynamic_cast<Point3D *>(pointTwo)->getY() - this->vertex->getY() + height);

            if(abs(dynamic_cast<Point3D *>(pointTwo)->getZ() - this->vertex->getZ()) < abs(dynamic_cast<Point3D *>(pointTwo)->getZ() - this->vertex->getZ() + depth))
                z = abs(dynamic_cast<Point3D *>(pointTwo)->getZ() - this->vertex->getZ());
            else
                z = abs(dynamic_cast<Point3D *>(pointTwo)->getZ() - this->vertex->getZ() + depth);

            if(x < y && x < z)
                return new Point3D(dynamic_cast<Point3D *>(direction)->getX() * -1, dynamic_cast<Point3D *>(direction)->getY(), dynamic_cast<Point3D *>(direction)->getZ());
            else if(y < x && y < z)
                return new Point3D(dynamic_cast<Point3D *>(direction)->getX(), dynamic_cast<Point3D *>(direction)->getY() * -1, dynamic_cast<Point3D *>(direction)->getZ());
            else
                return new Point3D(dynamic_cast<Point3D *>(direction)->getX(), dynamic_cast<Point3D *>(direction)->getY(), dynamic_cast<Point3D *>(direction)->getZ() * -1);

        }
    }

    /*
     * El calculo del angulo de incidencia entre una recta y un plano ha
     * sido obtenido desde el siguiente enlace:
     * http://www.vitutor.com/analitica/distancias/angulos.html
     */
    virtual double getIncidenceAngle(Point * point, Point * direction){
        
        // Vector unitario perpendicular al plano
        double nx;
        double ny;
        double nz;

        // Vector unitario de la recta
        double ux = dynamic_cast<Point3D *>(direction)->getX();
        double uy = dynamic_cast<Point3D *>(direction)->getY();
        double uz = dynamic_cast<Point3D *>(direction)->getZ();

        if (dynamic_cast<Point3D *>(point)->getX() == this->vertex->getX()){
            nx = 1;
            ny = 0;
            nz = 0;
        }
        else if (dynamic_cast<Point3D *>(point)->getX() == (this->vertex->getX() + width)){
            nx = 1;
            ny = 0;
            nz = 0;
        }
        else if (dynamic_cast<Point3D *>(point)->getY() == (this->vertex->getY())){
            nx = 0;
            ny = 1;
            nz = 0;
        }
        else if (dynamic_cast<Point3D *>(point)->getY() == (this->vertex->getY() + height)){
            nx = 0;
            ny = 1;
            nz = 0;
        }

        else if (dynamic_cast<Point3D *>(point)->getZ() == (this->vertex->getZ())){
            nx = 0;
            ny = 0;
            nz = 1;
        }

        else if (dynamic_cast<Point3D *>(point)->getZ() == (this->vertex->getZ() + depth)){
            nx = 0;
            ny = 0;
            nz = 1;
        }

        else{
            
            /*
             * Si no se encontró reflexión, el eje de reflexión es el más cercano a P2
             */

            double x;
            double y;
            double z;

            if(abs(dynamic_cast<Point3D *>(point)->getX() - this->vertex->getX()) < abs(dynamic_cast<Point3D *>(point)->getX() - this->vertex->getX() + width))
                x = abs(dynamic_cast<Point3D *>(point)->getX() - this->vertex->getX());
            else
                x = abs(dynamic_cast<Point3D *>(point)->getX() - this->vertex->getX() + width);

            if(abs(dynamic_cast<Point3D *>(point)->getY() - this->vertex->getY()) < abs(dynamic_cast<Point3D *>(point)->getY() - this->vertex->getY() + height))
                y = abs(dynamic_cast<Point3D *>(point)->getY() - this->vertex->getY());
            else
                y = abs(dynamic_cast<Point3D *>(point)->getY() - this->vertex->getY() + height);

            if(abs(dynamic_cast<Point3D *>(point)->getZ() - this->vertex->getZ()) < abs(dynamic_cast<Point3D *>(point)->getZ() - this->vertex->getZ() + depth))
                z = abs(dynamic_cast<Point3D *>(point)->getZ() - this->vertex->getZ());
            else
                z = abs(dynamic_cast<Point3D *>(point)->getZ() - this->vertex->getZ() + depth);

            if(x < y && x < z) {
                nx = 1;
                ny = 0;
                nz = 0;
            }
            else if(y < x && y < z) {
                nx = 0;
                ny = 1;
                nz = 0;
            }
            else {
                nx = 0;
                ny = 0;
                nz = 1;
            }
        }
        
        double pi_medio = 3.141592653589793238462 / 2.0;
        double alfa = asin(fabs(nx*ux + ny*uy + nz*uz) / (sqrt(nx*nx + ny*ny + nz*nz) + sqrt(ux*ux + uy*uy + uz*uz)));
        return pi_medio - alfa;
    }
};

#endif
