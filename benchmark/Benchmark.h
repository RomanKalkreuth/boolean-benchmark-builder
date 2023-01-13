/*
 * 	Base class for the implementation of Boolean functions.
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#ifndef BENCHMARK_BENCHMARK_H_
#define BENCHMARK_BENCHMARK_H_

#include "../table/TruthTable.h"

#include <vector>
#include <exception>
#include <iostream>
#include <memory>

class Benchmark {
protected:
	virtual void generateInputNames();
	virtual void generateOutputNames();

	std::shared_ptr<TruthTable> table;
	std::vector<std::vector<int>> *operands;
	std::vector<std::vector<int>> *result;

	std::vector<std::string> *inputNames;
	std::vector<std::string> *outputNames;

	int numInputs;
	int numOutputs;
	int bitLength;

	std::shared_ptr<std::vector<int>> separators;

public:
	Benchmark();
	virtual ~Benchmark();

	// Function for the construction of the truth table
	// of the respective function.
	virtual void build() = 0;
	std::shared_ptr<TruthTable> getTable();
	int getNumInputs() const;
	int getNumOutputs() const;
};

#endif /* BENCHMARK_BENCHMARK_H_ */
