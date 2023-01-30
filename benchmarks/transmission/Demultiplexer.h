/*
 * Demultiplexer.h
 *
 *  Created on: 07.01.2023
 *      Author: roman
 */

#ifndef BENCHMARKS_LOGICAL_COMBINATIONAL_DEMULTIPLEXER_H_
#define BENCHMARKS_LOGICAL_COMBINATIONAL_DEMULTIPLEXER_H_

#include <cmath>

#include "../LogicalBenchmark.h"
#include "../../util/Util.h"

class Demultiplexer : public LogicalBenchmark{
public:
	Demultiplexer(int p_bit_legth);
	virtual ~Demultiplexer() = default;
	void build() override;
	void generateInputNames() override;
	void generateOutputNames() override;
};

#endif /* BENCHMARKS_LOGICAL_COMBINATIONAL_DEMULTIPLEXER_H_ */
