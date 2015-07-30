/*
 * TrackingHandler.hh
 *
 *  Created on: 11/11/2012
 *      Author: hector
 */

#ifndef BUFFER_HH_
#define BUFFER_HH_


#define UC_PLUSPLUS

#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#include  <uFile.h>
#endif
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
_Monitor Buffer {
	std::vector<T> elements;
  public:
	Buffer(){
	};
	~Buffer() {
	};
	//Falta agregar no mutex
	int count() {
		return elements.size();
	};

	void insert( T elem );
	T remove();
};

template<class T>
void Buffer<T>::insert( T elem ) {
	elements.push_back(elem);
}

template<typename T>
T Buffer<T>::remove() {
	T elem;
	if(elements.size() > 0){
		elem = elements[0];
		elements.erase(elements.begin());
		return elem;
	} else{
		return NULL;
	}
}

#endif /* BUFFER_HH_ */


