/*
 * XOR.cpp
 *
 *  Created on: 27.12.2021
 *
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#include "XOR.h"

XOR::XOR() {
}

XOR::~XOR() {

}

int XOR::execute(int *ops) {
	int result = 0;
	result = ops[0] ^ ops[1];
	return result;
}

std::vector<std::vector<int>>* XOR::execute(
		std::vector<std::vector<int>> *ops) {

	this->setup();
	std::vector<int>* op1 =  &ops->at(0);
	std::vector<int>* op2 =  &ops->at(1);

	int val1;
	int val2;
	int dim = op1->size();

	for (int i = 0; i < dim; i++) {
		val1 = op1->at(i);
		val2 = op2->at(i);

		int r = val1 ^ val2;
		res->push_back(r);
	}

	result->push_back(*res);

	return result;

}

