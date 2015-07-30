/*
 * CoroutineWriter.cc
 *
 *  Created on: 29/11/2012
 *      Author: hector
 */

#ifndef WRITER_CC_
#define WRITER_CC_

#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#include  <uFile.h>
#endif

#include <string>
#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../tracking/Track.hh"
#include <vector>
#include "../common/Point2D.hh"
#include "../particle/PhotonParticleChange.hh"
#include <aio.h>

using namespace std;

_Coroutine Writer {
private:
	string data;
	bool done;
	ostream *outfile;
	aiocb aioData;

	void main() {
		for (;;) {
			*outfile << data << "\n";
			suspend();
			if (done)
				break;
		}
		delete outfile;
	};

	string formatData(Track * track){
		stringstream outStream;
		outStream << track->getEventID() <<
				  " " << track->getParticle()->getPosition()->toString() <<
				  " " << track->getParticle()->getEnergy() <<
				  " " << track->getTime() <<
				  " " << track->getParticle()->getDirection()->toString() <<
				  " " << dynamic_cast<PhotonParticleChange *>(track->getParticleChange())->getAbsorption() <<
				  " " << track->getSourceID();
		return outStream.str();
	};

public:
	void addTracks(vector<Track *> tracks) {
		for(unsigned int i = 0;i < tracks.size(); i++){
			data.append(formatData(tracks[i]) + "\n");
			delete tracks[i];
		}

	};

	void saveFile(){
		resume();
		data = "";
	}

	void stop() {
		done = 1;
		resume();
	};

	Writer(string output_file_name) {
		done = false;
		data = "";
		try {
			outfile = new ofstream(strdup(output_file_name.c_str()));
		} catch (uFile::Failure ) {
			cerr << "No se puede abrir el archivo de salida\"" << output_file_name  << "\"" << endl;
			exit(-1);
		}
	};
};

#endif /* WRITER_CC_ */
