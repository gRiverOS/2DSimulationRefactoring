/*
 * CustomBodyHandler.hh
 *
 *  Created on: 20/10/2012
 *      Author: hector
 */

#ifndef BODYCONTAINER_HH_
#define BODYCONTAINER_HH_

#include "Body.hh"
#include "BodyHandler.hh"
#include "../common/Point.hh"
#include "../utils/BodyContainerNode.hh"
#include <iomanip>

using namespace std;

class BodyContainer {
private:
	BodyContainerNode * universe_body;
	BodyContainerNode * getBodyNode(BodyContainerNode * body, Point * v);
	BodyContainerNode * adding;
public:
	BodyContainer();
	BodyContainer(Body * n_universe_body, unsigned int chidrens);
	bool addBody(Body * body, unsigned int childrens);
	void showTree(BodyContainerNode * b);
	BodyContainerNode * getBody(Point * position);
	BodyContainerNode * getUniverseBody();
	virtual ~BodyContainer() {
		delete universe_body;
	};
};

#endif /* BODYCONTAINER_HH */
