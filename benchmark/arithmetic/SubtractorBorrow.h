/*
 * SubtractorBorrow.h
 *
 *  Created on: 06.01.2023
 *      Author: roman
 */

#ifndef BENCHMARK_ARITHMETIC_SUBTRACTORBORROW_H_
#define BENCHMARK_ARITHMETIC_SUBTRACTORBORROW_H_

#include "../../function/arithmetic/ArithmeticFunction.h"
#include "../../function/arithmetic/SUBB.h"
#include "ArithmeticBenchmark.h"

class SubtractorBorrow : public ArithmeticBenchmark {
public:
	SubtractorBorrow(ArithmeticFunction *p_function, int p_bit_length);
	~SubtractorBorrow() = default;
	void build() override;
	void generateInputNames() override;
	void generateOutputNames() override;
};

#endif /* BENCHMARK_ARITHMETIC_SUBTRACTORBORROW_H_ */
