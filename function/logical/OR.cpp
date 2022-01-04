/*
 * OR.cpp
 *
 * Created on: 09.12.2021
 * Author: Roman Kalkreuth
 */

#include "OR.h"

OR::OR() {
	this->inputs = 2;
	this->outputs = 1;
}

OR::~OR() {

}

int OR::execute(int *ops) {
	return ops[0] | ops[1];
}
