#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#endif

#include "../utils/GeometryAlgorithms.hh"
#include "PhotonProcessHandler.hh"
#include "AbsorptionProcess.hh"
#include "ScatteringProcess.hh"

PhotonProcessHandler::PhotonProcessHandler(AbsorptionProcess* absoptionProcess,
        ScatteringProcess* scatteringProcess, Random * random) {
    this->absoptionProcess = absoptionProcess;
    this->scatteringProcess = scatteringProcess;
    this->random = random;
}

bool PhotonProcessHandler::isReflected(Particle * p, Body * b, Body * nextb){
    GeometryAlgorithms * alg = new GeometryAlgorithms();

    
    /* 
     * Se debe analizar si el angulo de incidencia es mayor al angulo critico, 
     * en caso de ser mayor al ángulo critico la particula se reflecta sin más
     * análisis:
     * http://es.wikipedia.org/wiki/Refracci%C3%B3n#.C3.8Dndice_de_refracci.C3.B3n
     *
     * Lo anterior es equivalente a decir que
     * n1 * sin(ai) / n2 > 1 
     */

    double n1 = b->getMaterial()->getMaterialProperties()->getProperty("refractive_index");
    double n2 = nextb->getMaterial()->getMaterialProperties()->getProperty("refractive_index");
    double ai = b->getGeometry()->getIncidenceAngle(p->getPosition(), p->getDirection());
    if ( (n1 * sin(ai) / n2) > 1  ) {
        // cout << "Incidencia con angulo menor al crítico" << endl;
        return true;
    } 
    // else {
    //     cout << "Incidencia con angulo mayor al crítico" << endl;
    // }

    /*
     * Se ha reemplazado la ecuación de fresnel, ahora se le pasa por parametro
     * el angulo de incidencia
     */
    // cout << "PhotonProcessHandler.css: Ejecutando fresnel... " << endl;
    // cout << "PhotonProcessHandler.css: Position de la particula: " << p->getPosition()->toString() << endl;
    // cout << "PhotonProcessHandler.css: Direccion de la particula: " << p->getDirection()->toString() << endl;

    // cout << "PhotonProcessHandler.cc: Angulo de incidencia" << b->getGeometry()->getIncidenceAngle(p->getPosition(), p->getDirection()) * 180/3.14159 << endl;
    double n = alg->Fresnel(
        b->getMaterial()->getMaterialProperties()->getProperty("refractive_index"),
        nextb->getMaterial()->getMaterialProperties()->getProperty("refractive_index"),
        b->getGeometry()->getIncidenceAngle(p->getPosition(), p->getDirection())
        // dynamic_cast<Point2D *>(p->getDirection())->getX()
    );

    delete alg;
    // cout << "Fresnel es: " << n << endl;
    if(random->RandomNumBetweenZeroOne() <= n) {
        // cout << "Particula reflejada" << endl;
        return true;
    }
    else {
        // cout << "Particula transmitida a otro medio" << endl;
        return false;
    }
}

AbsorptionProcess* PhotonProcessHandler::getAbsoptionProcess() {
    return this->absoptionProcess;
}

void PhotonProcessHandler::setAbsoptionProcess(
        AbsorptionProcess* absoptionProcess) {
    this->absoptionProcess = absoptionProcess;
}

ScatteringProcess* PhotonProcessHandler::getScatteringProcess() {
    return this->scatteringProcess;
}

void PhotonProcessHandler::setScatteringProcess(
        ScatteringProcess* scatteringProcess) {
    this->scatteringProcess = scatteringProcess;
}
