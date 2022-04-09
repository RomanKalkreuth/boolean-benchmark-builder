/*
 *  Adder.h
 *
 *  Created on: 06.01.2022
 *
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#ifndef BENCHMARK_ADDERCARRY_H_
#define BENCHMARK_ADDERCARRY_H_

#include "../function/mathematical/ADDC.h"
#include "../function/mathematical/MathematicalFunction.h"
#include "Benchmark.h"

class AdderCarry : public Benchmark {
public:
	AdderCarry(int p_bits, MathematicalFunction* p_function);
	virtual ~AdderCarry();
	void build();

private:
	MathematicalFunction* function;
};

#endif /* BENCHMARK_ADDERCARRY_H_ */
