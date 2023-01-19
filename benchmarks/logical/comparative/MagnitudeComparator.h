/*
 * MagnitudeComparator.h
 *
 *  Created on: 09.01.2023
 *      Author: roman
 */

#ifndef BENCHMARK_LOGICAL_COMPARATIVE_MAGNITUDECOMPARATOR_H_
#define BENCHMARK_LOGICAL_COMPARATIVE_MAGNITUDECOMPARATOR_H_

#include "../LogicalBenchmark.h"
#include "../../../util/Util.h"

class MagnitudeComparator : public LogicalBenchmark {
private:
 	int numComparisons;
public:
	MagnitudeComparator(int bitLength);
	virtual ~MagnitudeComparator() = default;
	void build() override;
	void generateInputNames() override;
	void generateOutputNames() override;
};

#endif /* BENCHMARK_LOGICAL_COMPARATIVE_MAGNITUDECOMPARATOR_H_ */
