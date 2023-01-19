/*
 * 	Implements binary subtraction
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#include "../../functions/arithmetic/SUB.h"

std::vector<std::vector<int>>* SUB::execute(
		std::vector<std::vector<int>> *ops) {

	this->setup();

	std::vector<int> *bin1 = &ops->at(0);
	std::vector<int> *bin2 = &ops->at(1);

	int dim = bin1->size();
	int x = 0;
	int y = 0;
	int d = 0;
	int b = 0;

	std::vector<int> diff;
	std::vector<int> borrow;

	std::vector<std::vector<int>> *result = new std::vector<std::vector<int>>();

	for (int i = 0; i < dim; i++) {
		x = bin1->at(i);
		y = bin2->at(i);
		d = (x ^ y) ^ b;
		b = (~x & b) | (~x & y) | (y & b) ;
		diff.push_back(d);
	}

	borrow.push_back(b);

	result->push_back(diff);
	result->push_back(borrow);

	return result;
}

