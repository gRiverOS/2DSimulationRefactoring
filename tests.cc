
#include <iostream>
#include <string>
#include <math.h>
#include <float.h>
#include <cmath>

#include <stdio.h>

using namespace std;

void getIntersectionPoint() {

	double x1, x2, x3, x4, y1, y2, y3, y4;
    double m1, m2;
    double x, y;

    // Se definen los puntos  
    // x1 = pointOne->getX();
    // y1 = pointOne->getY();

    // x2 = pointTwo->getX();
    // y2 = pointTwo->getY();

    // x3 = pointThree->getX();
    // y3 = pointThree->getY();

    // x4 = pointFour->getX();
    // y4 = pointFour->getY();

    x1 = 0.3;
    y1 = 0.25;

    x2 = 0.6;
    y2 = 0.25;

    x3 = 0.6;
    y3 = 0.493535;

    x4 = 0.345726;
    y4 = 0.736448;

    // Dos rectas paralelas verticales
    // if (fabs(x2 - x1) < FLT_EPSILON && fabs(x4 - x3) < FLT_EPSILON) {
    if ((x2 - x1) == 0 && (x4 - x3) == 0) {
        //return NULL;
        printf("NULL\n");
    }

    // Una recta vertical y otra no
    // else if (fabs(x2 - x1) < FLT_EPSILON && fabs(x4 - x3) > FLT_EPSILON) {
    else if ((x2 - x1) == 0 && (x4 - x3) != 0) {
        // m1 -> infinito  and  m2 pertenece a los reales
        m2 = (y4 - y3) / (x4 - x3);
        x = x1;
        y = m2 * (x1 - x3) + y3;

        //return new Point2D(x, y);
        printf("(%lf, %lf)\n", x, y)
    }

    // else if (fabs(x2 - x1) > FLT_EPSILON && fabs(x4 - x3) < FLT_EPSILON) {
    else if ((x2 - x1) != 0 && (x4 - x3) == 0) {
        // m2 -> infinito  and  m1 pertenece a los reales
        m1 = (y2 - y1) / (x2 - x1);
        x = x3;
        y = m1 * (x3 - x1) + y1;

        //return new Point2D(x, y);
        printf("(%lf, %lf)\n", x, y);
    }

    else {
        m1 = (y2 - y1) / (x2 - x1);
        m2 = (y4 - y3) / (x4 - x1);

        // Rectas paralelas
        // if (fabs(m1 - m2) < FLT_EPSILON) {
        if (m1 == m2) {
            //return NULL;
            printf("NULL\n");
        }
        else {
            x = (m1 * x1 - y1 + y3 - m2 * x3) / (m1 - m2);
            y = (m1 * m2 * (x1 - x3) + y3 * m1 - y1 * m2) / (m1 - m2);

            //return new Point2D(x, y);
            printf("(%lf, %lf)\n", x, y);
        }
    }
}

int main(int argc, char** argv) {

	getIntersectionPoint();
	return 1;
}