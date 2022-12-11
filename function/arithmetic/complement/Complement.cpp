/*
 * COMPL.cpp
 *
 *  Created on: 11.12.2022
 *      Author: roman
 */

#include "Complement.h"

Complement::Complement() {
	funcAdd = new ADD();
}

Complement::~Complement() {
	delete funcAdd;
}

std::vector<int>* Complement::complement(std::vector<int> *bin) {
	int dim = bin->size();
	int x;
	int x_;

	std::vector<int> one(dim, 0);
	std::vector<int> *cmpl;

	std::vector<std::vector<int>> *result;

	one.at(0) = 1;

	for (int i = 0; i < dim; i++) {
		x = bin->at(i);
		x_ = (x == 0 ? 1 : 0);
		bin->at(i) = x_;
	}

	result = funcAdd->execute(bin, &one);

	cmpl = new std::vector<int>(result->at(0));

	delete result;

	return cmpl;
}

