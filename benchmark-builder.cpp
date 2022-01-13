//============================================================================
// Name        : boolean-benchmark-builder.cpp
// Author      : Roman Kalkreuth
// Version     : 0.1 Beta
// Copyright   : 
// Description :
//============================================================================

#include <iostream>
#include <cmath>
#include <vector>
#include <string>

#include "benchmark/ALU.h"
#include "benchmark/Adder.h"
#include "benchmark/AdderCarry.h"
#include "table/TruthTable.h"
#include "util/Convert.h"
#include "function/mathematical/SUB.h"
#include "function/mathematical/ADD.h"
#include "function/logical/AND.h"
#include "function/Function.h"

int main() {

	std::vector<int> *bin1 = new std::vector<int> { 0, 0, 0, 0, 0, 0 };
	std::vector<int> *bin2 = new std::vector<int> { 1, 0, 0, 0, 1, 1 };

	SUB *sub = new SUB();
	ADD *add = new ADD();
	AND *fand = new AND();


	std::vector<Function*>* functions = new std::vector<Function*>();
	functions->push_back(fand);

	//Adder *adder = new Adder(3, sub);
	//adder->build();
	//TruthTable *table = adder->getTable();
	//std::vector<std::vector<unsigned int>>* comprTable;
	//comprTable = table->compress();


	ALU *alu = new ALU(functions, 3);
	TruthTable *table = alu->getTable();
	table->printHumanReadable();


	//delete comprTable;
	//delete functions;

	return 0;
}

