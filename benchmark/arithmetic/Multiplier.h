/*
 *  Class Multiplier implements the digital multiplier function.
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#ifndef BENCHMARK_MULTIPLIER_H_
#define BENCHMARK_MULTIPLIER_H_

#include "../../function/arithmetic/ArithmeticFunction.h"
#include "../../function/arithmetic/MUL.h"
#include "../Benchmark.h"
#include "ArithmeticBenchmark.h"

class Multiplier: public ArithmeticBenchmark {
public:
	Multiplier(ArithmeticFunction* p_function, int p_bits);
	virtual ~Multiplier() = default;
	void build() override;
	void generateInputNames() override;
	void generateOutputNames() override;
private:
	ArithmeticFunction* function;
};

#endif /* BENCHMARK_MULTIPLIER_H_ */
