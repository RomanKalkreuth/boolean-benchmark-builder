/*
 * ALU.h
 *
 *  Created on: 09.12.2021
 *  Author: Roman Kalkreuth
 */

#ifndef BENCHMARK_ALU_H_
#define BENCHMARK_ALU_H_

#include <stdexcept>
#include <vector>
#include <cmath>

#include "Benchmark.h"
#include "../function/Function.h"


class ALU : public Benchmark{
public:
	ALU(std::vector<Function*>* p_functions, int p_bits);
	virtual ~ALU();

	std::vector<Function*>* functions;

	int bits;
	int chunk;
	int opcodes;
	int opcodesBits;

	void build();

};

#endif /* BENCHMARK_ALU_H_ */
