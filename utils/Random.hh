/*
 * Random.hh
 *
 *  Created on: 11/11/2012
 *      Author: hector
 */

#ifndef RANDOM_HH_
#define RANDOM_HH_

class Random{
// private:

// 	// Almacena los estados random de manera privada a la hebra
	// struct drand48_data* privateBuffer;
public:
	// Random();
    // Random(long int seed);
	double RandomNumBetweenZeroOne();
	double RandomNum();
};


#endif /* RANDOM_HH_ */
