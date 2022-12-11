/*
 *  Class Subtractor implements the digital subtractor function.
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#include "Subtractor.h"

Subtractor::Subtractor(ArithmeticFunction *p_function, int p_bit_length) :
ArithmeticBenchmark(p_function, p_bit_length) {

	if (typeid(*p_function) != typeid(SUB)) {
		throw std::invalid_argument("SUB function is required by this class!");
	}

	inputs = bitLength * 2;
	outputs = bitLength + 1;

	generateInputNames();
	generateOutputNames();

	std::vector<int> *separators = new std::vector<int> { 2 };

	table = new TruthTable(inputs, outputs, inputNames, outputNames,
			separators);

}

void Subtractor::build() {

	std::vector<int> op1(bitLength);
	std::vector<int> op2(bitLength);

	std::vector<int> *diff;
	std::vector<int> *borrow;

	int d = 0;

	int rows = table->getRows();
	int cols = table->getCols();

	int diffPos = 2 * bitLength;

	int boutVal = 0;
	int boutPos = 2 * bitLength;

	for (int i = 0; i < rows; i++) {

		op1.clear();
		op2.clear();

		operands->clear();

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

		diff = &result->at(0);
		borrow = &result->at(1);

		std::reverse(diff->begin(), diff->end());

		boutVal = borrow->at(0);
		table->set(i, boutPos, boutVal);

		for (int j = 0; j < bitLength; j++) {
			d = diff->at(j);
			table->set(i, j + diffPos, d);
		}

	}

}

void Subtractor::generateOutputNames() {
	for (int i = bitLength - 1; i >= 0; i--) {
		outputNames->push_back("D" + std::to_string(i));
	}
	outputNames->push_back("Bo");
}

void Subtractor::generateInputNames() {

	for (int i = bitLength - 1; i >= 0; i--) {
		inputNames->push_back("A" + std::to_string(i));
	}

	for (int i = bitLength - 1; i >= 0; i--) {
		inputNames->push_back("B" + std::to_string(i));
	}
}
