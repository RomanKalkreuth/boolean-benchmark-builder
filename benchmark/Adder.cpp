/*
 * Adder.cpp
 *
 *  Created on: 06.01.2022
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#include "Adder.h"
#include <iostream>

Adder::Adder(int p_bits) {
	bits = p_bits;
	inputs = bits * 2 + 1;
	outputs = bits + 1;

	table = new TruthTable(inputs, outputs);
	add = new ADDC();
}

Adder::~Adder() {
	delete add;
}

/**
 *
 */
void Adder::build() {

	std::vector<int> op1;
	std::vector<int> op2;
	std::vector<int> op3;

	std::vector<int> *sum;
	std::vector<int> *carry;

	int s = 0;
	int rows = table->getRows();
	int cols = table->getCols();

	int cinVal = 0;
	int coutVal = 0;

	int cinPos = 2 * bits;
	int coutPos = cols - 1;

	int outputPos = 2 * bits + 1;

	for (int i = 0; i < rows; i++) {

		op1.clear();
		op2.clear();
		op3.clear();

		ops->clear();

		for (int j = 0; j < bits; j++) {
			int val1 = table->at(i, j);
			int val2 = table->at(i, j + bits);
			op1.push_back(val1);
			op2.push_back(val2);
		}

		cinVal = table->at(i, cinPos);
		op3.push_back(cinVal);

		ops->push_back(op1);
		ops->push_back(op2);
		ops->push_back(op3);

		result = add->execute(ops);

		sum = &result->at(0);
		carry = &result->at(1);

		for (int j = 0; j < bits; j++) {
			s = sum->at(j);
			table->set(i, j + outputPos, s);
		}

		coutVal = carry->at(0);
		table->set(i, coutPos, coutVal);
	}

}

