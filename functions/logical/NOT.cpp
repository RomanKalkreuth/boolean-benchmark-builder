/*
 * NOT.cpp
 *
 *  Created on: 09.01.2023
 *      Author: roman
 */

#include "../../functions/logical/NOT.h"


int NOT::execute(int* ops) {
	int result = 0;
	result = ~ops[0];
	return result;
}

std::vector<std::vector<int>>* NOT::execute(
		std::vector<std::vector<int>> *ops) {

	this->setup();
	std::vector<int>* op1 =  &ops->at(0);

	int val1 = 0;
	int r = 0;
	int dim = op1->size();

	for (int i = 0; i < dim; i++) {
		val1 = op1->at(i);
		r = ~val1;
		res->push_back(r);
	}

	result->push_back(*res);

	return result;

}
