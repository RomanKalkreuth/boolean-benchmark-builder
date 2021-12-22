/*
 * Benchmark.h
 *
 *  Created on: 09.12.2021
 *  Author: Roman Kalkreuth
 */

#ifndef BENCHMARK_BENCHMARK_H_
#define BENCHMARK_BENCHMARK_H_

#include "../table/TruthTable.h"

class Benchmark {
public:
	Benchmark();
	virtual ~Benchmark();

	TruthTable *table;

	int inputs;
	int outputs;

	virtual void build() = 0;

};

#endif /* BENCHMARK_BENCHMARK_H_ */
