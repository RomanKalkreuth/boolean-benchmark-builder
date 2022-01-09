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
		this->functions = p_functions;
	} else {
		throw std::invalid_argument("Function set is NULL!");
	}

	if (p_bits > 0) {
		this->bits = p_bits;
	} else {
		throw std::invalid_argument("Inputs must be greater than zero!");
	}

	this->opcodes = this->functions->size();
	this->opcodesBits = pow(2.0, this->opcodes);

	this->chunk = this->table->getRows() / this->opcodes;

}

ALU::~ALU() {

}

void ALU::build() {

	int offset = opcodesBits;

	std::vector<int> op1;
	std::vector<int> op2;
	std::vector<int> op3;

	int result = 0;

	int rows = table->getRows();

	int index = 0;

	Function *function = functions->at(index);

	for (int i = 0; i < rows; i++) {
		if (i % chunk == 1) {
			index++;
			function = functions->at(index);
		}

		for (int j = 0; j < bits; j++) {

		}
	}


}

