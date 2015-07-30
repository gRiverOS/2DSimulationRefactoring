#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#endif

#include "Step.hh"
#include "../common/Point2D.hh"
#include "../common/Point3D.hh"
#include "../common/PointFactory.hh"
#include "../utils/GeometryAlgorithms.hh"

Step::Step() {
    this->step_size = 1;
}

Step::Step(double step_size){
    this->step_size = step_size;
}

Step::~Step(){
    // if(this->position != NULL)
    //     delete this->position;

    // if(this->direction != NULL)
    //     delete this->direction;

    // if(this->hit_point != NULL)
    //     delete this->hit_point;
}

void Step::setStep_size(double step_size) {
    this->step_size = step_size;
}

void Step::setPosition(Point* pos) {
    // printf("Step.cc: Llamando a setPosition\n");
    this->position = PointFactory::getPoint(pos);
    // printf("Step.cc: Finalizando setPosition\n");
}

void Step::setDirection(Point* dir) {
    // printf("Step.cc: Llamando a setDirection\n");
    this->direction = PointFactory::getPoint(dir);
    // printf("Step.cc: Finalizando setDirection\n");
}

void Step::setHit(bool hit_boundary) {
    this->hit = hit_boundary;
}

void Step::setHitPoint(Point* intersection) {
    this->hit_point = PointFactory::getPoint(intersection);
}

void Step::setInteractionRatio(double ratio) {
    this->interaction_ratio = ratio;
}

double Step::getStep_size() {
    // printf("Step.cc: Llamando a getStep_size\n");
    return this->step_size;
}

Point* Step::getPosition() {
    return this->position;
}

Point* Step::getDirection() {
    return this->direction;
}

bool Step::getHit() {
    return this->hit;
}

Point* Step::getHitPoint() {
    if (this->hit)
        return this->hit_point;
    else
        return NULL;
}
double Step::getInteractionRatio(){
    if (this->hit)
        return this->interaction_ratio;
    else
        return 0;
}

double Step::getForeshortenedStep() {
    if (this->hit) {
        GeometryAlgorithms * alg = new GeometryAlgorithms();
        double d;
        
        if (PointFactory::dimensions == 2) {
            d = alg->distanceBetweenPoints(dynamic_cast<Point2D *>(position), dynamic_cast<Point2D *>(hit_point));
        }
        else if (PointFactory::dimensions == 3) {
            d = alg->distanceBetweenPoints(dynamic_cast<Point3D *>(position), dynamic_cast<Point3D *>(hit_point));
        }
        else {
            d = 0;
        }

        delete alg;
        return d;
    }
    else {
        return 0;
    }
}