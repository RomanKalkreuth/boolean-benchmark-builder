/*
 * AND.cpp
 *
 *  Created on: 22.12.2021
 *      Author: Roman Kalkreuth
 */

#include "AND.h"

AND::AND() {
	this->inputs = 2;
	this->outputs = 1;
}

AND::~AND() {

}

int AND::execute(int *ops) {
	return ops[0] & ops[1];
}

