/*
 * Comparator.h
 *
 *  Created on: 07.01.2023
 *      Author: roman
 */

#ifndef BENCHMARKS_LOGICAL_COMPARATIVE_IDENTITYCOMPARATOR_H_
#define BENCHMARKS_LOGICAL_COMPARATIVE_IDENTITYCOMPARATOR_H_

#include "..//LogicalBenchmark.h"
#include "../../../util/Util.h"

class IdentityComparator : public LogicalBenchmark {
private:
 	int numComparisons;
public:
	IdentityComparator(int bitLength);
	virtual ~IdentityComparator() = default;
	void build() override;
};

#endif /* BENCHMARKS_LOGICAL_COMPARATIVE_IDENTITYCOMPARATOR_H_ */
