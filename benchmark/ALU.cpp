/*
 * ALU.cpp
 *
 *  Created on: 09.12.2021
 *
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#include "ALU.h"

ALU::ALU(std::vector<Function*> *p_functions, int p_bits) {
	if (p_functions != nullptr) {
		functions = p_functions;
	} else {
		throw std::invalid_argument("Function set is NULL!");
	}

	if (p_bits > 0) {
		bits = p_bits;
	} else {
		throw std::invalid_argument("Bits must be greater than zero!");
	}

	opcodes = functions->size();
	opcodesBits = pow(2.0, opcodes);

	inputs = 2*bits + opcodesBits;
	outputs = bits + 1;

	std::vector<std::string>* inputNames = new std::vector<std::string>{"M2", "M1", "M0", "I2", "I1", "I0"};
	std::vector<std::string>* outputNames =  new std::vector<std::string>{ "S", "O2", "O1", "O0" };

	std::vector<int>* separators = new std::vector<int>{1,4,8};

	table = new TruthTable(inputs, outputs, inputNames, outputNames, separators);

	chunk = table->getRows() / opcodes;
}

ALU::~ALU() {
	delete functions;
}

/**
 *
 */
void ALU::build() {

	int offset = opcodesBits;

	std::vector<int> op1;
	std::vector<int> op2;

	int rows = table->getRows();
	int cols = table->getCols();
	int index = 0;

	int coutVal = 0;
	int coutPos = 2 * bits;

	int sumPos = coutPos + 1;

	Function *function;

	for (int i = 0; i < rows; i++) {

		op1.clear();
		op2.clear();
		ops->clear();

		//TODO: Optimize loading of the operators

		for (int j = 0; j < bits; j++) {
			int val1 = table->at(i, j);
			int val2 = table->at(i, j + bits);
			op1.push_back(val1);
			op2.push_back(val2);
		}

		std::reverse(op1.begin(), op1.end());
		std::reverse(op2.begin(), op2.end());

		ops->push_back(op1);
		ops->push_back(op2);

		ops->push_back(op1);
		ops->push_back(op2);

		if (i % chunk == 1) {
			index++;
			function = functions->at(index);
			result = function->execute(ops);
		}


	}


}

