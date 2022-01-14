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

Adder::Adder(MathematicalFunction *p_function, int p_bit_length) {

	if (p_bit_length > 0) {
		bitLength = p_bit_length;
	} else {
		throw std::invalid_argument("Number of bits must be greater zero!");
	}

	if (p_function != nullptr) {
		function = p_function;
	} else {
		throw std::invalid_argument("Function is NULL!");
	}

	inputs = bitLength * 2;
	outputs = bitLength + 1;

	std::vector<std::string>* inputNames = new std::vector<std::string>{"I2", "I1", "I0"};
	std::vector<std::string>* outputNames =  new std::vector<std::string>{ "S", "O2", "O1", "O0" };

	std::vector<int>* separators = new std::vector<int>{2};

	table = new TruthTable(inputs, outputs, inputNames, outputNames, separators);
}

Adder::~Adder() {
	delete function;
}

/**
 *
 */
void Adder::build() {

	std::vector<int> op1(bitLength);
	std::vector<int> op2(bitLength);

	std::vector<int> *sum;
	std::vector<int> *carry;

	int s = 0;
	int rows = table->getRows();
	int cols = table->getCols();

	int coutVal = 0;
	int coutPos = 2 * bitLength;

	int sumPos = coutPos + 1;

	for (int i = 0; i < rows; i++) {

		op1.clear();
		op2.clear();

		operands->clear();

		//TODO: Optimize loading of the operators

		for (int j = 0; j < bitLength; j++) {
			int val1 = table->at(i, j);
			int val2 = table->at(i, j + bitLength);
			op1.push_back(val1);
			op2.push_back(val2);
		}

		std::reverse(op1.begin(), op1.end());
		std::reverse(op2.begin(), op2.end());

		operands->push_back(op1);
		operands->push_back(op2);
		result = function->execute(operands);

		sum = &result->at(0);
		carry = &result->at(1);

		std::reverse(sum->begin(), sum->end());

		coutVal = carry->at(0);
			table->set(i, coutPos, coutVal);

		for (int j = 0; j < bitLength; j++) {
			s = sum->at(j);
			table->set(i, j + sumPos, s);
		}

	}

}

