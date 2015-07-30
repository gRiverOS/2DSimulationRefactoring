#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#endif

#include "Body.hh"
#include "Geometry.hh"

Body::Body(Geometry * geometry, Material * material ,int ID, bool sensitive) {
	this->geometry = geometry;
	this->ID = ID;
	this->material = material;
	this->sensitive = sensitive;
}

Body::~Body() {
	delete geometry;
	delete material;
}

Geometry* Body::getGeometry() {
	return geometry;
}

void Body::setGeometry(Geometry* geometry) {
	this->geometry = geometry;
}

int Body::getID(){
	return ID;
}

void Body::setID(int ID){
	this->ID = ID;
}

Material* Body::getMaterial() {
	return this->material;
}

bool Body::isSensitive() {
	return sensitive;
}

void Body::setSensitive(bool sensitive) {
	this->sensitive = sensitive;
}

void Body::setMaterial(Material* material) {
	this->material = material;
}
