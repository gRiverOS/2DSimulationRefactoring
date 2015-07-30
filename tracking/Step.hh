/*
 * Step.hh
 */

#ifndef STEP_HH_
#define STEP_HH_

#include "../common/Point.hh"

using namespace std;

class Step {
private:
	Point* position;	// Inicio del step
	Point* direction;	// Direción del step
	double step_size;	// Largo del step

	bool hit;				  // Indica si hay un hit entre el inicio y final del step
	Point* hit_point;		  // En caso de un hit, indica cual es el punto de interseccion 
	double interaction_ratio; // Es la division entre el coef de interaccion el cuerpo
							  // donde el step comienza y el cuerpo donde debería terminar
public:
	Step();
	Step(double stepSize);
	~Step();
	
	void setPosition(Point* pos);
	void setDirection(Point* dir);
	void setStep_size(double step_size);
	void setHit(bool hit_boundary);
	void setHitPoint(Point* intersection);
	void setInteractionRatio(double ratio);

	Point* getPosition();
	Point* getDirection();
	double getStep_size();
	bool getHit();
	Point* getHitPoint();
	double getInteractionRatio();

	// Distancia entre la posición de un step
	// hasta el punto de interseccion
	double getForeshortenedStep();
	
};

#endif /* STEP_HH_ */
