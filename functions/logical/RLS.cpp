/*
 * RLS.cpp
 *
 *  Created on: 09.01.2023
 *      Author: roman
 */

#include "../../functions/logical/RLS.h"

int RLS::execute(int *ops) {
	int result = 0;
	result = ops[0] >> 1;
	return result;
}

std::vector<std::vector<int>>* RLS::execute(
		std::vector<std::vector<int>> *ops) {

	this->setup();
	std::vector<int> *op = &ops->at(0);
	std::vector<int> *bin = new std::vector<int>();

	int value = 0;
	int r = 0;
	int dim = op->size();

	for (int i = 0; i < dim; i++) {
		value = op->at(i);
		bin->push_back(value);
	}

	std::move(bin->begin() + 1, bin->begin() + bin->size(), bin->begin());
	bin->at(bin->size() - 1) = 0;

	result->push_back(*bin);

	return result;
}
