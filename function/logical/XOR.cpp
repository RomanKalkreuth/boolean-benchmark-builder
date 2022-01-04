/*
 * XOR.cpp
 *
 *  Created on: 27.12.2021
 *      Author: roman
 */

#include "XOR.h"

XOR::XOR() {
	this->inputs = 2;
	this->outputs = 1;
}

XOR::~XOR() {

}

int XOR::execute(int *ops) {
	return ops[0] ^ ops[1];
}

