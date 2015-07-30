#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#include <uDeadlineMonotonic.h>
#endif

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
#include "body/BodyContainer.hh"
#include "utils/GeometryAlgorithms.hh"
#include "utils/Random.hh"
#include "particle/AbsorptionProcess.hh"
#include "particle/ScatteringProcess.hh"
#include "particle/ProcessHandler.hh"
#include "particle/PhotonProcessHandler.hh"
#include "tracking/TrackingHandler.hh"
#include "tracking/EventDispatcher.hh"
#include "tracking/EventBuffer.cc"
#include "io/InputHandler.hh"

#include "common/PointFactory.hh"

#include <iostream>
#include <fstream>
#include <sstream>
#include "event/EventFactory.hh"
#include <stddef.h>
#include "io/Writer.cc"
#include <sys/time.h>

#define NUMBER_PROCESSORS 2

using namespace std;

#ifdef UC_PLUSPLUS

struct timeval start, end;

double  diffTime(struct timeval start, struct timeval end){

    double msecs;
    msecs   = (double)end.tv_sec*1000.0 + (double)end.tv_usec/1000.0;
    msecs   -= (double)start.tv_sec*1000.0 + (double)start.tv_usec/1000.0;
    return msecs;
};

int PointFactory::dimensions = 2;

void uMain::main() {
#else
    int main(int argc, char *argv[]) {
#endif

    gettimeofday(&start,NULL);

    srand48(time(NULL));
    srand(time(NULL));
    // srand48(100);
    // srand(100);

    CustomBodyHandler * customBodyHandler;
    SourceHandler * sourceHandler;
    BodyContainer * bodyContainer;
    vector<EventBuffer * > eventBuffers;
    InputHandler * inputHandler;
    ProcessHandler * processHandler;
    Random * random;
    EventFactory * eventFactory;
    EventDispatcher * eventDispatcher;
    string input_file_name, outfile_name, enconding;
    int processors,buffersize, dimensions;
    vector<Writer *> coroutineWriters;

    switch (argc) {
         case 4:
             break;
         default:
             cerr << "Usage: " << argv[0] << " input-file processors-number buffer-size" << endl;
             exit(-1);
    } // switch

    input_file_name = argv[1];
    processors = atoi(argv[2]);
    buffersize = atoi(argv[3]);

    int virutalprocessors = processors;

    if(processors < 1)
        processors = 1;

    inputHandler   = new InputHandler(input_file_name);
    random         = new Random();
    sourceHandler  = new SourceHandler(random);
    
    // cout << "main.cc: Activando inputHandler..." << endl;
    inputHandler->setHandlers(bodyContainer, sourceHandler, outfile_name,enconding, dimensions);
    
    // cout << "main.cc: Experimento " << dimensions << "D..." << endl;

    // tipo de experimento: 2D o 3D
    PointFactory::dimensions = dimensions;

    eventFactory   = new EventFactory(sourceHandler, random);
    processHandler = new PhotonProcessHandler(
        new AbsorptionProcess(),
        new ScatteringProcess(random),
        random
    );


    for(int i = 0; i < processors; i++) {
        eventBuffers.push_back(new EventBuffer());
    }

    for(int i = 0;i < processors; i++) {
        stringstream s;
        s << outfile_name << "_" << i << ".txt";
        coroutineWriters.push_back(new Writer(s.str()));
    }

    uCluster wclus[processors] __attribute__(( unused ));
    uProcessor *wcpus[processors];

    //cout << "number of processors in cluster1 = " << Cluster1.getProcessors() << endl;

    // cout << "main.cc: Inicializando event dispatcher..." << endl;

    {
        eventDispatcher = new EventDispatcher(eventFactory, eventBuffers, buffersize);
        vector<TrackingHandler *> trackins;

        for(int i = 0; i < processors;i ++){
            wcpus[i] = new uProcessor(uThisCluster());

            //customBodyHandler = new CustomBodyHandler(bodyContainer);
            /*
            TrackingHandler * tracking = new TrackingHandler(
                processHandler, 
                customBodyHandler, 
                i + 1,
                eventBuffers[i], 
                coroutineWriters[i] , 
                random, 
                Cluster1
            );
            trackins.push_back(tracking);
            */
            trackins.push_back(
                new TrackingHandler(
                    processHandler, 
                    new CustomBodyHandler(bodyContainer), 
                    i + 1,
                    eventBuffers[i], 
                    coroutineWriters[i] , 
                    random, 
                    uThisCluster()
                )
            );
        }

        delete eventDispatcher;

        for (int i = 0;i < processors; i++) {
            delete trackins[i];
             delete wcpus[i];
        }
    }


    for(int i = 0;i < processors; i++)
        delete eventBuffers[i];

    delete inputHandler;
    delete bodyContainer;
    delete processHandler;
    delete random;

    // for ( unsigned int i = 0; i < virutalprocessors ; i += 1 ) {
    //     delete processor[ i ];
    // }
    // delete [] processor;
     
    gettimeofday(&end,NULL);
    cout << "End: "<<  (diffTime(start, end)/1000) << endl;

#ifdef UC_PLUSPLUS
#else
    return 0;
#endif

}
