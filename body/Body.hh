/*
 * Body.hh
 *
 *  Created on: 09/10/2012
 *      Author: hector
 */

#ifndef BODY_HH_
#define BODY_HH_

#include "Geometry.hh"
#include "Material.hh"

using namespace std;

class Body {
private:
	Geometry * geometry;
	Material * material;
	int ID;
	bool sensitive;
public:
	Body(Geometry * geometry, Material * material , int ID, bool sensitive);
	~Body();
	Geometry* getGeometry();
	void setGeometry(Geometry* geometry);
	int getID();
	void setID(int ID);
	Material * getMaterial();
	void setMaterial(Material * material);
	bool isSensitive();
	void setSensitive(bool sensitive);
};

#endif /* BODY_HH_ */
