/*
 * BodyContainerNode.hh
 *
 *  Created on: 09/10/2012
 *      Author: hector
 */

#ifndef BODYCONTAINERNODE_HH_
#define BODYCONTAINERNODE_HH_

#include "../body/Body.hh"
#include <vector>

using namespace std;

class BodyContainerNode {
private:
	Body * body;
	BodyContainerNode * motherBody;
	vector <BodyContainerNode*> childrenBodys;
	unsigned int number_childrens;
public:
	BodyContainerNode(Body * n_body, BodyContainerNode * n_motherBody, unsigned int n_number_childrens) : body(n_body) , motherBody(n_motherBody), number_childrens(n_number_childrens){
	};
	~BodyContainerNode(){
		delete body;
		for(unsigned int i = 0;i < childrenBodys.size(); i++){
			delete childrenBodys[i];
		}
	};
	void addChildren(BodyContainerNode * body);
	vector <BodyContainerNode*> getChildrenBodys();
	Body * getBody();
	BodyContainerNode * getMotherBody();
	unsigned int getNumber_childrens();
	void setNumbre_childrens(unsigned int n_number_childrens);
};

#endif /* BODYCONTAINERNODE_HH_ */
