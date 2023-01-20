/*
 * MagnitudeComparator.h
 *
 *  Created on: 09.01.2023
 *      Author: roman
 */

#ifndef BENCHMARKS_LOGICAL_COMPARATIVE_MAGNITUDECOMPARATOR_H_
#define BENCHMARKS_LOGICAL_COMPARATIVE_MAGNITUDECOMPARATOR_H_

#include "../../../benchmarks/logical/LogicalBenchmark.h"
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

#endif /* BENCHMARKS_LOGICAL_COMPARATIVE_MAGNITUDECOMPARATOR_H_ */
