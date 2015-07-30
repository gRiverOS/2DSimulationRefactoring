/*
 * SourceHandler.cc
 *
 *  Created on: 06/11/2012
 *      Author: hector
 */
#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#endif

#include "SourceHandler.hh"
#include "Source.hh"

#include <math.h>

SourceHandler::SourceHandler(Random * random) {
	this->random = random;
}

SourceHandler::~SourceHandler() {
	for(unsigned int i = 0;i < this->sources.size(); i++){
		delete sources[i];
	}
}

void SourceHandler::addSource(Source * source) {
	this->sources.push_back(source);
}

Source* SourceHandler::getNextSource() {
	Source * source = NULL;
	double q = 100;
	double aTime;
	for(unsigned int i = 0; i < this->sources.size(); i++){
		if(this->sources[i]->getParticleNumbers() == this->sources[i]->getEmitedParticles())
			continue;
		aTime = -log( this->random->RandomNumBetweenZeroOne() ) * ( 1. /(this->sources[i]->getParticleNumbers() - this->sources[i]->getEmitedParticles()));
		if(aTime < q){
			source = this->sources[i];
			q = aTime;
		}
	}

	if(source != NULL ){
		source->setEmitedParticles(source->getEmitedParticles() + 1);
	}

	return source;
}
