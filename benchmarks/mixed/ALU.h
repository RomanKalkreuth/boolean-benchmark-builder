/*
 * 	Class ALU implements the arithmetic logic unit benchmark.
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
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

#include "../../benchmarks/Benchmark.h"
#include "../../function/Function.h"

class ALU : public Benchmark{
private:
	std::vector<Function*>* functions;

	int chunkSize;
	int opcodeBits;
	int numFunctions;
public:
	ALU(std::vector<Function*>* p_functions, int p_bit_length);
	virtual ~ALU();

	void generateInputNames();
	void generateOutputNames();
	void build();

};

#endif /* BENCHMARK_ALU_H_ */
