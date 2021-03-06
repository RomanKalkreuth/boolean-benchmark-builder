/*
 * 	Class ALU implements the arithmetic logic unit benchmark.
 *
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#ifndef BENCHMARK_ALU_H_
#define BENCHMARK_ALU_H_

#include <stdexcept>
#include <vector>
#include <cmath>
#include <string>
#include <stack>
#include <algorithm>

#include "Benchmark.h"
#include "../function/Function.h"

class ALU : public Benchmark{
public:
	ALU(std::vector<Function*>* p_functions, int p_bit_length);
	virtual ~ALU();

	std::vector<Function*>* functions;

	int chunkSize;
	int opcodeBits;
	int numFunctions;

	void generateInputNames();
	void generateOutputNames();
	void build();

};

#endif /* BENCHMARK_ALU_H_ */
