/*
 * 	Base class for the implementation of Boolean functions.
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#include "Benchmark.h"

Benchmark::Benchmark() {
	operands = new std::vector<std::vector<int>>();
	inputNames = new std::vector<std::string>();
	outputNames = new std::vector<std::string>();
	separators = std::make_shared<std::vector<int>>();
}

Benchmark::~Benchmark() {
	delete operands;
	delete inputNames;
	delete outputNames;
}

int Benchmark::getNumOutputs() const {
	return numOutputs;
}

int Benchmark::getNumInputs() const {
	return numInputs;
}

std::shared_ptr<TruthTable> Benchmark::getTable() {
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

