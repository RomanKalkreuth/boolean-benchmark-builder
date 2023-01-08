/*
 * Comparator.cpp
 *
 *  Created on: 07.01.2023
 *      Author: roman
 */

#include "Comparator.h"

Comparator::Comparator(int bitLength) :
		LogicalBenchmark(bitLength) {
	numInputs = bitLength;

	this->numComparisons = 3;

	int totalComparisions = Util::binomCoeff(numInputs, 2) * numComparisons;

	numOutputs = totalComparisions;

	generateInputNames();
	generateOutputNames();

	table = std::make_shared<TruthTable>(numInputs, numOutputs, inputNames,
			outputNames, separators);

}

void Comparator::build() {

	int rows = table->getRows();

	int outputStartIndex = numInputs;

	int lt = 0;
	int eq = 1;
	int gt = 2;

	std::vector<int> bin;

	int currentComparisonIndex = 0;
	int comparisonOffset = 0;
	int caseOffset = 0;

	for (int i = 0; i < outputStartIndex - 1; i++) {
		for (int j = i + 1; j < outputStartIndex; j++) {
			for (int z = 0; z < rows; z++) {

				currentComparisonIndex = outputStartIndex + comparisonOffset;

				int a = table->at(z, i);
				int b = table->at(z, j);

				if (a < b) {
					caseOffset = lt;
				} else if (a == b) {
					caseOffset = eq;
				} else if (a > b) {
					caseOffset = gt;
				}

				table->set(z, currentComparisonIndex + caseOffset, 1);
			}
			comparisonOffset = j * this->numComparisons;
		}
	}

}

void Comparator::generateOutputNames() {

}

void Comparator::generateInputNames() {

}

