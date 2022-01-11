/*
 * ADD.cpp
 *
 *  Created on: 10.01.2022
 *      Author: roman
 */

#include "ADD.h"

ADD::ADD() {

}

ADD::~ADD() {

}

/**
 *   sum = a xor b xor c
 */
std::vector<std::vector<int>>* ADD::execute(
		std::vector<std::vector<int>> *ops) {
	this->setup(ops);

	int a = 0;
	int b = 0;
	int s = 0;
	int c = 0;
	int dim = op1->size();

	std::vector<int> *carry = new std::vector<int>();

	for (int i = 0; i < dim; i++) {
		a = op1->at(i);
		b = op2->at(i);
		s = ((a ^ b) ^ c);
		result->push_back(s);
		c = ((a & b) | (a & c)) | (b & c);
	}

	carry->push_back(c);

	vec->push_back(*result);
	vec->push_back(*carry);

	delete result;
	delete carry;

	return vec;
}

