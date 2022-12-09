/*
 * 	Class AdderSubtractor implements the digital adder-subtractor function.
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#include "AdderSubtractor.h"

AdderSubtractor::AdderSubtractor(ArithmeticFunction *p_function, int p_bit_length) {
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

	std::vector<int>* separators = new std::vector<int>{2};

	table = new TruthTable(inputs, outputs, inputNames, outputNames, separators);

}

void AdderSubtractor::build() {

}

void AdderSubtractor::generateOutputNames() {
}

void AdderSubtractor::generateInputNames() {

}

AdderSubtractor::~AdderSubtractor() {
	delete function;
}

