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

#ifndef BENCHMARK_ADDER_H_
#define BENCHMARK_ADDER_H_

#include "Benchmark.h"
#include "../function/mathematical/ADD.h"

class Adder: public Benchmark {
public:
	Adder(int p_bits);
	virtual ~Adder();
	void build();

private:
	ADD* add;
};

#endif /* BENCHMARK_ADDER_H_ */
