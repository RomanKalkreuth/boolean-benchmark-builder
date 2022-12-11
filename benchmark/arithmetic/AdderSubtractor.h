/*
 * 	Class AdderSubtractor implements the digital adder-subtractor function.
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#ifndef BENCHMARK_ADDERSUBTRACTOR_H_
#define BENCHMARK_ADDERSUBTRACTOR_H_

#include "../../function/arithmetic/ArithmeticFunction.h"
#include "../Benchmark.h"
#include "ArithmeticBenchmark.h"


class AdderSubtractor : ArithmeticBenchmark {
public:
	AdderSubtractor(ArithmeticFunction *p_function, int p_bit_length);
	void build() override;
	void generateInputNames() override;
	void generateOutputNames() override;
private:
	ArithmeticFunction* function;

};

#endif /* BENCHMARK_ADDERSUBTRACTOR_H_ */
