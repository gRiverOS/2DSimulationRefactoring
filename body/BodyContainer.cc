#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#endif


#include "BodyContainer.hh"
#include "../utils/BodyContainerNode.hh"
#include "Body.hh"

BodyContainer::BodyContainer() {
	this->universe_body = NULL;
	this->adding = NULL;
}

BodyContainer::BodyContainer(Body * n_universe_body, unsigned int childrens) {
	this->universe_body = new BodyContainerNode(n_universe_body, NULL,childrens);
	this->adding = this->universe_body;
}

bool BodyContainer::addBody(Body * body, unsigned int childrens) {
	if (this->adding->getNumber_childrens()
			<= this->adding->getChildrenBodys().size()) {
		if (this->adding->getMotherBody() != NULL) {
			adding = this->adding->getMotherBody();
			return this->addBody(body, childrens);
		} else
			return false;
	}
	BodyContainerNode * bodyHandlerNode = new BodyContainerNode(body,
			this->adding, childrens);
	this->adding->addChildren(bodyHandlerNode);

	this->adding = this->adding->getChildrenBodys()[0];
	return true;
}

void BodyContainer::showTree(BodyContainerNode * b) {
	cout << "Node: " << b->getBody()->getID() << "cuerpos : "
			<< b->getChildrenBodys().size() << endl;
	cout << "propiedades- ua:"
			<< b->getBody()->getMaterial()->getMaterialProperties()->getProperty(
					"absorption_coefficient") << endl;
	for (unsigned int i = 0; i < b->getChildrenBodys().size(); i++) {
		this->showTree(b->getChildrenBodys()[i]);
	}
}

BodyContainerNode * BodyContainer::getUniverseBody() {
	return this->universe_body;
}

BodyContainerNode * BodyContainer::getBody(Point * position) {
	BodyContainerNode * nbody = this->universe_body;
	BodyContainerNode * bodynode = this->getBodyNode(nbody, position);
	if (bodynode != NULL) {
		return bodynode;
	} else {;
		return NULL;
	}
}
;

BodyContainerNode * BodyContainer::getBodyNode(BodyContainerNode * body,Point * v){
	if(!body->getBody()->getGeometry()->insideGeometry(v)){
		return NULL;
	}
	BodyContainerNode * b;
	for(unsigned int i = 0; i < body->getChildrenBodys().size(); i++){
		b = getBodyNode(body->getChildrenBodys()[i],v);
		if(b != NULL)
			body = b;
	}
	return body;
}
