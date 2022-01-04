/*
 * ADD.cpp
 *
 *  Created on: 03.01.2022
 *      Author: roman
 */

#include "ADD.h"

ADD::ADD() {
	this->inputs = 3;
	this->outputs = 2;
}

ADD::~ADD() {

}

int ADD::execute(int *ops) {
	int s;
	int carry;
	s = ops[0] ^ ops[1] ^ ops[2];
	carry = (ops[0] & ops[1]) + (ops[2] & (ops[0] ^ ops[1]));
	return s;
}


