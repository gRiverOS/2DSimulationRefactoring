#ifndef RECTANGLE_HH
#define RECTANGLE_HH

#include <iostream>
#include <string>
#include <math.h>
#include <float.h>
#include "../../common/Point2D.hh"
#include "../../common/Point.hh"
#include "../../utils/GeometryAlgorithms.hh"
#include "../Geometry.hh"
#include "../../utils/Random.hh"
#include <cmath>

#include <stdio.h>

using namespace std;

class Rectangle: public Geometry {
private:
    string name;
    Point2D * vertex;
    double height;
    double width;
public:
    Rectangle();
    Rectangle(string n_Name);
    Rectangle(string n_Name, Point2D * n_Vertex, double n_Height,
            double n_Width);
    ~Rectangle();
    double getHeight();
    double getWidth();
    Point2D * getVertex();
    void setHeight(double n_Height);
    void setWidth(double n_Width);
    void setVertex(Point2D * n_Vertex);

    virtual bool insideGeometry(Point * n_point) {
        // if (dynamic_cast<Point2D *>(n_point)->getX() >= this->getVertex()->getX() && dynamic_cast<Point2D *>(n_point)->getX() <= (this->getVertex()->getX() + this->getWidth())
        //         && dynamic_cast<Point2D *>(n_point)->getY() >= this->getVertex()->getY() && dynamic_cast<Point2D *>(n_point)->getY() <= (this->getVertex()->getY() + this->getHeight())){
        //     return true;
        // }
        // else{
        //     return false;
        // }

        double x = dynamic_cast<Point2D *>(n_point)->getX();
        double y = dynamic_cast<Point2D *>(n_point)->getY();
        double left = this->getVertex()->getX();
        double right = this->getVertex()->getX() + this->getWidth();
        double top = this->getVertex()->getY() + this->getHeight();
        double bottom = this->getVertex()->getY();

        if ((x > left || fabs(x - left) < DBL_EPSILON) && 
            (x < right || fabs(x - right) < DBL_EPSILON) && 
            (y > bottom || fabs(y - bottom) < DBL_EPSILON) && 
            (y < top || fabs(y - top) < DBL_EPSILON)) {
            
            return true;
        }
        else{
            return false;
        }

    }

    virtual void debugInsideGeometry(Point * n_point) {

        int inside = 0;
        inside = inside + (dynamic_cast<Point2D *>(n_point)->getX() < this->getVertex()->getX());
        if (inside) cout << "Primera" << endl;
        inside = inside + (dynamic_cast<Point2D *>(n_point)->getX() > (this->getVertex()->getX() + this->getWidth()));
        if (inside) cout << "Segunda" << endl;
        inside = inside + (dynamic_cast<Point2D *>(n_point)->getY() < this->getVertex()->getY());
        if (inside) cout << "Tercera" << endl;
        inside = inside + (dynamic_cast<Point2D *>(n_point)->getY() > (this->getVertex()->getY() + this->getHeight()));
        if (inside) cout << "Cuarta" << endl;

        cout << "Comp: " << dynamic_cast<Point2D *>(n_point)->getX() << "<" << this->getVertex()->getX() << " -> " << (dynamic_cast<Point2D *>(n_point)->getX() < this->getVertex()->getX()) << endl;
        cout << "Comp: " << dynamic_cast<Point2D *>(n_point)->getX() << ">" << (this->getVertex()->getX() + this->getWidth()) << " -> " << (dynamic_cast<Point2D *>(n_point)->getX() > (this->getVertex()->getX() + this->getWidth())) << endl;
        cout << "Comp: " << dynamic_cast<Point2D *>(n_point)->getY() << "<" << this->getVertex()->getY() << " -> " << (dynamic_cast<Point2D *>(n_point)->getY() < this->getVertex()->getY()) << endl;
        cout << "Comp: " << dynamic_cast<Point2D *>(n_point)->getY() << ">" << (this->getVertex()->getY() + this->getHeight()) << " -> " << (dynamic_cast<Point2D *>(n_point)->getY() > (this->getVertex()->getY() + this->getHeight())) << endl;
        
        cout << "Comp compuesta: " << (((dynamic_cast<Point2D *>(n_point))->getX() < this->getVertex()->getX()) || ((dynamic_cast<Point2D *>(n_point))->getX() > (this->getVertex()->getX() + this->getWidth())) || ((dynamic_cast<Point2D *>(n_point))->getY() < this->getVertex()->getY()) || ((dynamic_cast<Point2D *>(n_point))->getY() > (this->getVertex()->getY() + this->getHeight()))) << endl;
        cout << "Comp compuesta num: " << inside << endl;
    }

