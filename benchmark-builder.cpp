//============================================================================
// Project     : Boolean Benchmark Builder
// Author      : Roman Kalkreuth
//         		 https://orcid.org/0000-0003-1449-5131,
//          	 https://www.researchgate.net/profile/Roman-Kalkreuth,
//         		https://twitter.com/RomanKalkreuth
// Version     : 0.1 Beta
// Description : C++ based project for the automatic build of Boolean function benchmarks
// License 	   :
//============================================================================

#include <iostream>
#include <cmath>
#include <vector>
#include <string>

#include "benchmark/mixed/ALU.h"
#include "benchmark/arithmetic/Adder.h"
#include "benchmark/arithmetic/AdderCarry.h"
#include "function/arithmetic/ADD.h"
#include "function/arithmetic/SUB.h"
#include "table/TruthTable.h"
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



	Adder *adder = new Adder(funcAdd,2);

	/*

	ALU *alu = new ALU(functions, 4);

	alu->build();

	TruthTable *table = alu->getTable();

	table->printHeader();
	table->printHumanReadable();

	std::cout << std::endl;
	std::cout << std::endl;

	std::vector<std::vector<unsigned int>>* compressed = table->compress();

	table->printCompressedTable(compressed); */

	return 0;
}

