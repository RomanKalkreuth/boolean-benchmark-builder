/*
 * ArithmeticBenchmark.h
 *
 *  Created on: 09.12.2022
 *      Author: roman
 */

#ifndef BENCHMARK_ARITHMETIC_ARITHMETICBENCHMARK_H_
#define BENCHMARK_ARITHMETIC_ARITHMETICBENCHMARK_H_

#include "../Benchmark.h"
#include "../../function/arithmetic/ArithmeticFunction.h"

class ArithmeticBenchmark : public Benchmark {
public:
	ArithmeticBenchmark(ArithmeticFunction *p_function, int p_bit_length);
	ArithmeticBenchmark(int p_bit_length);
	virtual ~ArithmeticBenchmark();

protected:
	ArithmeticFunction* function;
};

#endif /* BENCHMARK_ARITHMETIC_ARITHMETICBENCHMARK_H_ */