    /*
     * Algoritmo
     * 
     * Determinar los vertices A,B,C,D del rectangulo
     * Obtener todos los puntos de interseccion pi[]
     * Eliminar todos los puntos pi que estan fuera de la geometria
     * Eliminar todos los puntos pi fuera del espacio de pointOne y pointTwo
     * Si size(pi) == 0 -> retornar NULL (no deberia pasar)
     * Si size(pi) == 1 -> retornar pi[0]
     * Si size(pi)== 2 and Si pi[0] == pi[1]:
     *      -> retornar pi[0]
     * Sino:
     *     Sea p el primer punto de pi mas cercano a pointOne y distinto de pointOne
     *     retornar p
     */
    virtual Point * getIntersectionPoint(Point * pointOne, Point * pointTwo) {
        
        GeometryAlgorithms * algorithm = new GeometryAlgorithms();

        // Se  determinan los vertices A,B,C,D del rectangulo
        Point2D * vertexTop = new Point2D(vertex->getX(),
                vertex->getY() + height);

        Point2D * vertexRight = new Point2D(vertex->getX() + width,
                vertex->getY());

        Point2D * vertexTopRight = new Point2D(vertex->getX() + width,
                vertex->getY() + height);

        vector<Point2D *> pi_apriori;
        vector<Point2D *> pi;

        Point2D * intersection_point;

        // Obtener todos los puntos de interseccion pi_apriori[]
        intersection_point = algorithm->getLineLineIntersection(
                dynamic_cast<Point2D *>(pointOne),
                dynamic_cast<Point2D *>(pointTwo), vertex, vertexTop);
        if (intersection_point != NULL)
            pi_apriori.push_back(intersection_point);

        intersection_point = algorithm->getLineLineIntersection(
                dynamic_cast<Point2D *>(pointOne),
                dynamic_cast<Point2D *>(pointTwo), vertex, vertexRight);
        if (intersection_point != NULL)
            pi_apriori.push_back(intersection_point);

        intersection_point = algorithm->getLineLineIntersection(
                dynamic_cast<Point2D *>(pointOne),
                dynamic_cast<Point2D *>(pointTwo), vertexTop, vertexTopRight);
        if (intersection_point != NULL)
            pi_apriori.push_back(intersection_point);

        intersection_point = algorithm->getLineLineIntersection(
                dynamic_cast<Point2D *>(pointOne),
                dynamic_cast<Point2D *>(pointTwo), vertexRight, vertexTopRight);
        if (intersection_point != NULL)
            pi_apriori.push_back(intersection_point);

        // Para cada punto pi_apriori
        for (unsigned int i = 0; i < pi_apriori.size(); i++) { 

            double min_x = min(dynamic_cast<Point2D*>(pointOne)->getX(), dynamic_cast<Point2D*>(pointTwo)->getX());
            double max_x = max(dynamic_cast<Point2D*>(pointOne)->getX(), dynamic_cast<Point2D*>(pointTwo)->getX());
            double min_y = min(dynamic_cast<Point2D*>(pointOne)->getY(), dynamic_cast<Point2D*>(pointTwo)->getY());
            double max_y = max(dynamic_cast<Point2D*>(pointOne)->getY(), dynamic_cast<Point2D*>(pointTwo)->getY());

            // Eliminar todos los puntos fuera de la geometria
            // Eliminar todos los puntos pi fuera del espacio de pointOne y pointTwo
            if (
                this->insideGeometry(pi_apriori[i]) &&
                ((pi_apriori[i]->getX() > min_x) || (fabs(pi_apriori[i]->getX() - min_x) < /*((double)10.0) * */ DBL_EPSILON)) &&
                ((pi_apriori[i]->getX() < max_x) || (fabs(pi_apriori[i]->getX() - max_x) < /*((double)10.0) * */ DBL_EPSILON)) &&
                ((pi_apriori[i]->getY() > min_y) || (fabs(pi_apriori[i]->getY() - min_y) < /*((double)10.0) * */ DBL_EPSILON)) &&
                ((pi_apriori[i]->getY() < max_y) || (fabs(pi_apriori[i]->getY() - max_y) < /*((double)10.0) * */ DBL_EPSILON))
            ) {
                
                pi.push_back(pi_apriori[i]);
            }
        }

        if (pi.size() == 0) {

            /*
            // DEBUG
            // cout << "Error: no hay punto de interseccion con la recta (";
            // cout << dynamic_cast<Point2D*>(pointOne)->getX() << ", ";
            // cout << dynamic_cast<Point2D*>(pointOne)->getY() << ") - (";
            // cout << dynamic_cast<Point2D*>(pointTwo)->getX() << ", ";
            // cout << dynamic_cast<Point2D*>(pointTwo)->getY() << ") ";
            printf("Error: no hay punto de interseccion con la\nrecta (%.35f, %.35f)  -  (%.35f, %.15f)\n", dynamic_cast<Point2D*>(pointOne)->getX(), dynamic_cast<Point2D*>(pointOne)->getY(), dynamic_cast<Point2D*>(pointTwo)->getX(), dynamic_cast<Point2D*>(pointTwo)->getY());
            printf("Y el rectangulo formado por:\n");
            printf("BottomLeft: (%.15f, %.15f)\n", vertex->getX(), vertex->getY());
            printf("TopLeft: (%.15f, %.15f)\n", vertexTop->getX(), vertexTop->getY());
            printf("TopRight: (%.15f, %.15f)\n", vertexTopRight->getX(), vertexTopRight->getY());
            printf("BottomRight: (%.15f, %.15f)\n", vertexRight->getX(), vertexRight->getY());
            
            // cout << "y el rectangulo definido por: " << endl;
            // cout << "BottomLeft" << ": (" << vertex->getX() << ", " << vertex->getY() << ")" << endl;
            // cout << "TopLeft" << ": (" << vertexTop->getX() << ", " << vertexTop->getY() << ")" << endl;
            // cout << "TopRight" << ": (" << vertexTopRight->getX() << ", " << vertexTopRight->getY() << ")" << endl;
            // cout << "BottomRight" << ": (" << vertexRight->getX() << ", " << vertexRight->getY() << ")" << endl;

            // cout << "Cantidad de puntos de interseccion a priori: " << pi_apriori.size() << endl << endl;
            printf("\nCantidad de puntos de interseccion a priori: %d\n\n", pi_apriori.size());
            for (unsigned int i = 0; i < pi_apriori.size(); i++) { 
                //cout << "Analizando Punto " << i << ": (" << pi_apriori[i]->getX() << ", " << pi_apriori[i]->getY() << ")" << endl;
                printf("Analizando Punto %u: (%.35f, %.35f)\n", i, pi_apriori[i]->getX(), pi_apriori[i]->getY());

                double min_x = min(dynamic_cast<Point2D*>(pointOne)->getX(), dynamic_cast<Point2D*>(pointTwo)->getX());
                double max_x = max(dynamic_cast<Point2D*>(pointOne)->getX(), dynamic_cast<Point2D*>(pointTwo)->getX());
                double min_y = min(dynamic_cast<Point2D*>(pointOne)->getY(), dynamic_cast<Point2D*>(pointTwo)->getY());
                double max_y = max(dynamic_cast<Point2D*>(pointOne)->getY(), dynamic_cast<Point2D*>(pointTwo)->getY());

                // Eliminar todos los puntos fuera de la geometria
                if (this->insideGeometry(pi_apriori[i])) {
                    //cout << "Punto dentro de la geometria" << endl;
                    printf("Punto dentro de la geometria\n");
                }
                else {
                    //cout << "Punto fuera de la geometria, mostrando comparaciones:" << endl;
                    printf("Punto fuera de la geometria, mostrando comparaciones:\n");
                    debugInsideGeometry(pi_apriori[i]);
                }

                // Eliminar todos los puntos pi fuera del espacio de pointOne y pointTwo
                if (
                    ((pi_apriori[i]->getX() > min_x) || (fabs(pi_apriori[i]->getX() - min_x) < ((double)3.0) * DBL_EPSILON)) &&
                    ((pi_apriori[i]->getX() < max_x) || (fabs(pi_apriori[i]->getX() - max_x) < ((double)3.0) * DBL_EPSILON)) &&
                    ((pi_apriori[i]->getY() > min_y) || (fabs(pi_apriori[i]->getY() - min_y) < ((double)3.0) * DBL_EPSILON)) &&
                    ((pi_apriori[i]->getY() < max_y) || (fabs(pi_apriori[i]->getY() - max_y) < ((double)3.0) * DBL_EPSILON))
                ) {
                    
                    // cout << "Punto dentro del espacio de pointOne y pointTwo:" << endl;
                    // cout << "Min x: " << min_x << "  -  Max x: " << max_x << endl;
                    // cout << "Min y: " << min_y << "  -  Max y: " << max_y << endl;
                    printf("Punto dentro del espacio de pointOne y pointTwo::\n");
                    printf("Min x: %.35f    -    Max x: %.35f\n", min_x, max_x);
                    printf("Min y: %.35f    -    Max y: %.35f\n", min_y, max_y);
                }
                else {
                    // cout << "Punto fuera del espacio de pointOne y pointTwo" << endl;
                    // cout << "Min x: " << min_x << "  -  Max x: " << max_x << endl;
                    // cout << "Min y: " << min_y << "  -  Max y: " << max_y << endl;
                    printf("Punto fuera del espacio de pointOne y pointTwo::\n");
                    printf("Min x: %.35f    -    Max x: %.35f\n", min_x, max_x);
                    printf("Min y: %.35f    -    Max y: %.35f\n", min_y, max_y);
                }
                // cout << endl;
                printf("\n");
            }

            // cout << endl;
            printf("\n");
            */

            /*
             * Luego de realizar cientos de pruebas, pueden existir cero 
             * intersecciones en el caso de que el step_size sea demasiado
             * pequeño, por ejemplo 1.1x10E-8, y además la dirección del step
             * sea paralela a una cara vertical del rectangulo.
             *
             * Por ejemplo sea la recta P1 - P2:
             * 0.29999999999999998889776975374843460, 0.38874654780004552767636027965636458)  -  (0.29999997333349803785296217029099353, 0.387364836106619)
             * y el rectangulo formado po:
             * BottomLeft: (0.300000000000000, 0.250000000000000)
             * TopLeft: (0.300000000000000, 0.550000000000000)
             * TopRight: (0.600000000000000, 0.550000000000000)
             * BottomRight: (0.600000000000000, 0.250000000000000)
             *
             * Dado que la direfencia en el eje X es menor DBL_EPSILON, 
             * para el programa las rectas (P1,P2) y (TopLeft, BottomLeft)
             * son paralelas. Luego, los puntos de interseccion a obtener
             * serán los dados por la recta (P1, P2) y las rectas horizontales.
             * Los puntos 0.25 y 0.55 están fuera del rango del eje Y de 
             * P1 y P2, por lo cual no existirá interseccion.
             * 
             * La solucion que se ha dado es asumir que el punto de interseccion
             * es P2.
             */

            delete algorithm;
            delete vertexTop;
            delete vertexRight;
            delete vertexTopRight;

            // cerr << "Error: Siempre debe existir una intersección entre una recta y un rectangulo."<< endl;
            // exit(-1);
            // return NULL;

            Point2D * intersection = new Point2D(dynamic_cast<Point2D*>(pointTwo));
            for(unsigned int i = 0; i < pi_apriori.size(); i++)
                delete pi_apriori[i];

            return intersection;
        }
        else if (pi.size() == 1) {

            delete algorithm;
            delete vertexTop;
            delete vertexRight;
            delete vertexTopRight;
            Point2D * intersection = new Point2D(pi[0]);
            
            for(unsigned int i = 0; i < pi_apriori.size(); i++)
                delete pi_apriori[i];

            return intersection;
        }
        //else if ((pi.size() == 2) && (pi[0] == pi[1])) {
        else if ( 
            pi.size() == 2 && 
            fabs(pi[0]->getX() < pi[1]->getX()) < DBL_EPSILON && 
            fabs(pi[0]->getY() < pi[1]->getY()) < DBL_EPSILON 
        ) {
            delete algorithm;
            delete vertexTop;
            delete vertexRight;
            delete vertexTopRight;
            Point2D * intersection = new Point2D(pi[0]);
    
            for(unsigned int i = 0; i < pi_apriori.size(); i++)
                delete pi_apriori[i];

            return intersection;
        }
        else {
            // Sea p el primer punto de pi mas cercano a pointOne y distinto de pointOne (distancia>0)
            double mejor_distancia = -1;
            Point2D * intersection = NULL;
            for (unsigned int i = 0; i < pi.size(); i++) {
                double distancia = algorithm->distanceBetweenPoints(dynamic_cast<Point2D*>(pointOne), pi[i]);
                if (distancia > 0) {
                    if (mejor_distancia == -1) {
                        mejor_distancia = distancia;
                        intersection = pi[i];
                    }
                    else if (distancia < mejor_distancia) {
                        mejor_distancia = distancia;
                        intersection = pi[i];
                    }

                }
            }

            // retornar p
            Point2D * inter = new Point2D(intersection);
            delete algorithm;
            delete vertexTop;
            delete vertexRight;
            delete vertexTopRight;
            
            for(unsigned int i = 0; i < pi_apriori.size(); i++)
                delete pi_apriori[i];

            return inter;
        }

    }

