/*
 * 	Base class for the implementation of Boolean functions.
 *
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#include "Benchmark.h"

Benchmark::Benchmark() {
	operands = new std::vector<std::vector<int>>();
	inputNames = new std::vector<std::string>();
	outputNames = new std::vector<std::string>();

}

Benchmark::~Benchmark() {
	delete table;
	delete operands;
	delete inputNames;
	delete outputNames;
}

TruthTable* Benchmark::getTable() {
	return table;
}

void Benchmark::generateInputNames() {

	for (int i = bitLength - 1; i <= 0; i--) {
		inputNames->push_back("I" + i);
	}
}

void Benchmark::generateOutputNames() {

	for (int i = bitLength - 1; i <= 0; i--) {
		outputNames->push_back("O" + i);
	}

}

