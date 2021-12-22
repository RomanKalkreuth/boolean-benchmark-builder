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

#include "Benchmark.h"
#include "../function/Function.h"


class ALU : public Benchmark{
public:
	ALU(std::vector<Function>* function_set);
	virtual ~ALU();

	std::vector<Function>* functions;

	int opcodes;
	int opcodesBits;
	int opcode = 0;
};

#endif /* BENCHMARK_ALU_H_ */
