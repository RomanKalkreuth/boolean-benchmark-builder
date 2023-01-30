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

#include "../../benchmarks/arithmetic/ArithmeticBenchmark.h"
#include "../../benchmarks/Benchmark.h"
#include "../../functions/arithmetic/ArithmeticFunction.h"
#include "../../functions/arithmetic/ADDC.h"

class AdderCarry : public ArithmeticBenchmark {
public:
	AdderCarry(ArithmeticFunction* p_function, int p_bits);
	~AdderCarry() = default;
	void build() override;
	void generateInputNames() override;
	void generateOutputNames() override;
};

#endif /* BENCHMARK_ADDERCARRY_H_ */
