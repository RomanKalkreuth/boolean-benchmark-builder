/*
 * Pow.cpp
 *
 *  Created on: 11.01.2022
 *      Author: roman
 */

#include "Pow.h"

Pow::Pow() {
	// TODO Auto-generated constructor stub

}

Pow::~Pow() {
	// TODO Auto-generated destructor stub
}

unsigned long Pow::pow(int x, unsigned int p)
{
  if (p == 0) return 1;
  if (p == 1) return x;

  unsigned long tmp = pow(x, p/2);
  if (p%2 == 0) return tmp * tmp;
  else return x * tmp * tmp;
}

