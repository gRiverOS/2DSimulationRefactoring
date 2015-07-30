#include <iostream>
#include <vector>
#include <string>
#include "body/MaterialProperties.hh"
#include "body/BodyHandler.hh"
#include "body/Body.hh"
#include "body/Geometry.hh"
#include "body/figure/Rectangle.hh"
#include "body/figure/Circumference.hh"
#include "body/CustomBodyHandler.hh"
#include "utils/GeometryAlgorithms.hh"
#include "utils/Random.hh"
#include "particle/Particle.hh"
#include "event/Event.hh"
#include "particle/AbsorptionProcess.hh"
#include "particle/ScatteringProcess.hh"
#include "particle/ProcessHandler.hh"
#include "particle/PhotonProcessHandler.hh"
#include "tracking/TrackingHandler.hh"

#define NUMBER_PROCESSORS 2

using namespace std;

#ifdef UC_PLUSPLUS
void uMain::main() {
#else
int main6(int argc, char *argv[]) {
#endif

/*	materialProperties->addProperty("absorption_coefficient", 0.0);
	materialProperties->addProperty("scattering_coefficient", 0.0);
	materialProperties->addProperty("anisotropy", 0.0);

	//aire
	Material * air = new Material();
	air->setName("Aire");
	air->setMaterialProperties(materialProperties);

	Point2D * v = new Point2D(0.0, 0.0);
	Rectangle * rectangle = new Rectangle("rectangle mother", v, 1, 1);
	srand(time(NULL));

	Body * body = new Body(rectangle, air, 1);
	int number_childrens = 1;
	CustomBodyHandler * cbh = new CustomBodyHandler(body, number_childrens);

	v = new Point2D(0.5, 0.5);
	Circumference * cirumference = new Circumference("circumference 1", v, 0.45);

	materialProperties = new MaterialProperties();
	materialProperties->addProperty("absorption_coefficient", 1.0);
	materialProperties->addProperty("scattering_coefficient", 100.0);
	materialProperties->addProperty("anisotropy", 0.9);
	Material * tissue = new Material();
	tissue->setName("tissue 1");
	tissue->setMaterialProperties(materialProperties);

	body = new Body(cirumference, tissue, 2);
	cbh->addBody(body, 2);

	v = new Point2D(0.5, 0.25);

	materialProperties = new MaterialProperties();
	materialProperties->addProperty("absorption_coefficient", 1.0);
	materialProperties->addProperty("scattering_coefficient", 10.0);
	materialProperties->addProperty("anisotropy", 0.0);
	tissue = new Material();
	tissue->setName("tissue 2");
	tissue->setMaterialProperties(materialProperties);

	cirumference = new Circumference("Circumference 2", v, 0.12);
	body = new Body(cirumference, tissue, 3);
	cbh->addBody(body, 1);

	materialProperties = new MaterialProperties();
	materialProperties->addProperty("absorption_coefficient", 1.0);
	materialProperties->addProperty("scattering_coefficient", 100.0);
	materialProperties->addProperty("anisotropy", 0.9);
	tissue = new Material();
	tissue->setName("tissue 1");
	tissue->setMaterialProperties(materialProperties);

	v = new Point2D(0.5, 0.25);
	rectangle = new Rectangle("rectangle 2", v, 0.05, 0.05);
	body = new Body(rectangle, tissue, 4);
	cbh->addBody(body, 0);

	materialProperties = new MaterialProperties();
	materialProperties->addProperty("absorption_coefficient", 2.0);
	materialProperties->addProperty("scattering_coefficient", 10.0);
	materialProperties->addProperty("anisotropy", 0.7);
	tissue = new Material();
	tissue->setName("tissue 3");
	tissue->setMaterialProperties(materialProperties);

	v = new Point2D(0.5, 0.5);
	rectangle = new Rectangle("rectangle 3", v, 0.20, 0.20);
	body = new Body(rectangle, tissue, 5);
	cbh->addBody(body, 0);

	cbh->setUniverseAsCurrentBody();

	Point2D * pointEvent = new Point2D(0.51,0.26);
	Point2D * directionParticle = new Point2D(1.0,0);

	Particle * particleEvent = new Particle(pointEvent,directionParticle,1E-4);
	Event * event = new Event(1, pointEvent, particleEvent);

	ScatteringProcess * scatterProcess = new ScatteringProcess();
	AbsorptionProcess * absorptionProcess = new AbsorptionProcess();
	ProcessHandler * pHandler = new PhotonProcessHandler(absorptionProcess,scatterProcess);

	TrackingHandler * tracking = new TrackingHandler(event,pHandler,cbh);
	tracking->trackParticle();*/
}
