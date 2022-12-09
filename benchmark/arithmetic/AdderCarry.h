/*
 *  Class AdderCarry implements the digital adder function with carry.
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#ifndef BENCHMARK_ADDERCARRY_H_
#define BENCHMARK_ADDERCARRY_H_

#include "../../function/arithmetic/ArithmeticFunction.h"
#include "../Benchmark.h"
#include "ArithmeticBenchmark.h"

class AdderCarry : public ArithmeticBenchmark {
public:
	AdderCarry(ArithmeticFunction* p_function, int p_bits);
	void generateInputNames();
	void generateOutputNames();
	void build();

private:
	ArithmeticFunction* function;
};

#endif /* BENCHMARK_ADDERCARRY_H_ */
