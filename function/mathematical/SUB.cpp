/*
 * SUB.cpp
 *
 *  Created on: 03.01.2022
 *
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#include "SUB.h"

SUB::SUB() {
}

SUB::~SUB() {
}

std::vector<int>* SUB::complement(std::vector<int> *bin) {
	int dim = bin->size();
	int x;
	int x_;

	std::vector<int> one(dim, 0);
	std::vector<int> *cmpl;

	std::vector<std::vector<int>>* result;

	one.at(0) = 1;

	for (int i = 0; i < dim; i++) {
		x = bin->at(i);
		x_ = (x == 0 ? 1 : 0);
		bin->at(i) = x_;
	}

	result = add(bin, &one);

	cmpl =  new std::vector<int>(result->at(0));

	delete result;

	return cmpl;
}

std::vector<std::vector<int>>* SUB::execute(
		std::vector<std::vector<int>> *ops) {


	this->setup();
	std::vector<int>* op1 =  &ops->at(0);
	std::vector<int>* op2 =  &ops->at(1);
	std::vector<int>* op3 =  &ops->at(2);

	int a = 0;
	int b = 0;
	int s = 0;
	int c =  op3->at(0);
	int dim = op1->size();

	std::vector<int> *cmpl;
	std::vector<int> carry;

	cmpl = complement(op2);

	carry.push_back(c);

	result->push_back(*res);
	result->push_back(carry);

	delete cmpl;

	return result;
}

