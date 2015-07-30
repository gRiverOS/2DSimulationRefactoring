#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#endif


#include "CustomBodyHandler.hh"
#include "../utils/BodyContainerNode.hh"
#include "Body.hh"

CustomBodyHandler::CustomBodyHandler(){
	this->body_container = NULL;
	this->current_body = NULL;
	this->next_body = NULL;
	this->lastPosition = NULL;
}

CustomBodyHandler::CustomBodyHandler(BodyContainer * body_container) {
	this->body_container = body_container;
	this->current_body = body_container->getUniverseBody();
	this->next_body = NULL;
	this->lastPosition = NULL;
}


Body * CustomBodyHandler::getCurrentBody() {
	return current_body->getBody();
}

void CustomBodyHandler::setCurrentBody(Point * vector) {
	this->current_body = this->body_container->getBody(vector);
}


void CustomBodyHandler::setUniverseAsCurrentBody(){
	this->current_body = this->body_container->getUniverseBody();
}

void CustomBodyHandler::setCurrentBodyAsNextBody() {
	this->current_body = this->next_body;
}

Point * CustomBodyHandler::getLastPosition(){
	return this->lastPosition;

}
Body * CustomBodyHandler::getNextBody(){
	return this->next_body->getBody();
}
