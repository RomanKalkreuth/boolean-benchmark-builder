/*
 *
 *
 * Class for the representation of the truth table and
 * the corresponding functionality.
 *
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#ifndef TRUTHTABLE_H_
#define TRUTHTABLE_H_

#include <vector>
#include <stack>
#include <cmath>
#include <string>
#include <iostream>
#include <exception>
#include <memory>

#include "../util/Util.h"


class TruthTable {
private:
	int inputs;
	int outputs;
	int cols;
	int rows;
	int chunkSize;

	const int MAX_CHUNK_SIZE = 32;

	std::shared_ptr<std::vector<int>> separators;
	std::vector<std::vector<int> > *table;
	std::vector<std::string>* inputNames;
	std::vector<std::string>* outputNames;

public:

	TruthTable(int p_inputs, int p_outputs);
	TruthTable(int p_inputs, int p_outputs, std::vector<std::string>* p_input_names,
			std::vector<std::string>* p_output_names, std::shared_ptr<std::vector<int>> p_separators);

	TruthTable(int p_bits);
	virtual ~TruthTable();

	void init(int rows, int cols, int outputs,
			std::vector<std::vector<int> > *table);
	void init(int rows, int cols, std::vector<std::vector<int> > *table);
	void print();
	void printHumanReadable();
	void printHeader();
	void printCompressedTable(std::vector<std::vector<unsigned int>>* comprTable);

	std::vector<std::vector<unsigned int>>* compress();
	void trim(int row);

	int at(int i, int j) const;
	void set(int i, int j, int val);

	int getInputs() const;
	int getOutputs() const;
	int getRows() const;
	int getCols() const;
	const std::vector<std::string>* getInputNames() const;
	const std::vector<std::string>* getOutputNames() const;

	int getChunkSize() const;
	void setChunkSize(int chunkSize);

	const std::vector<std::vector<int> >* getTable() const;

};

#endif /* TRUTHTABLE_H_ */
