/*
 * 	Implements binary complement
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#include "../../../functions/arithmetic/complement/Complement.h"

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
	std::vector<int> *temp = new std::vector<int>(); ;
	std::vector<int> *cmpl;

	std::vector<std::vector<int>> *result;

	one.at(0) = 1;

	for (int i = 0; i < dim; i++) {
		x = bin->at(i);
		x_ = (x == 0 ? 1 : 0);
		temp->push_back(x_);
	}

	result = funcAdd->execute(temp, &one);

	cmpl = new std::vector<int>(result->at(0));

	delete temp;
	delete result;

	return cmpl;
}

