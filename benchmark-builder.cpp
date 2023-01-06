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
#include "benchmark/arithmetic/SubtractorBorrow.h"
#include "benchmark/arithmetic/AdderSubtractor.h"


#include "function/Function.h"

#include "function/logical/AND.h"
#include "function/logical/OR.h"
#include "function/logical/XOR.h"

#include "function/arithmetic/ADDC.h"
#include "function/arithmetic/ADD.h"
#include "function/arithmetic/SUB.h"
#include "function/arithmetic/SUBB.h"

#include "table/TruthTable.h"


int main() {

	SUB *funcSub = new SUB();
	SUBB *funcSubb = new SUBB();
	ADD *funcAdd = new ADD();
	ADDC *funcAddc = new ADDC();

	AND *funcAnd = new AND();
	OR *funcOr = new OR();
	XOR *funcXor = new XOR();


	std::vector<Function*>* functions = new std::vector<Function*>();

	functions->push_back(funcAnd);
	functions->push_back(funcOr);
	functions->push_back(funcXor);
	functions->push_back(funcAdd);
	functions->push_back(funcSub);

	Adder *adder = new Adder(funcAdd, 2);
	adder->build();

	AdderCarry* adderCarry = new AdderCarry(funcAddc, 2);
	adderCarry->build();

	Subtractor *subtractor = new Subtractor(funcSub, 2);
	subtractor->build();

	SubtractorBorrow *subtractorBorrow = new SubtractorBorrow(funcSubb, 4);
	subtractorBorrow->build();

	AdderSubtractor* addSub = new AdderSubtractor(funcAddc, 4);
	addSub->build();

	TruthTable *table = addSub->getTable();

	table->printHeader();
	table->printHumanReadable();

	delete adder;
	delete adderCarry;
	delete subtractor;
	delete subtractorBorrow;
	delete addSub;

	return 0;
}

