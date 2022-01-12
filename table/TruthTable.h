/*
 * TruthTable.h
 *
 *  Created on: 09.12.2021
 *
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#ifndef TRUTHTABLE_H_
#define TRUTHTABLE_H_

#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <string>
#include <exception>

#include "../util/Convert.h"
#include "../util/Pow.h"


class TruthTable {
private:
	int inputs;
	int outputs;
	int cols;
	int rows;
	int chunkSize = 32;

	std::vector<std::vector<int> > *table;

	const std::string *inputNames;
	const std::string *outputNames;

public:

	TruthTable(int p_inputs, int p_outputs);
	TruthTable(int p_inputs, int p_outputs, std::string *p_input_names,
			std::string *p_output_names);

	TruthTable(int p_bits);
	virtual ~TruthTable();

	void init(int rows, int cols, int outputs,
			std::vector<std::vector<int> > *table);
	void init(int rows, int cols, std::vector<std::vector<int> > *table);
	void print();
	void compressToLong();
	void compressToInt();

	int getInputs() const;
	int getOutputs() const;
	int getRows() const;
	int getCols() const;

	int at(int i, int j) const;
	void set(int i, int j, int val);

	const std::string* getInputNames() const;
	const std::string* getOutputNames() const;

	int getChunkSize() const;
	void setChunkSize(int chunkSize);

	const std::vector<std::vector<int> >* getTable() const;

};

#endif /* TRUTHTABLE_H_ */
