/*
 * LogicBenchmark.h
 *
 *  Created on: 07.01.2023
 *      Author: roman
 */

#ifndef BENCHMARK_LOGICAL_LOGICALBENCHMARK_H_
#define BENCHMARK_LOGICAL_LOGICALBENCHMARK_H_

#include "../Benchmark.h"

class LogicalBenchmark : public Benchmark {
public:
	LogicalBenchmark() = default;
	LogicalBenchmark(int p_bit_length);
	virtual ~LogicalBenchmark() = default;
};

#endif /* BENCHMARK_LOGICAL_LOGICALBENCHMARK_H_ */
