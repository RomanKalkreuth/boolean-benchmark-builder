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
	rows = std::pow(2.0, inputs);

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
	rows = std::pow(2.0, cols);
	table = new std::vector<std::vector<int> >(rows, std::vector<int>(cols, 0));
	init(rows, cols, table);
}

TruthTable::~TruthTable() {
	delete table;
}

int TruthTable::at(int i, int j) const {
	return (*table)[i][j];
}

void TruthTable::set(int i, int j, int val) {
	(*table)[i][j] = val;
}

/**
 *
 */
void TruthTable::init(int rows, int cols, int outputs,
		std::vector<std::vector<int> > *table) {
	int n;
	int x = 0;
	for (int i = (cols - outputs - 1); i >= 0; i--) {
		n = std::pow(2.0, x);
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
		std::vector<std::vector<int> > *table) {
	int n;
	int x = 0;
	for (int i = (cols - 1); i >= 0; i--) {
		n = std::pow(2.0, x);
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
void TruthTable::print() {

	int separator = inputs / 2;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << (*table)[i][j];

			if ((j + 1) == separator) {
				std::cout << " ";
			}

			if ((j + 1) == inputs) {
				std::cout << " : ";
			}
		}
		std::cout << std::endl;
	}
}

/*
 if (header) {

 if (inputNames == nullptr || outputNames == nullptr) {
 throw std::runtime_error("Header is NULL!");
 }

 for (int i = 0; i < inputs; i++) {
 std::cout << inputNames[i] << " ";
 }

 for (int i = 0; i < outputs; i++) {
 std::cout << outputNames[i] << " ";
 }

 std::cout << std::endl;
 }*/

void TruthTable::compressToInt() {

	int val = 0;
	std::vector<int> compressed;
	std::vector<int> bin;

	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			bin.push_back((*table)[j][i]);
		}
		val = Convert::binToInt(&bin);
		compressed.push_back(val);
		bin.clear();
		std::cout << val << std::endl;
	}
	std::cout << std::endl;
}

void TruthTable::compressToLong() {

	if (rows % chunkSize != 0) {
		throw new std::runtime_error("Number of rows does "
				"not fit with chunk size " + chunkSize);
	}

	std::cout << std::endl;

	unsigned long val = 0;
	std::vector<std::vector<unsigned long>> compressed;
	std::vector<unsigned long> chunks;
	int b;
	int e;

	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			b = (*table)[j][i];
			e = j % chunkSize;
			val += b * Pow::pow(2.0, e);

			if ((j + 1) % chunkSize == 0) {
				std::cout << val << std::endl;
				chunks.push_back(val);
				val = 0;
			}
		}
		compressed.push_back(chunks);
		std::cout << std::endl;
		chunks.clear();
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

int TruthTable::getChunkSize() const {
	return chunkSize;
}

void TruthTable::setChunkSize(int chunkSize) {
	this->chunkSize = chunkSize;
}

