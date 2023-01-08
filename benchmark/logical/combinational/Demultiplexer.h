/*
 * Demultiplexer.h
 *
 *  Created on: 07.01.2023
 *      Author: roman
 */

#ifndef BENCHMARK_LOGICAL_COMBINATIONAL_DEMULTIPLEXER_H_
#define BENCHMARK_LOGICAL_COMBINATIONAL_DEMULTIPLEXER_H_

#include <cmath>
#include "../../../util/Util.h"
#include "../LogicalBenchmark.h"

class Demultiplexer : public LogicalBenchmark{
public:
	Demultiplexer(int p_bit_legth);
	virtual ~Demultiplexer() = default;
	void build() override;
	void generateInputNames() override;
	void generateOutputNames() override;
};

#endif /* BENCHMARK_LOGICAL_COMBINATIONAL_DEMULTIPLEXER_H_ */
