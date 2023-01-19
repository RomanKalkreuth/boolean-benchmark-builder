/*
 * ArithmeticBenchmark.h
 *
 *  Created on: 09.12.2022
 *      Author: roman
 */

#ifndef BENCHMARKS_ARITHMETIC_ARITHMETICBENCHMARK_H_
#define BENCHMARKS_ARITHMETIC_ARITHMETICBENCHMARK_H_

#include "../../benchmarks/Benchmark.h"
#include "../../functions/arithmetic/ArithmeticFunction.h"

class ArithmeticBenchmark : public Benchmark {
public:
	ArithmeticBenchmark(ArithmeticFunction *p_function, int p_bit_length);
	virtual ~ArithmeticBenchmark();

protected:
	ArithmeticFunction* function;
};

#endif /* BENCHMARKS_ARITHMETIC_ARITHMETICBENCHMARK_H_ */
