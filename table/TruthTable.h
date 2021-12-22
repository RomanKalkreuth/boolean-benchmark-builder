/*
 * TruthTable.h
 *
 *  Created on: 09.12.2021
 *  Author: Roman Kalkreuth
 */

#ifndef TRUTHTABLE_H_
#define TRUTHTABLE_H_

#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <string>

class TruthTable {
public:
	int inputs;
	int outputs;
	int cols;
	int rows;

	std::vector<std::vector<int> > table;

	std::string* inputNames;
	std::string* outputNames;

	TruthTable(int p_inputs, int p_outputs);
	TruthTable(int p_inputs, int p_outputs, std::string* p_input_names, std::string*
			p_output_names);

	TruthTable(int p_bits);


	virtual ~TruthTable();

	void init(int rows, int cols, int outputs,std::vector<std::vector<int> >& table);
	void init(int rows, int cols,std::vector<std::vector<int> >& table);
	void print(bool header);

};

#endif /* TRUTHTABLE_H_ */
