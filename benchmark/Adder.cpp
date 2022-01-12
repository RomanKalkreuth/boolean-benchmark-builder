/*
 * Adder.cpp
 *
 *  Created on: 06.01.2022
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#include "Adder.h"

Adder::Adder(int p_bits, MathematicalFunction *p_function) {

	if (p_bits > 0) {
		bits = p_bits;
	} else {
		throw std::invalid_argument("Number of bits must be greater zero!");
	}

	if (p_function != nullptr) {
		function = p_function;
	} else {
		throw std::invalid_argument("Function is NULL!");
	}

	inputs = bits * 2;
	outputs = bits + 1;

	function = p_function;

	table = new TruthTable(inputs, outputs);
}

Adder::~Adder() {
	delete function;
}

/**
 *
 */
void Adder::build() {

	std::vector<int> op1(bits);
	std::vector<int> op2(bits);
	std::vector<int> op3;

	std::vector<int> *sum;
	std::vector<int> *carry;

	int s = 0;
	int rows = table->getRows();
	int cols = table->getCols();

	int coutVal = 0;
	int coutPos = 2 * bits;

	int sumPos = coutPos + 1;

	for (int i = 0; i < rows; i++) {

		op1.clear();
		op2.clear();
		op3.clear();

		ops->clear();

		for (int j = 0; j < bits; j++) {
			int val1 = table->at(i, j);
			int val2 = table->at(i, j + bits);
			op1.push_back(val1);
			op2.push_back(val2);
		}

		std::reverse(op1.begin(), op1.end());
		std::reverse(op2.begin(), op2.end());

		ops->push_back(op1);
		ops->push_back(op2);
		result = function->execute(ops);

		sum = &result->at(0);
		carry = &result->at(1);

		std::reverse(sum->begin(), sum->end());

		coutVal = carry->at(0);
			table->set(i, coutPos, coutVal);

		for (int j = 0; j < bits; j++) {
			s = sum->at(j);
			table->set(i, j + sumPos, s);
		}

	}

}

