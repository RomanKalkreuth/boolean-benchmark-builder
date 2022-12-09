/*
 * 	Class ALU implements the arithmetic logic unit benchmark.
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#include "ALU.h"

ALU::ALU(std::vector<Function*> *p_functions, int p_bit_length) {
	if (p_functions != nullptr) {
		functions = p_functions;
	} else {
		throw std::invalid_argument("Function set is NULL!");
	}

	numFunctions = functions->size();

	if (numFunctions <= 1) {
		throw std::invalid_argument(
				"Number of functions must be at least 2. This is a multifunctional benchmark!");
	}

	if (p_functions != nullptr) {
		functions = p_functions;
	} else {
		throw std::invalid_argument("Function set is NULL!");
	}

	if (p_bit_length > 0) {
		bitLength = p_bit_length;
	} else {
		throw std::invalid_argument("Bits must be greater than zero!");
	}

	opcodeBits = ceil(log2(numFunctions));

	inputs = 2 * bitLength + opcodeBits;
	outputs = bitLength + 1;

	std::vector<int> *separators = new std::vector<int>();

	int sep1 = opcodeBits - 1;
	int sep2 = opcodeBits + bitLength - 1;
	int sep3 = 2 * bitLength + opcodeBits;

	separators->push_back(sep1);
	separators->push_back(sep2);
	separators->push_back(sep3);

	generateInputNames();
	generateOutputNames();

	table = new TruthTable(inputs, outputs, inputNames, outputNames,
			separators);

	int maxFunctions = std::pow(2.0, opcodeBits);

	if (numFunctions < maxFunctions) {
		int len = 2 * bitLength;
		int rows = numFunctions * std::pow(2.0, len);
		table->trim(rows);
	}

	chunkSize = table->getRows() / numFunctions;

	if (chunkSize < 32) {
		table->setChunkSize(chunkSize);
	}

}

ALU::~ALU() {

	for (std::vector<Function*>::iterator it = functions->begin();
			it != functions->end(); ++it) {
		delete *it;
	}
	delete functions;
}

/**
 *
 */
void ALU::build() {

	int rows = table->getRows();

	int opcode = 0;
	int r = 0;

	int inputPos = opcodeBits;
	int statusPos = 2 * bitLength + opcodeBits;
	int resPos = statusPos + 1;

	int statusVal = 0;

	std::vector<int> op1;
	std::vector<int> op2;

	std::vector<int> *res;
	std::vector<int> *status;

	Function *function = functions->at(0);

	for (int i = 0; i < rows; i++) {

		op1.clear();
		op2.clear();
		operands->clear();

		if ((i % chunkSize == 0) && i > 0) {
			opcode++;
			function = functions->at(opcode);
		}

		//TODO: Optimize loading of the operators

		for (int j = 0; j < bitLength; j++) {
			int val1 = table->at(i, inputPos + j);
			int val2 = table->at(i, inputPos + bitLength + j);
			op1.push_back(val1);
			op2.push_back(val2);
		}

		std::reverse(op1.begin(), op1.end());
		std::reverse(op2.begin(), op2.end());

		operands->push_back(op1);
		operands->push_back(op2);

		result = function->execute(operands);

		res = &result->at(0);

		std::reverse(res->begin(), res->end());

		for (int j = 0; j < bitLength; j++) {
			r = res->at(j);
			table->set(i, j + resPos, r);
		}

		if (result->size() > 1) {
			status = &result->at(1);
			statusVal = status->at(0);
			table->set(i, statusPos, statusVal);
		}

	}
}

void ALU::generateOutputNames() {

	outputNames->push_back("S ");

	for (int i = bitLength - 1; i >= 0; i--) {
		outputNames->push_back("O" + std::to_string(i));
	}
}

void ALU::generateInputNames() {

	for (int i = opcodeBits - 1; i >= 0; i--) {
		inputNames->push_back("M" + std::to_string(i));
	}

	for (int i = bitLength - 1; i >= 0; i--) {
		inputNames->push_back("B" + std::to_string(i));
	}

	for (int i = bitLength - 1; i >= 0; i--) {
		inputNames->push_back("A" + std::to_string(i));
	}
}

