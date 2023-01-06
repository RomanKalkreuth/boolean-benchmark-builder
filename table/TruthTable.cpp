/*
 * Class for the representation of the truth table and
 * the corresponding functionality.
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#include "TruthTable.h"

/**
 * Constructor that creates a dummy table based on the
 * number of inputs and outputs
 */
TruthTable::TruthTable(int p_inputs, int p_outputs) {

	if (p_inputs > 0) {
		this->inputs = p_inputs;
	} else {
		throw std::invalid_argument("Inputs must be greater 0!");
	}

	if (p_outputs > 0) {
		this->outputs = p_outputs;
	} else {
		throw std::invalid_argument("Outputs must be greater 0!");
	}

	cols = inputs + outputs;
	rows = std::pow(2.0, inputs);

	table = new std::vector<std::vector<int> >(rows, std::vector<int>(cols, 0));

	chunkSize = 32;

	init(rows, cols, outputs, table);
}

TruthTable::~TruthTable() {
	delete table;
	delete inputNames;
	delete outputNames;
	delete separators;
}


/**
 * Constructor that creates a dummy table based on the
 * number of inputs and outputs.
 * This constructors also includes the input and output names
 * as well as the separators for formatting
 */
TruthTable::TruthTable(int p_inputs, int p_outputs,
		std::vector<std::string> *p_input_names,
		std::vector<std::string> *p_output_names,
		std::vector<int> *p_separators) :
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
 * Constructor that creates a dummy table based on the
 * number of bits
 */
TruthTable::TruthTable(int p_bits) {
	cols = p_bits;
	rows = std::pow(2.0, cols);
	table = new std::vector<std::vector<int> >(rows, std::vector<int>(cols, 0));
	init(rows, cols, table);
}


/**
 * Initializes the values only for the inputs of the table
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
 * Initializes the values for the whole table
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
 * Format and print the table readable for human beings.
 */
void TruthTable::printHumanReadable() {

	if (separators == nullptr) {
		throw std::runtime_error("Separators is NULL!");
	}
	for (int i = 0; i < rows; i++) {
		std::vector<int>::iterator it = separators->begin();

		for (int j = 0; j < cols; j++) {
			std::cout << (*table)[i][j] << "  ";

			if (it != separators->end()) {
				if (j == *it) {
					std::cout << " ";
					++it;
				}
			}

			if ((j + 1) == inputs) {
				std::cout << " :  ";
			}
		}
		std::cout << std::endl;
	}
}

/**
 * Raw print of the table.
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
 * Print only the header
 */
void TruthTable::printHeader() {

	if (separators == nullptr) {
		throw std::runtime_error("Separators is NULL!");
	}

	if (inputNames == nullptr || outputNames == nullptr) {
		throw std::runtime_error("Header is NULL!");
	}

	std::vector<int>::iterator it = separators->begin();

	for (int i = 0; i <= cols; i++) {

		if (i < inputs) {
			std::cout << inputNames->at(i) << " ";
		} else if (i == inputs) {
			std::cout << " :  ";
		} else {
			std::cout << outputNames->at(i - inputs - 1) << " ";
		}

		if (it != separators->end()) {
			if (i == *it) {
				std::cout << " ";
				++it;
			}
		}

	}
	std::cout << std::endl;

}

/**
 * Print the compressed truth table
 */
void TruthTable::printCompressedTable(
		std::vector<std::vector<unsigned int>> *comprTable) {

	std::vector<unsigned int> *vec = &comprTable->at(0);

	int rows = vec->size();
	int cols = comprTable->size();

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << (*comprTable)[j][i] << " ";
			if (j == inputs - 1) {
				std::cout << "  ";
			}
		}
		std::cout << std::endl;
	}

}

/**
 * Compress the table
 */
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

			val += b * std::pow(2.0, e);

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

/**
 * Trims the table by erasing rows from the beginning
 */
void TruthTable::trim(int row) {

	for (int i = row; i < rows; i++) {
		table->erase(table->begin() + i);
	}
	rows = table->size();
}



/*
 * Getter and setter for elements of the table.
 */
int TruthTable::at(int i, int j) const {
	return (*table)[i][j];
}


void TruthTable::set(int i, int j, int val) {
	(*table)[i][j] = val;
}


/**
 * Getter and setter for attributes of the class
 */
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

