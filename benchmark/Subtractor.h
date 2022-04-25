/*
 *  Class Subtractor implements the digital subtractor function.
 *
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
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
