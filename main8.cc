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

#define NUMBER_PROCESSORS 2

using namespace std;

#ifdef UC_PLUSPLUS
void uMain::main() {
#else
int main8(int argc, char *argv[]) {
#endif

/*	string input_file_name = "input/input.in",outfile_name,enconding;
	bool file_opened;
	CustomBodyHandler * customBodyHandler;
	SourceHandler * sourceHandler;;

	InputHandler * inputHandler = new InputHandler(input_file_name,file_opened);

	if (!file_opened) {
		cout << "Cant read the input file: " << input_file_name << endl;
		exit(1);
	}
	inputHandler->setHandlers(customBodyHandler, sourceHandler, outfile_name, enconding);

	Point2D * pointEvent = new Point2D(0.51, 0.26);
	Point2D * directionParticle = new Point2D(1.0, 0);

	Particle * particleEvent = new Particle(pointEvent, directionParticle, 3);
	Event * event = new Event(1, pointEvent, particleEvent);

	ScatteringProcess * scatterProcess = new ScatteringProcess();
	AbsorptionProcess * absorptionProcess = new AbsorptionProcess();
	ProcessHandler * pHandler = new PhotonProcessHandler(absorptionProcess,
			scatterProcess);

	TrackingHandler * tracking = new TrackingHandler(event, pHandler, customBodyHandler);
	tracking->trackParticle();
*/
}