    virtual Point * getRandomPoint() {
        Random * random = new Random();
        double x = vertex->getX() + (random->RandomNumBetweenZeroOne() * width);
        double y = vertex->getY() + (random->RandomNumBetweenZeroOne() * height);
        delete random;
        return new Point2D(x, y);
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
        cerr << "Error: La clase Rectangle no aun no puede ser usada para fuentes direccionadas" << endl;
        exit(-1);
        return NULL;
    }

    virtual Point * getReflection(Point * pointone, Point * pointtwo, Point * direction){
        /*Intersecto abajo*/
        if(dynamic_cast<Point2D *>(pointtwo)->getX() == this->vertex->getX()){
            return new Point2D(dynamic_cast<Point2D *>(direction)->getX() * -1, dynamic_cast<Point2D *>(direction)->getY());
        }
        else if(dynamic_cast<Point2D *>(pointtwo)->getX() == (this->vertex->getX() + width)){
            return new Point2D(dynamic_cast<Point2D *>(direction)->getX() * -1, dynamic_cast<Point2D *>(direction)->getY());
        }
        else if(dynamic_cast<Point2D *>(pointtwo)->getY() == (this->vertex->getY())){
            return new Point2D(dynamic_cast<Point2D *>(direction)->getX(), dynamic_cast<Point2D *>(direction)->getY() * -1);
        }
        else if(dynamic_cast<Point2D *>(pointtwo)->getY() == (this->vertex->getY() + height)){
            return new Point2D(dynamic_cast<Point2D *>(direction)->getX(),  dynamic_cast<Point2D *>(direction)->getY() * -1);
        }
        else{
            /*Parche de relfexion*/
            //cerr << "No se encontro angulo de reflexion en el rectangulo, punto: (" << dynamic_cast<Point2D *>(pointtwo)->getX() << ","<<dynamic_cast<Point2D *>(pointtwo)->getY()   << ")" << endl;
            //exit(-1);
            double x; double y;
            if(abs(dynamic_cast<Point2D *>(pointtwo)->getX() - this->vertex->getX()) < abs(dynamic_cast<Point2D *>(pointtwo)->getX() - this->vertex->getX() + width))
                x = abs(dynamic_cast<Point2D *>(pointtwo)->getX() - this->vertex->getX());
            else
                x = abs(dynamic_cast<Point2D *>(pointtwo)->getX() - this->vertex->getX() + width);

            if(abs(dynamic_cast<Point2D *>(pointtwo)->getY() - this->vertex->getY()) < abs(dynamic_cast<Point2D *>(pointtwo)->getY() - this->vertex->getY() + width))
                y = abs(dynamic_cast<Point2D *>(pointtwo)->getY() - this->vertex->getY());
            else
                y = abs(dynamic_cast<Point2D *>(pointtwo)->getY() - this->vertex->getY() + height);

            if(x < y)
                return new Point2D(dynamic_cast<Point2D *>(direction)->getX() * -1, dynamic_cast<Point2D *>(direction)->getY());
            else
                return new Point2D(dynamic_cast<Point2D *>(direction)->getX(),  dynamic_cast<Point2D *>(direction)->getY() * -1);

        }
    }

