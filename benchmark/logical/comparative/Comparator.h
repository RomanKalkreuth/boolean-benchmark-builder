/*
 * Comparator.h
 *
 *  Created on: 07.01.2023
 *      Author: roman
 */

#ifndef BENCHMARK_LOGICAL_COMPARATIVE_COMPARATOR_H_
#define BENCHMARK_LOGICAL_COMPARATIVE_COMPARATOR_H_

#include "../LogicalBenchmark.h"
#include "../../../util/Util.h"

class Comparator : public LogicalBenchmark {
private:
 	int numComparisons;
public:
	Comparator(int bitLength);
	virtual ~Comparator() = default;
	void build() override;
	void generateInputNames() override;
	void generateOutputNames() override;
};

#endif /* BENCHMARK_LOGICAL_COMPARATIVE_COMPARATOR_H_ */
