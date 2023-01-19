/*
 * 	Class AdderSubtractor implements the digital adder-subtractor function.
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#include "../../benchmarks/arithmetic/AdderSubtractor.h"

#include "../../functions/arithmetic/complement/Complement.h"

AdderSubtractor::AdderSubtractor(ArithmeticFunction *p_function,
		int p_bit_length) :
		ArithmeticBenchmark(p_function, p_bit_length) {

	numInputs = bitLength * 2 + 1;
	numOutputs = bitLength + 1;

	generateInputNames();
	generateOutputNames();

	table = std::make_shared<TruthTable>(numInputs, numOutputs, inputNames, outputNames,
				separators);
}

void AdderSubtractor::build() {

	int rows = table->getRows();

	int r = 0;

	int inputPos = 1;
	int statusPos = 2 * bitLength + 1;
	int resPos = statusPos + 1;

	int statusVal = 0;
	int cinVal = 0;

	std::vector<int> op1;
	std::vector<int> op2;
	std::vector<int> op3;

	std::vector<int> *res;
	std::vector<int> *status;

	for (int i = 0; i < rows; i++) {

		op1.clear();
		op2.clear();
		op3.clear();
		operands->clear();

		int m = table->at(i, 0);

		for (int j = 0; j < bitLength; j++) {
			int val1 = table->at(i, inputPos + j);
			int val2 = table->at(i, inputPos + bitLength + j);

			val2 = m ^ val2;

			op1.push_back(val1);
			op2.push_back(val2);
		}

		std::reverse(op1.begin(), op1.end());
		std::reverse(op2.begin(), op2.end());

		cinVal = m;
		op3.push_back(cinVal);

		operands->push_back(op1);
		operands->push_back(op2);
		operands->push_back(op3);

		result = function->execute(operands);

		res = &result->at(0);

		std::reverse(res->begin(), res->end());

		for (int j = 0; j < bitLength; j++) {
			r = res->at(j);
			table->set(i, j + resPos, r);
		}

		if (result->size() > 1) {
			status = &result->at(1);
			statusVal = status->at(0);
			table->set(i, statusPos, statusVal);
		}

	}

}

void AdderSubtractor::generateOutputNames() {

	outputNames->push_back("S");

	for (int i = bitLength - 1; i >= 0; i--) {
		outputNames->push_back("O" + std::to_string(i));
	}

}

void AdderSubtractor::generateInputNames() {

	inputNames->push_back("M");

	for (int i = bitLength - 1; i >= 0; i--) {
		inputNames->push_back("A" + std::to_string(i));
	}

	for (int i = bitLength - 1; i >= 0; i--) {
		inputNames->push_back("B" + std::to_string(i));
	}
}

