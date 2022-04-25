/*
 *  Class Adder implements the digital adder function without carry.
 *
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#ifndef BENCHMARK_ADDERCARRY_H_
#define BENCHMARK_ADDERCARRY_H_

#include "../function/mathematical/MathematicalFunction.h"
#include "Benchmark.h"

class Adder: public Benchmark {
public:
	Adder(MathematicalFunction *p_function, int p_bits);
	virtual ~Adder();
	void build();
	void generateInputNames();
	void generateOutputNames();
private:
	MathematicalFunction* function;
};

#endif /* BENCHMARK_ADDERCARRY_H_ */
