/*
 * Function.cpp
 *
 *  Created on: 09.12.2021
 *
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#include "Function.h"

Function::Function() {
	result = new std::vector<int>();
	vec = new std::vector<std::vector<int>>();
}

Function::~Function() {
	delete result;
	delete vec;
}

void Function::setup(std::vector<std::vector<int>> *ops) {
	op1 = &(ops->at(0));
	op2 = &(ops->at(1));
	result->clear();
	vec->clear();
}
