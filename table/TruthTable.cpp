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

TruthTable::TruthTable(int p_inputs, int p_outputs,
		std::vector<std::string> *p_input_names,
		std::vector<std::string> *p_output_names, std::vector<int> *p_separators) :
		TruthTable(p_inputs, p_outputs) {

	if (p_input_names != nullptr) {
		this->inputNames = p_input_names;
	} else {
		throw std::invalid_argument("p_input_names is NULL!");
	}

	if (p_output_names != nullptr) {
		this->outputNames = p_output_names;
	} else {
		throw std::invalid_argument("p_output_names is NULL!");
	}

	if (p_separators != nullptr) {
		this->separators = p_separators;
	} else {
		throw std::invalid_argument("p_separators is NULL!");
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
	delete inputNames;
	delete outputNames;
	delete separators;
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
void TruthTable::printHumanReadable() {

	if (separators == nullptr) {
		throw std::runtime_error("Separators is NULL!");
	}
	for (int i = 0; i < rows; i++) {
		std::vector<int>::iterator it = separators->begin();

		for (int j = 0; j < cols; j++) {
			std::cout << (*table)[i][j];

			if(it != separators->end()){
				if( j == *it){
					std::cout << " ";
					++it;
				}
			}

			if ((j + 1) == inputs) {
				std::cout << " : ";
			}
		}
		std::cout << std::endl;
	}
}

/**
 *
 */
void TruthTable::print() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << (*table)[i][j];
		}
		std::cout << std::endl;
	}
}

/**
 *
 */

//TODO: Revise method
void TruthTable::printHeader() {

	if (inputNames == nullptr || outputNames == nullptr) {
		throw std::runtime_error("Header is NULL!");
	}

	for (int i = 0; i < inputs; i++) {
		std::cout << inputNames->at(i) << " ";
	}

	for (int i = 0; i < outputs; i++) {
		std::cout << outputNames->at(i) << " ";
	}

	std::cout << std::endl;

}

//TODO: Implement method
void TruthTable::printCompressedTable(
		std::vector<std::vector<unsigned int>> *comprTable) {

}

std::vector<std::vector<unsigned int>>* TruthTable::compress() {

	bool chunk = false;

	if (rows > chunkSize) {
		if ((rows % chunkSize) != 0) {
			throw new std::runtime_error("Number of rows does "
					"not fit with chunk size " + chunkSize);
		}
		chunk = true;
	}

	unsigned int val = 0;
	std::vector<std::vector<unsigned int>> *comprTable = new std::vector<
			std::vector<unsigned int>>();

	std::vector<unsigned int> chunks;

	int b;
	int e;

	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			b = (*table)[j][i];

			if (chunk) {
				e = j % chunkSize;
			} else {
				e = j;
			}

			val += b * Pow::pow(2.0, e);

			if (chunk && ((j + 1) % chunkSize == 0)) {
				chunks.push_back(val);
				val = 0;
			}
		}
		if (chunk) {
			comprTable->push_back(chunks);
		} else {
			std::vector<unsigned int> col(val);
			comprTable->push_back(col);
		}

		chunks.clear();
	}

	return comprTable;
}

int TruthTable::getCols() const {
	return cols;
}

const std::vector<std::string>* TruthTable::getInputNames() const {
	return inputNames;
}

const std::vector<std::string>* TruthTable::getOutputNames() const {
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

