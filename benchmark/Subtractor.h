/*
 * Subtractor.h
 *
 *  Created on: 10.01.2022
 *      Author: roman
 */

#ifndef BENCHMARK_SUBTRACTOR_H_
#define BENCHMARK_SUBTRACTOR_H_
#include "Benchmark.h"
#include "../function/mathematical/MathematicalFunction.h"
#include "../function/mathematical/SUB.h"

class Subtractor: public Benchmark {
public:
	Subtractor(MathematicalFunction *p_function, int p_bit_length);
	virtual ~Subtractor();
	void build();
private:
	MathematicalFunction* function;
	SUB* sub;
};

#endif /* BENCHMARK_SUBTRACTOR_H_ */
