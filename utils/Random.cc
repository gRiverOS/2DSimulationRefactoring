/*
 * Random.cc
 *
 *  Created on: 11/11/2012
 *      Author: hector
 */


/*
 * Random.hh
 *
 *  Created on: 11/11/2012
 *      Author: hector
 */

#define UC_PLUSPLUS
#ifdef  UC_PLUSPLUS
#include  <uC++.h>
#endif


#include <cstddef>
#include <time.h>
#include <math.h>

#include "Random.hh"
#include <stdlib.h>
#include <stddef.h>

// Random::Random() {
// 	this->privateBuffer = new drand48_data;
// 	srand48_r(time(NULL), this->privateBuffer);
// }

// Random::Random(long int seed) {
// 	this->privateBuffer = new drand48_data;
// 	srand48_r(seed, this->privateBuffer);
// }

double Random::RandomNumBetweenZeroOne(void) {
	return drand48();
	// double r1;
    // drand48_r(this->privateBuffer, &r1);
    // // printf("%lf\n", r1);
    // return r1;
}
;


double Random::RandomNum(){
	return rand();
}
