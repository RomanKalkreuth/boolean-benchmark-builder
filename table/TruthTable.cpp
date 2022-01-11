/*
 * TruthTable.cpp
 *
 *  Created on: 09.12.2021
 *
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#include "TruthTable.h"

/**
 *
 */
TruthTable::TruthTable(int p_inputs, int p_outputs) {

	inputs = p_inputs;
	outputs = p_outputs;

	cols = inputs + outputs;
	rows = pow(2.0, inputs);

	table = new std::vector<std::vector<int> >(rows, std::vector<int>(cols, 0));

	init(rows, cols, outputs, table);
}

TruthTable::TruthTable(int p_inputs, int p_outputs, std::string *p_input_names,
		std::string *p_output_names) :
		TruthTable(p_inputs, p_outputs) {

	if (p_input_names != nullptr) {
		this->inputNames = p_input_names;
	} else {
		throw std::invalid_argument("Function set is NULL!");
	}

	if (p_output_names != nullptr) {
		this->outputNames = p_output_names;
	} else {
		throw std::invalid_argument("Function set is NULL!");
	}

}

/**
 *
 */
TruthTable::TruthTable(int p_bits) {
	cols = p_bits;
	rows = pow(2.0, cols);

	table = new std::vector<std::vector<int> >(rows, std::vector<int>(cols, 0));

	init(rows, cols, table);
}

TruthTable::~TruthTable() {
	delete table;
}

int TruthTable::at(int i, int j) const{
	return (*table)[i][j];
}

void TruthTable::set(int i, int j, int val) {
	(*table)[i][j] = val;
}


/**
 *
 */
void TruthTable::init(int rows, int cols, int outputs,
		std::vector<std::vector<int> >* table) {
	int n;
	int x = 0;
	for (int i = (cols - outputs - 1); i >= 0; i--) {
		n = pow(2.0, x);
		for (int j = 0; j < rows; j++) {
			if (j % (n * 2) >= n) {
				(*table)[j][i] = 1;
			}
		}
		x++;
	}
}

/**
 *
 */
void TruthTable::init(int rows, int cols,
		std::vector<std::vector<int> >* table) {
	int n;
	int x = 0;
	for (int i = (cols - 1); i >= 0; i--) {
		n = pow(2.0, x);
		for (int j = 0; j < rows; j++) {
			if (j % (n * 2) >= n) {
				(*table)[j][i] = 1;
			}
		}
		x++;
	}
}

/**
 *
 */
void TruthTable::print(bool header) {
	if (header) {

		if (inputNames == nullptr || outputNames == nullptr ) {
			throw std::runtime_error("Header is NULL!");
		}

		for (int i = 0; i < inputs; i++) {
			std::cout << inputNames[i] << " ";
		}

		for (int i = 0; i < outputs; i++) {
			std::cout << outputNames[i] << " ";
		}

		std::cout << std::endl;
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout <<(*table)[i][j] << "  ";
		}
		std::cout << std::endl;
	}
}

int TruthTable::getCols() const {
	return cols;
}

const std::string* TruthTable::getInputNames() const {
	return inputNames;
}

const std::string* TruthTable::getOutputNames() const {
	return outputNames;
}

int TruthTable::getInputs() const {
	return inputs;
}

int TruthTable::getOutputs() const {
	return outputs;
}

int TruthTable::getRows() const {
	return rows;
}

const std::vector<std::vector<int> >* TruthTable::getTable() const {
	return table;
}

