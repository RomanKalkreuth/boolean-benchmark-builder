/*
 * 	Implements bitwise AND
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#include "AND.h"

AND::AND() {
}

AND::~AND() {

}

int AND::execute(int* ops) {
	int result = 0;
	result = ops[0] & ops[1];
	return result;
}

std::vector<std::vector<int>>* AND::execute(
		std::vector<std::vector<int>> *ops) {

	this->setup();
	std::vector<int>* op1 =  &ops->at(0);
	std::vector<int>* op2 =  &ops->at(1);

	int val1 = 0;
	int val2 = 0;
	int r = 0;
	int dim = op1->size();

	for (int i = 0; i < dim; i++) {
		val1 = op1->at(i);
		val2 = op2->at(i);
		r = val1 & val2;
		res->push_back(r);
	}

	result->push_back(*res);

	return result;
}

