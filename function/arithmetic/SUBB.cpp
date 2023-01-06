/*
 * SUBB.cpp
 *
 *  Created on: 06.01.2023
 *      Author: roman
 */

#include "SUBB.h"

std::vector<std::vector<int>>* SUBB::execute(
		std::vector<std::vector<int>> *ops) {

	this->setup();

	std::vector<int> *bin1 = &ops->at(0);
	std::vector<int> *bin2 = &ops->at(1);
	std::vector<int> *bin3 = &ops->at(2);

	int borrowIn = bin3->at(0);

	int dim = bin1->size();
	int x = 0;
	int y = 0;
	int d = 0;
	int b = borrowIn;

	std::vector<int> diff;
	std::vector<int> borrowOut;

	std::vector<std::vector<int>> *result = new std::vector<std::vector<int>>();

	for (int i = 0; i < dim; i++) {
		x = bin1->at(i);
		y = bin2->at(i);
		d = (x ^ y) ^ b;
		b = (~x & b) | (~x & y) | (y & b) ;
		diff.push_back(d);
	}

	borrowOut.push_back(b);

	result->push_back(diff);
	result->push_back(borrowOut);

	return result;
}
