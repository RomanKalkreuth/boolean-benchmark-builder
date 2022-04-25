/*
 *  Class Multiplier implements the digital multiplier function.
 *
 *  Created on: 06.01.2022
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#ifndef BENCHMARK_MULTIPLIER_H_
#define BENCHMARK_MULTIPLIER_H_

#include "Benchmark.h"
#include "../function/mathematical/MUL.h"

class Multiplier: public Benchmark {
public:
	Multiplier();
	virtual ~Multiplier();
	void build();
private:
	MUL* mul;
};

#endif /* BENCHMARK_MULTIPLIER_H_ */
