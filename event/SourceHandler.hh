/*
 * SourceHandler.hh
 *
 *  Created on: 06/11/2012
 *      Author: hector
 */

#ifndef SOURCEHANDLER_HH_
#define SOURCEHANDLER_HH_

#include "Source.hh"
#include "../utils/Random.hh"
#include <vector>


class SourceHandler{
private:
	vector<Source *> sources;
	Random * random;
public:
	SourceHandler(Random * random);
	~SourceHandler();
	void addSource(Source * source);
	Source * getNextSource();
};


#endif /* SOURCEHANDLER_HH_ */
