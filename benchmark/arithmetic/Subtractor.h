/*
 *  Class Subtractor implements the digital subtractor function.
 *
  *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */
#ifndef BENCHMARK_SUBTRACTOR_H_
#define BENCHMARK_SUBTRACTOR_H_

#include "../../function/arithmetic/ArithmeticFunction.h"
#include "../../function/arithmetic/SUB.h"
#include "../Benchmark.h"
#include "ArithmeticBenchmark.h"

class Subtractor : public ArithmeticBenchmark {
public:
	Subtractor(ArithmeticFunction *p_function, int p_bit_length);
	~Subtractor() = default;
	void build() override;
	void generateInputNames() override;
	void generateOutputNames() override;
};

#endif /* BENCHMARK_SUBTRACTOR_H_ */