    /*
     * El calculo del angulo de incidencia ha sido obtenido desde el siguiente enlace:
     * http://www.vitutor.com/analitica/distancias/angulos.html
     */
    virtual double getIncidenceAngle(Point * point, Point * direction){
        
        // Vector unitario perpendicular al plano
        double nx;
        double ny;

        // Vector unitario de la recta
        double ux = dynamic_cast<Point2D *>(direction)->getX();
        double uy = dynamic_cast<Point2D *>(direction)->getY();

        if (dynamic_cast<Point2D *>(point)->getX() == this->vertex->getX()){
            nx = 1;
            ny = 0;
        }
        else if (dynamic_cast<Point2D *>(point)->getX() == (this->vertex->getX() + width)){
            nx = 1;
            ny = 0;
        }
        else if (dynamic_cast<Point2D *>(point)->getY() == (this->vertex->getY())){
            nx = 0;
            ny = 1;
        }
        else if (dynamic_cast<Point2D *>(point)->getY() == (this->vertex->getY() + height)){
            nx = 0;
            ny = 1;
        }

        else{
            
            /*
             * Si no se encontró reflexión, el eje de reflexión es el más cercano a P2
             */

            double x;
            double y;

            if(abs(dynamic_cast<Point2D *>(point)->getX() - this->vertex->getX()) < abs(dynamic_cast<Point2D *>(point)->getX() - this->vertex->getX() + width))
                x = abs(dynamic_cast<Point2D *>(point)->getX() - this->vertex->getX());
            else
                x = abs(dynamic_cast<Point2D *>(point)->getX() - this->vertex->getX() + width);

            if(abs(dynamic_cast<Point2D *>(point)->getY() - this->vertex->getY()) < abs(dynamic_cast<Point2D *>(point)->getY() - this->vertex->getY() + height))
                y = abs(dynamic_cast<Point2D *>(point)->getY() - this->vertex->getY());
            else
                y = abs(dynamic_cast<Point2D *>(point)->getY() - this->vertex->getY() + height);

            if(x < y) {
                nx = 1;
                ny = 0;
            }
            else {
                nx = 0;
                ny = 1;
            }

        }

        /* 
         * si nx*ux + ny*uy == 0 --> vectores perpendiculares y en este caso el angulo
         * de incidencia debe ser cero, acos(0) = pi/2.
         */
        double pi_medio = 3.141592653589793238462 / 2.0;
        return pi_medio - acos(fabs(nx*ux + ny*uy) / (sqrt(nx*nx + ny*ny) + sqrt(ux*ux + uy*uy)));
    }
};

#endif
