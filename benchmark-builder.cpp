//============================================================================
// Name        : boolean-benchmark-builder.cpp
// Author      : Roman Kalkreuth
// Version     : 0.1 Beta
// Description : C++ based project for the automatic build of Boolean benchmarks
//============================================================================

#include <iostream>
#include <cmath>
#include <vector>
#include <string>

#include "benchmark/ALU.h"
#include "benchmark/Adder.h"
#include "benchmark/AdderCarry.h"
#include "table/TruthTable.h"
#include "function/mathematical/SUB.h"
#include "function/mathematical/ADD.h"
#include "function/logical/AND.h"
#include "function/logical/OR.h"
#include "function/logical/XOR.h"
#include "function/Function.h"

int main() {

	SUB *funcSub = new SUB();
	ADD *funcAdd = new ADD();
	AND *funcAnd = new AND();
	OR *funcOr = new OR();
	XOR *funcXor = new XOR();

	std::vector<Function*>* functions = new std::vector<Function*>();

	functions->push_back(funcAnd);
	functions->push_back(funcOr);
	functions->push_back(funcXor);
	functions->push_back(funcAdd);
	functions->push_back(funcSub);

	ALU *alu = new ALU(functions, 3);
	alu->build();
	TruthTable *table = alu->getTable();
	table->printHeader();
	//table->printHumanReadable();

	std::vector<std::vector<unsigned int>>* compressed = table->compress();

	//table->printCompressedTable(compressed);

	return 0;
}

