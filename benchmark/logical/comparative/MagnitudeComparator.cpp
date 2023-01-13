/*
 * MagnitudeComparator.cpp
 *
 *  Created on: 09.01.2023
 *      Author: roman
 */

#include "MagnitudeComparator.h"

MagnitudeComparator::MagnitudeComparator(int bitLength) :
		LogicalBenchmark(bitLength) {
	numInputs = bitLength * 2;
	numComparisons = 3;
	numOutputs = numComparisons;

	generateInputNames();
	generateOutputNames();

	table = std::make_shared<TruthTable>(numInputs, numOutputs, inputNames,
			outputNames, separators);

}

void MagnitudeComparator::build() {

	std::vector<int> op1(bitLength);
	std::vector<int> op2(bitLength);

	int numRows = table->getRows();
	int outputIndex = 2 * bitLength;

	int lt = 0;
	int eq = 1;
	int gt = 2;

	int caseOffset = 0;
	int comparisonOffset = 0;

	for (int i = 0; i < numRows; i++) {

		op1.clear();
		op2.clear();

		operands->clear();

		for (int j = 0; j < bitLength; j++) {
			int value1 = table->at(i, j);
			int value2 = table->at(i, j + bitLength);
			op1.push_back(value1);
			op2.push_back(value2);
		}

		std::reverse(op1.begin(), op1.end());
		std::reverse(op2.begin(), op2.end());

		int dec1 = Util::binToInt(op1);
		int dec2 = Util::binToInt(op2);

		if(dec1 < dec2) {
			caseOffset = lt;
		} else if (dec1 > dec2) {
			caseOffset = gt;
		} else {
			caseOffset = eq;
		}

		table->set(i, outputIndex  + caseOffset, 1);
	}

}

void MagnitudeComparator::generateOutputNames() {

}

void MagnitudeComparator::generateInputNames() {

}

