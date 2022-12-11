//============================================================================
// Project     : Boolean Benchmark Builder
// Author      : Roman Kalkreuth
//         		 https://orcid.org/0000-0003-1449-5131,
//          	 https://www.researchgate.net/profile/Roman-Kalkreuth,
//         		 https://twitter.com/RomanKalkreuth
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
#include "benchmark/arithmetic/Subtractor.h"


#include "function/Function.h"

#include "function/logical/AND.h"
#include "function/logical/OR.h"
#include "function/logical/XOR.h"

#include "function/arithmetic/ADD.h"
#include "function/arithmetic/SUB.h"

#include "table/TruthTable.h"


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

	Adder *adder = new Adder(funcAdd,3);
	adder->build();

	Subtractor *subtractor = new Subtractor(funcSub,3);
	subtractor->build();

	TruthTable *table = subtractor->getTable();

	table->printHeader();
	table->printHumanReadable();

	return 0;
}

