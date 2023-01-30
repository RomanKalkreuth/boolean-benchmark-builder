/*
 *  Class Adder implements the digital adder function without carry.
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#ifndef BENCHMARK_ADDER_H_
#define BENCHMARK_ADDER_H_

#include "../../benchmarks/arithmetic/ArithmeticBenchmark.h"
#include "../../functions/arithmetic/ArithmeticFunction.h"
#include "../../functions/arithmetic/ADD.h"
#include "../Benchmark.h"

class Adder: public ArithmeticBenchmark {
public:
	Adder(ArithmeticFunction *p_function, int p_bit_length);
	~Adder() = default;
	void build() override;
	void generateInputNames() override;
	void generateOutputNames() override;
};

#endif /* BENCHMARK_ADDERCARRY_H_ */
