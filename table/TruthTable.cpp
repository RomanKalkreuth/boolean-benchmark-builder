/*
 * TruthTable.cpp
 *
 *  Created on: 08.12.2021
 *      Author: Roman Kalkreuth
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

	table = std::vector<std::vector<int> >(rows, std::vector<int>(cols, 0));

	init(rows, cols, outputs, table);
}

/**
 *
 */
TruthTable::TruthTable(int p_bits) {
	cols = p_bits;
	rows = pow(2.0, cols);

	table = std::vector<std::vector<int> >(rows, std::vector<int>(cols, 0));

	init(rows, cols, table);
}

TruthTable::~TruthTable() {

}

/**
 *
 */
void TruthTable::init(int rows, int cols, int outputs,
		std::vector<std::vector<int> > &table) {
	int n;
	int x = 0;
	for (int i = (cols - outputs - 1); i >= 0; i--) {
		n = pow(2.0, x);
		for (int j = 0; j < rows; j++) {
			if (j % (n * 2) >= n) {
				table[j][i] = 1;
			}
		}
		x++;
	}
}

/**
 *
 */
void TruthTable::init(int rows, int cols, std::vector<std::vector<int> > &table) {
	int n;
	int x = 0;
	for (int i = (cols - 1); i >= 0; i--) {
		n = pow(2.0, x);
		for (int j = 0; j < rows; j++) {
			if (j % (n * 2) >= n) {
				table[j][i] = 1;
			}
		}
		x++;
	}
}

/**
 *
 */
void TruthTable::print() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << table[i][j];
		}
		std::cout << std::endl;
	}
}

