/*
 * Multiplier.h
 *
 *  Created on: 12.01.2022
 *      Author: roman
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
