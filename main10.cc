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
#include "io/InputHandler.hh"
#include "body/CustomBodyHandler.hh"
#include "body/BodyContainer.hh"

#define NUMBER_PROCESSORS 2

using namespace std;

#ifdef UC_PLUSPLUS
void uMain::main() {
#else
int main10(int argc, char *argv[]) {
#endif
	srand48(time(NULL));
	string input_file_name = "input/input.in", outfile_name, enconding;
	bool file_opened;
	CustomBodyHandler * cbh;
	SourceHandler * sourceHandler;
	BodyContainer * bodyContainer;

	InputHandler * inputHandler = new InputHandler(input_file_name,
			file_opened);

	if (!file_opened) {
		cout << "Cant read the input file: " << input_file_name << endl;
		exit(1);
	}

	inputHandler->setHandlers(bodyContainer, sourceHandler, outfile_name,
			enconding);

	cbh = new CustomBodyHandler(bodyContainer);


	Point2D * pointEvent = new Point2D(0.51, 0.26);
	Point2D * directionParticle = new Point2D(1.0, 0);

	Particle * particleEvent = new Particle(pointEvent, directionParticle, 3);
	Event * event = new Event(1, pointEvent, particleEvent);

	Random * random = new Random();

	ScatteringProcess * scatterProcess = new ScatteringProcess(random);
	AbsorptionProcess * absorptionProcess = new AbsorptionProcess();
	ProcessHandler * pHandler = new PhotonProcessHandler(absorptionProcess,
			scatterProcess);

	/*Here Aqui que copiar posteriormente el valor del bodyHandler dado el current body no sera comun para los multiples trackinghandler*/

	/*customBodyHandler->setCurrentBody(new Point2D(0.5, 0.5));
	TrackingHandler * tracking = new TrackingHandler(event, pHandler,
			customBodyHandler);
	tracking->trackParticle();

	customBodyHandler->setUniverseAsCurrentBody();
	TrackingHandler * tracking2 = new TrackingHandler(event, pHandler,
			customBodyHandler);*/

	Body * body; Point2D * v;
	cbh->setUniverseAsCurrentBody();
	v = new Point2D(1, 1);
	body = cbh->getBody(v);
	if (body != NULL)
		cout << "Para el vector (" << v->getX() << "," << v->getY()
				<< ") el body es: " << body->getID() << endl;
	else
		cout << "not found !" << endl;

	cbh->setUniverseAsCurrentBody();
	v = new Point2D(5.1, 5.1);
	body = cbh->getBody(v);
	if (body != NULL)
		cout << "Para el vector (" << v->getX() << "," << v->getY()
				<< ") el body es: " << body->getID() << endl;
	else
		cout << "not found !" << endl;

	cbh->setUniverseAsCurrentBody();
	v = new Point2D(5.0, 2.4);
	body = cbh->getBody(v);
	if (body != NULL)
		cout << "Para el vector (" << v->getX() << "," << v->getY()
				<< ") el body es: " << body->getID() << endl;
	else
		cout << "not found !" << endl;

	cbh->setUniverseAsCurrentBody();
	v = new Point2D(1, 1);
	body = cbh->getBody(v);
	if (body != NULL)
		cout << "Para el vector (" << v->getX() << "," << v->getY()
				<< ") el body es: " << body->getID() << endl;
	else
		cout << "not found !" << endl;

	cbh->setUniverseAsCurrentBody();
	v = new Point2D(5.1, 2.6);
	body = cbh->getBody(v);
	if (body != NULL)
		cout << "Para el vector (" << v->getX() << "," << v->getY()
				<< ") el body es: " << body->getID() << endl;
	else
		cout << "not found !" << endl;

	cbh->setUniverseAsCurrentBody();
	v = new Point2D(5.7, 6.0);
	body = cbh->getBody(v);
	if (body != NULL)
		cout << "Para el vector (" << v->getX() << "," << v->getY()
				<< ") el body es: " << body->getID() << endl;
	else
		cout << "not found !" << endl;

	cbh->setUniverseAsCurrentBody();
	v = new Point2D(1.0, 1.2);
	body = cbh->getBody(v);
	if (body != NULL)
		cout << "Para el vector (" << v->getX() << "," << v->getY()
				<< ") el body es: " << body->getID() << endl;
	else
		cout << "not found !" << endl;

	cbh->setUniverseAsCurrentBody();
	v = new Point2D(4.3, 4.0);
	body = cbh->getBody(v);
	if (body != NULL)
		cout << "Para el vector (" << v->getX() << "," << v->getY()
				<< ") el body es: " << body->getID() << endl;
	else
		cout << "not found !" << endl;

	cbh->setUniverseAsCurrentBody();
	v = new Point2D(5.7, 6.0);
	body = cbh->getBody(v);
	if (body != NULL)
		cout << "Para el vector (" << v->getX() << "," << v->getY()
				<< ") el body es: " << body->getID() << endl;
	else
		cout << "not found !" << endl;

	cbh->setUniverseAsCurrentBody();
	v = new Point2D(5.0, 2.4);
	body = cbh->getBody(v);
	if (body != NULL)
		cout << "Para el vector (" << v->getX() << "," << v->getY()
				<< ") el body es: " << body->getID() << endl;
	else
		cout << "not found !" << endl;

	cbh->setUniverseAsCurrentBody();
	v = new Point2D(4.3, 4.0);
	body = cbh->getBody(v);
	if (body != NULL)
		cout << "Para el vector (" << v->getX() << "," << v->getY()
				<< ") el body es: " << body->getID() << endl;
	else
		cout << "not found !" << endl;

}
