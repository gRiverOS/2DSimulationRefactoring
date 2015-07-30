/*
 * MaterialProperties.hh
 *
 *  Created on: 09/10/2012
 *      Author: hector
 */

#ifndef MATERIALPROPERTIES_HH_
#define MATERIALPROPERTIES_HH_

#include <map>
#include <string>

using namespace std;

class MaterialProperties {
private:
	map<string,double> properties;
public:
	MaterialProperties();
	MaterialProperties(map<string,double> properties);
	~MaterialProperties();
	map<string,double> getProperties();
	void setProperties(map<string,double> properties);
	bool addProperty(string name, double value);
	bool removeProperty(string name);
	double getProperty(string name);
};

#endif /* BODY_HH_ */
