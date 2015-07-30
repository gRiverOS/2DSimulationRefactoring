/*
 * InputHandler.hh
 *
 *  Created on: 12/11/2012
 *      Author: hector
 */

#ifndef INPUTHANDLER_HH_
#define INPUTHANDLER_HH_

#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#include  <uFile.h>
#endif

#include <string>
#include <iostream>
#include <fstream>
#include <iostream>

#include "../body/BodyContainer.hh"
#include "../event/SourceHandler.hh"
#include "../event/Source.hh"


class InputHandler{
private:
	istream * input_file;
	string findData();
	vector<string> split(char* str, char* delim);
public:
	InputHandler(string fila_name);
	~InputHandler();
	void setHandlers(BodyContainer * &bodyContainer, 
					 SourceHandler * &sourceHandler,
					 string &outfile_name, 
					 string &encoding,
					 int &dimensions);
};


#endif /* INPUTHANDLER_HH_ */
