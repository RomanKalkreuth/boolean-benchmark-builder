/*
 * ADD.cpp
 *
 *  Created on: 03.01.2022
 *
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#include "ADDC.h"

ADDC::ADDC() {
}

ADDC::~ADDC() {

}

/**
 *   sum = a xor b xor c
 *   carry = ab+bc+ca
 */
std::vector<std::vector<int>>* ADDC::execute(
		std::vector<std::vector<int>>* ops) {
	this->setup(ops);

	op3 =  &ops->at(2);

	int a = 0;
	int b = 0;
	int s = 0;
	int carry = op3->at(0);
	int dim = op1->size();

	for (int i = 0; i < dim; i++) {
		a = op1->at(i);
		b = op2->at(i);
		s = ((a ^ b) ^ carry);
		result->push_back(s);
		carry = ((a & b) | (a & carry)) | (b & carry);
	}

	op3->at(0) = carry;
 	vec->push_back(*result);
	vec->push_back(*op3);

	return vec;

}

