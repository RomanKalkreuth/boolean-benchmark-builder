/*
 * Benchmark.h
 *
 *  Created on: 09.12.2021
 *
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#ifndef BENCHMARK_BENCHMARK_H_
#define BENCHMARK_BENCHMARK_H_

#include "../table/TruthTable.h"

#include <vector>
#include <exception>
#include <iostream>


class Benchmark {
public:
	Benchmark();
	virtual ~Benchmark();

	TruthTable *table;
	std::vector<std::vector<int>>* ops;
	std::vector<std::vector<int>>* result;

	int inputs;
	int outputs;
	int bits;

	virtual void build() = 0;

	TruthTable* getTable();

};

#endif /* BENCHMARK_BENCHMARK_H_ */
