/*
 * AND.cpp
 *
 *  Created on: 22.12.2021
 *
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#include "AND.h"

AND::AND() {
	this->inputs = 2;
	this->outputs = 1;
}

AND::~AND() {

}

int* AND::execute(int *ops) {
	int *result = new int[outputs];
	result[0] = ops[0] & ops[1];
	return result;
}

std::vector<std::vector<int>>* AND::execute(
		std::vector<std::vector<int>> *ops) {

	this->setup(ops);

	int val1;
	int val2;
	int dim = op1->size();

	for (int i = 0; i < dim; i++) {
		val1 =  op1->at(i);
		val2 =  op2->at(i);

		int r = val1 & val2;
		result->push_back(r);
	}

	vec->push_back(*result);

	return vec;
}

