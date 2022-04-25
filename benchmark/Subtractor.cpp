/*
 *  Class Subtractor implements the digital subtractor function.
 *
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#include "Subtractor.h"

Subtractor::Subtractor(MathematicalFunction *p_function, int p_bit_length) {
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

	table = new TruthTable(inputs, outputs);
	sub = new SUB();

}

Subtractor::~Subtractor() {
}


void Subtractor::build() {

}
