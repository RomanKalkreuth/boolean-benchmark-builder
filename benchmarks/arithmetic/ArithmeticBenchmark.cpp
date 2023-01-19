/*
 * ArithmeticBenchmark.cpp
 *
 *  Created on: 09.12.2022
 *      Author: roman
 */

#include "../../benchmarks/arithmetic/ArithmeticBenchmark.h"

ArithmeticBenchmark::ArithmeticBenchmark(ArithmeticFunction *p_function,
		int p_bit_length) {

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

}

ArithmeticBenchmark::~ArithmeticBenchmark() {
	delete function;
}

