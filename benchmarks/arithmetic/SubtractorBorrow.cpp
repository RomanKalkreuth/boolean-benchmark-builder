/*
 * SubtractorBorrow.cpp
 *
 *  Created on: 06.01.2023
 *      Author: roman
 */

#include "../../benchmarks/arithmetic/SubtractorBorrow.h"

SubtractorBorrow::SubtractorBorrow(ArithmeticFunction *p_function,
		int p_bit_length) : ArithmeticBenchmark(p_function, p_bit_length){

	if (typeid(*p_function) != typeid(SUBB)) {
		throw std::invalid_argument("SUBB function is required by this class!");
	}

	numInputs = bitLength * 2 + 1;
	numOutputs = bitLength + 1;

	generateInputNames();
	generateOutputNames();

	table = std::make_shared<TruthTable>(numInputs, numOutputs, inputNames, outputNames,
				separators);
}

void SubtractorBorrow::build() {

	std::vector<int> op1;
	std::vector<int> op2;
	std::vector<int> op3;

	std::vector<int> *diff;
	std::vector<int> *borrow;

	int s = 0;
	int rows = table->getRows();
	int cols = table->getCols();

	int binVal = 0;
	int boutVal = 0;

	int binPos = 2 * bitLength;
	int boutPos = cols - 1;

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

		std::reverse(op1.begin(), op1.end());
		std::reverse(op2.begin(), op2.end());

		binVal = table->at(i, binPos);
		op3.push_back(binVal);

		operands->push_back(op1);
		operands->push_back(op2);
		operands->push_back(op3);

		result = function->execute(operands);

		diff = &result->at(0);
		borrow = &result->at(1);

		std::reverse(diff->begin(), diff->end());

		for (int j = 0; j < bitLength; j++) {
			s = diff->at(j);
			table->set(i, j + outputPos, s);
		}

		boutVal = borrow->at(0);
		table->set(i, boutPos, boutVal);
	}

}

void SubtractorBorrow::generateOutputNames() {
	for (int i = bitLength - 1; i >= 0; i--) {
		outputNames->push_back("S" + std::to_string(i));
	}
	outputNames->push_back("Bo");
}

void SubtractorBorrow::generateInputNames() {

	for (int i = bitLength - 1; i >= 0; i--) {
		inputNames->push_back("A" + std::to_string(i));
	}

	for (int i = bitLength - 1; i >= 0; i--) {
		inputNames->push_back("B" + std::to_string(i));
	}
	inputNames->push_back("Bi");
}


