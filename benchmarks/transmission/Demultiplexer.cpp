/*
 * Demultiplexer.cpp
 *
 *  Created on: 07.01.2023
 *      Author: roman
 */

#include "../../../benchmarks/logical/combinational/Demultiplexer.h"

Demultiplexer::Demultiplexer(int p_bit_legth) : LogicalBenchmark(p_bit_legth) {

	float lg2 = std::log2(bitLength);

	if (std::fmod(lg2, 1) != 0) {
		throw std::invalid_argument("Bit length must be a power of two!");
	}

	numInputs = lg2 + 1;
	numOutputs = bitLength;

	generateInputNames();
	generateOutputNames();

	table = std::make_shared<TruthTable>(numInputs, numOutputs, inputNames, outputNames,
			separators);
}

void Demultiplexer::build() {

	int rows = table->getRows();

	int inputIndex = numInputs - 1;
	int outputIndex;

	int inputValue;
	int outputValue;

	std::vector<int> bin;

	for (int i = 0; i < rows; i++) {

		bin.clear();

		for (int j = 0; j < numInputs - 1; j++) {
			int b = table->at(i,j);
			bin.push_back(b);
		}

		std::reverse(bin.begin(), bin.end());

		outputValue = Util::binToInt(bin);
		inputValue = table->at(i, inputIndex);

		outputIndex = inputIndex + outputValue + 1;

		table->set(i, outputIndex, inputValue);
	}
}

void Demultiplexer::generateOutputNames() {
	for (int i = bitLength - 1; i >= 0; i--) {
		outputNames->push_back("Y" + std::to_string(i));
	}
}

void Demultiplexer::generateInputNames() {
	for (int i = numInputs - 1; i >= 0; i--) {
		inputNames->push_back("S" + std::to_string(i));
	}

	inputNames->push_back("I");
}

