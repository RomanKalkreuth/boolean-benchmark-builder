/*
 * Benchmark.cpp
 *
 *  Created on: 09.12.2021
 *  Author: Roman Kalkreuth
 */

#include "Benchmark.h"

Benchmark::Benchmark() {
	table = new TruthTable(inputs,outputs);

}

Benchmark::~Benchmark() {
	delete table;
}

