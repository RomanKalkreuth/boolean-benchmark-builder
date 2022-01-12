/*
 * MathematicalFunction.cpp
 *
 *  Created on: 10.01.2022
 *      Author: roman
 */

#include "MathematicalFunction.h"

MathematicalFunction::MathematicalFunction() {

}

MathematicalFunction::~MathematicalFunction() {
}

std::vector<std::vector<int>>* MathematicalFunction::execute(
		std::vector<std::vector<int>> *ops) {
	return ops;
}

std::vector<std::vector<int>>* MathematicalFunction::add(std::vector<int> *bin1,
		std::vector<int> *bin2) {
	int dim = bin1->size();
	int a = 0;
	int b = 0;
	int s = 0;
	int c = 0;

	std::vector<int> sum;
	std::vector<int> carry;

	std::vector<std::vector<int>> *result = new std::vector<std::vector<int>>();

	for (int i = 0; i < dim; i++) {
		a = bin1->at(i);
		b = bin2->at(i);
		s = ((a ^ b) ^ c);
		c = (a & b) | (c & (a ^ b));
		sum.push_back(s);
	}
	carry.push_back(c);

	result->push_back(sum);
	result->push_back(carry);

	return result;
}

std::vector<std::vector<int>>* MathematicalFunction::addc(std::vector<int> *bin1,
		std::vector<int> *bin2, int carryIn) {

	std::vector<int> sum;

	int a = 0;
	int b = 0;
	int s = 0;

	int c = carryIn;
	int dim = bin1->size();

	std::vector<int> carryOut;

	for (int i = 0; i < dim; i++) {
		a = bin1->at(i);
		b = bin2->at(i);
		s = (a ^ b) ^ c;
		sum.push_back(s);
		c = (a & b) | (c & (a ^ b));
	}

	carryOut.push_back(c);

	result->push_back(sum);
	result->push_back(carryOut);

	return result;

}

