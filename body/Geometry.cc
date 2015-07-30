#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#endif

#include <iostream>
#include <string>
#include "Geometry.hh"

using namespace std;

Geometry::Geometry() {
	name = "not defined";
}

Geometry::Geometry(string n_Name) :
		name(n_Name) {

}

Geometry::~Geometry() {

}

void Geometry::setName(string n_Name) {
	name = n_Name;
}

string Geometry::getName() {
	return name;
}
