/*
 * LogicBenchmark.cpp
 *
 *  Created on: 07.01.2023
 *      Author: roman
 */

#include "../../benchmarks/logical/LogicalBenchmark.h"


LogicalBenchmark::LogicalBenchmark(int p_bit_length) {

	if (p_bit_length > 0) {
		bitLength = p_bit_length;
	} else {
		throw std::invalid_argument("Number of bits must be greater zero!");
	}

}
