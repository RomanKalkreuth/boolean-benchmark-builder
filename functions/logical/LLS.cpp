/*
 * LLS.cpp
 *
 *  Created on: 09.01.2023
 *      Author: roman
 */

#include "../../functions/logical/LLS.h"

int LLS::execute(int *ops) {
	int result = 0;
	result = ops[0] << 1 ;
	return result;
}

std::vector<std::vector<int>>* LLS::execute(
		std::vector<std::vector<int>> *ops) {

	this->setup();
	std::vector<int> *op = &ops->at(0);
	std::vector<int> *bin = new std::vector<int>();

	int value = 0;
	int dim = op->size();

	for (int i = 0; i < dim; i++) {
		value = op->at(i);
		bin->push_back(value);
	}

	std::move(bin->begin(), bin->begin() + bin->size(), bin->begin() + 1);
	bin->at(0) = 0;

	result->push_back(*bin);

	return result;
}

