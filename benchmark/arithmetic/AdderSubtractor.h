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

class AdderSubtractor : Benchmark {
public:
	AdderSubtractor(ArithmeticFunction *p_function, int p_bit_length);
	virtual ~AdderSubtractor();
	void build();
	void generateInputNames();
	void generateOutputNames();
private:
	ArithmeticFunction* function;

};

#endif /* BENCHMARK_ADDERSUBTRACTOR_H_ */
