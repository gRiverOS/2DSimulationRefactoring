#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#endif

#include "Material.hh"

Material::Material(){
	this->name = "Undefined";
	this->materialProperties = new MaterialProperties();
}
Material::Material(string name, MaterialProperties * materialProperties){
	this->name = name;
	this->materialProperties = materialProperties;
}
Material::~Material(){
	delete this->materialProperties;
}
string Material::getName(){
	return this->name;
}
void Material::setName(string name){
	this->name = name;
}
MaterialProperties * Material::getMaterialProperties(){
	return this->materialProperties;
}
void Material::setMaterialProperties(MaterialProperties * materialProperties){
	this->materialProperties = materialProperties;
}
