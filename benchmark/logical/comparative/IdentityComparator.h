/*
 * Comparator.h
 *
 *  Created on: 07.01.2023
 *      Author: roman
 */

#ifndef BENCHMARK_LOGICAL_COMPARATIVE_IDENTITYCOMPARATOR_H_
#define BENCHMARK_LOGICAL_COMPARATIVE_IDENTITYCOMPARATOR_H_

#include "../LogicalBenchmark.h"
#include "../../../util/Util.h"

class IdentityComparator : public LogicalBenchmark {
private:
 	int numComparisons;
public:
	IdentityComparator(int bitLength);
	virtual ~IdentityComparator() = default;
	void build() override;
	void generateInputNames() override;
	void generateOutputNames() override;
};

#endif /* BENCHMARK_LOGICAL_COMPARATIVE_IDENTITYCOMPARATOR_H_ */
