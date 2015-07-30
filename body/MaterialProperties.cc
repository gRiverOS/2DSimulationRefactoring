#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#endif

#include "MaterialProperties.hh"

MaterialProperties::MaterialProperties() {
}

MaterialProperties::MaterialProperties(map<string, double> properties) {
	this->properties = properties;
}

MaterialProperties::~MaterialProperties() {
}

map<string, double> MaterialProperties::getProperties() {
	return this->properties;
}

void MaterialProperties::setProperties(map<string, double> properties) {
	this->properties = properties;
}

bool MaterialProperties::addProperty(string name, double value) {
	if(this->properties.count(name) > 0)
		return false;
	else{
		properties[name] = value;
		return true;
	}
}

bool MaterialProperties::removeProperty(string name) {
	if(this->properties.count(name) > 0)
			return false;
		else{
			this->properties.erase(name);
			return true;
		}
}

double MaterialProperties::getProperty(string name) {
	return this->properties[name];
}
