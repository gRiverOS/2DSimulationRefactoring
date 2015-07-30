/*
 * Source.hh
 *
 *  Created on: 06/11/2012
 *      Author: hector
 */

#ifndef SOURCE_HH_
#define SOURCE_HH_

#include "../body/Geometry.hh"

class Source {
private:
    int ID;
    Geometry * geometry;
    int particleNumbers;
    int emitedParticles;

    /*
     * Estas variables son utilizadas para fuentes direccionadas, la primera 
     * corresponde al ángulo de apertura desde donde se disparan fotones, 
     * la segunda a la dirección
     *
     * Para el caso de 2D estas variables representarán un triangulo, 
     * donde el angulo de apertura es lo maximo que puede desviarse un foton
     * con respecto a la direccion de disparo
     *
     * Para el caso de 3D estas variables representan un cono
     */
    double angularAperture;
    Point * direction;
public:
    Source();
    Source(Geometry * geometry, int particleNumbers, int ID, int e = 0) : emitedParticles(e) {
        this->geometry = geometry;
        this->particleNumbers = particleNumbers;
        this->ID = ID;
        this->direction = NULL;
    };
    ~Source();
    Geometry * getGemeotry();
    void setGeometry(Geometry * geometry);
    int getParticleNumbers();
    void setParticleNumbers(int partucleNumbers);
    int getEmitedParticles();
    void setEmitedParticles(int emitedParticles);
    int getID();
    void setID(int ID);

    Point* getDirection();
    void setDirection(Point* direction);
    double getAngularAperture();
    void setAngularAperture(double angularAperture);

    Point * getRandomDirection();
};

#endif /* SOURCE_HH_ */
