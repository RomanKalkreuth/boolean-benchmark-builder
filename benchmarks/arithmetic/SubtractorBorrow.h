/*
 * SubtractorBorrow.h
 *
 *  Created on: 06.01.2023
 *      Author: roman
 */

#ifndef BENCHMARKS_ARITHMETIC_SUBTRACTORBORROW_H_
#define BENCHMARKS_ARITHMETIC_SUBTRACTORBORROW_H_

#include "../../benchmarks/arithmetic/ArithmeticBenchmark.h"
#include "../../functions/arithmetic/ArithmeticFunction.h"
#include "../../functions/arithmetic/SUBB.h"

class SubtractorBorrow : public ArithmeticBenchmark {
public:
	SubtractorBorrow(ArithmeticFunction *p_function, int p_bit_length);
	~SubtractorBorrow() = default;
	void build() override;
	void generateInputNames() override;
	void generateOutputNames() override;
};

#endif /* BENCHMARKS_ARITHMETIC_SUBTRACTORBORROW_H_ */
