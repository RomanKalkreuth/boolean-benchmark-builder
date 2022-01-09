/*
 * Benchmark.cpp
 *
 *  Created on: 09.12.2021
 *
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#include "Benchmark.h"

#include <iostream>

Benchmark::Benchmark() {
	ops = new std::vector<std::vector<int>>();
	result = new std::vector<std::vector<int>>();
}

Benchmark::~Benchmark() {
	delete table;
	delete ops;
	delete result;
}

TruthTable* Benchmark::getTable() {
	return table;
}

