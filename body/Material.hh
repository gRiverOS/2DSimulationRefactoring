/*
 * Material.hh
 *
 *  Created on: 09/10/2012
 *      Author: hector
 */

#ifndef MATERIAL_HH_
#define MATERIAL_HH_
#include <string>
#include "MaterialProperties.hh"

using namespace std;

class Material {
private:
	string name;
	MaterialProperties * materialProperties;
public:
	Material();
	Material(string name, MaterialProperties * materialProperties);
	~Material();
	string getName();
	void setName(string name);
	MaterialProperties * getMaterialProperties();
	void setMaterialProperties(MaterialProperties * materialProperties);
};

#endif /* MATERIAL_HH_ */
