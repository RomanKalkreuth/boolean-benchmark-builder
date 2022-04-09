/*
 * Adder.cpp
 *
 *  Created on: 06.01.2022
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#include "AdderCarry.h"

AdderCarry::AdderCarry(int p_bits, MathematicalFunction* p_function) {

	if (p_bits > 0 ){
		bitLength = p_bits;
	} else {
		throw std::invalid_argument("Number of bits must be greater zero!");
	}

	if (p_function != nullptr) {
		function = p_function;
	} else {
		throw std::invalid_argument("Function is NULL!");
	}

	inputs = bitLength * 2 + 1;
	outputs = bitLength + 1;

	function = p_function;

	table = new TruthTable(inputs, outputs);
}

AdderCarry::~AdderCarry() {
	delete function;
}

/**
 *
 */
void AdderCarry::build() {

	std::vector<int> op1;
	std::vector<int> op2;
	std::vector<int> op3;

	std::vector<int> *sum;
	std::vector<int> *carry;

	int s = 0;
	int rows = table->getRows();
	int cols = table->getCols();

	int cinVal = 0;
	int coutVal = 0;

	int cinPos = 2 * bitLength;
	int coutPos = cols - 1;

	int outputPos = 2 * bitLength + 1;

	for (int i = 0; i < rows; i++) {

		op1.clear();
		op2.clear();
		op3.clear();

		operands->clear();

		for (int j = 0; j < bitLength; j++) {
			int val1 = table->at(i, j);
			int val2 = table->at(i, j + bitLength);
			op1.push_back(val1);
			op2.push_back(val2);
		}

		cinVal = table->at(i, cinPos);
		op3.push_back(cinVal);

		operands->push_back(op1);
		operands->push_back(op2);
		operands->push_back(op3);

		result = function->execute(operands);

		sum = &result->at(0);
		carry = &result->at(1);

		for (int j = 0; j < bitLength; j++) {
			s = sum->at(j);
			table->set(i, j + outputPos, s);
		}

		coutVal = carry->at(0);
		table->set(i, coutPos, coutVal);
	}

}

