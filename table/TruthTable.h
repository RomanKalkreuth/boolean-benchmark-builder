/*
 * TruthTable.h
 *
 *  Created on: 08.12.2021
 *      Author: Roman Kalkreuth
 */

#ifndef TRUTHTABLE_H_
#define TRUTHTABLE_H_

#include <vector>
#include <cmath>
#include <iostream>

class TruthTable {
public:
	int inputs;
	int outputs;
	int cols;
	int rows;

	std::vector<std::vector<int> > table;

	TruthTable(int p_inputs, int p_outputs);
	TruthTable(int p_bits);
	virtual ~TruthTable();

	void init(int rows, int cols, int outputs,std::vector<std::vector<int> >& table);
	void init(int rows, int cols,std::vector<std::vector<int> >& table);
	void print();

};

#endif /* TRUTHTABLE_H_ */
