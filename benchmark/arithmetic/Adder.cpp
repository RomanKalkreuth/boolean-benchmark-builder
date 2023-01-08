/*
 *  Class Adder implements the digital adder function without carry.
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#include "Adder.h"

Adder::Adder(ArithmeticFunction *p_function, int p_bit_length) :
		ArithmeticBenchmark(p_function, p_bit_length) {

	if (typeid(*p_function) != typeid(ADD)) {
		throw std::invalid_argument("ADD function is required by this class!");
	}

	numInputs = bitLength * 2;
	numOutputs = bitLength + 1;

	generateInputNames();
	generateOutputNames();

	table = std::make_shared<TruthTable>(numInputs, numOutputs, inputNames, outputNames,
				separators);
}

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

void Adder::generateOutputNames() {
	outputNames->push_back("C");
	for (int i = bitLength - 1; i >= 0; i--) {
		outputNames->push_back("S" + std::to_string(i));
	}
}

void Adder::generateInputNames() {
	for (int i = bitLength - 1; i >= 0; i--) {
		inputNames->push_back("A" + std::to_string(i));
	}

	for (int i = bitLength - 1; i >= 0; i--) {
		inputNames->push_back("B" + std::to_string(i));
	}
}

