/*
 *  Class Multiplier implements the digital multiplier function.
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#include "../../benchmarks/arithmetic/Multiplier.h"

Multiplier::Multiplier(ArithmeticFunction *p_function, int p_bit_length) :
		ArithmeticBenchmark(p_function, p_bit_length) {

	if (typeid(*p_function) != typeid(MUL)) {
			throw std::invalid_argument("MUL function is required by this class!");
	}

}

void Multiplier::build() {

}

void Multiplier::generateOutputNames() {
	for (int i = bitLength - 1; i >= 0; i--) {
		outputNames->push_back("C" + std::to_string(i));
	}
}

void Multiplier::generateInputNames() {

	for (int i = bitLength - 1; i >= 0; i--) {
		inputNames->push_back("A" + std::to_string(i));
	}

	for (int i = bitLength - 1; i >= 0; i--) {
		inputNames->push_back("B" + std::to_string(i));
	}

}

