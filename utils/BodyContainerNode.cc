#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#endif


#include "BodyContainerNode.hh"

void BodyContainerNode::addChildren(BodyContainerNode * body){
	this->childrenBodys.push_back(body);
}

vector <BodyContainerNode*> BodyContainerNode::getChildrenBodys(){
	return this->childrenBodys;
}

Body * BodyContainerNode::getBody(){
	return this->body;
}

BodyContainerNode * BodyContainerNode::getMotherBody(){
	return this->motherBody;
}

unsigned int BodyContainerNode::getNumber_childrens(){
	return this->number_childrens;
}
void BodyContainerNode::setNumbre_childrens(unsigned int n_number_childrens){
	this->number_childrens = n_number_childrens;
}
