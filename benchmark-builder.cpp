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
#include <memory>

#include "benchmark/mixed/ALU.h"
#include "benchmark/arithmetic/Adder.h"
#include "benchmark/arithmetic/AdderCarry.h"
#include "benchmark/arithmetic/Subtractor.h"
#include "benchmark/arithmetic/SubtractorBorrow.h"
#include "benchmark/arithmetic/AdderSubtractor.h"

#include "benchmark/logical/combinational/Demultiplexer.h"
#include "benchmark/logical/comparative/Comparator.h"

#include "function/Function.h"

#include "function/logical/AND.h"
#include "function/logical/OR.h"
#include "function/logical/XOR.h"

#include "function/arithmetic/ADDC.h"
#include "function/arithmetic/ADD.h"
#include "function/arithmetic/SUB.h"
#include "function/arithmetic/SUBB.h"

#include "table/TruthTable.h"

#include "util/Util.h"


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

	std::unique_ptr<Adder> adder = std::make_unique<Adder>(funcAdd, 2);
	adder->build();

	std::unique_ptr<AdderCarry> adderCarry = std::make_unique<AdderCarry>(funcAddc, 2);
	adderCarry->build();

	std::unique_ptr<Subtractor> subtractor = std::make_unique<Subtractor>(funcSub, 2);
	subtractor->build();

	std::unique_ptr<SubtractorBorrow> subtractorBorrow = std::make_unique<SubtractorBorrow>(funcSubb, 4);
	subtractorBorrow->build();

	std::unique_ptr<AdderSubtractor> addSub = std::make_unique<AdderSubtractor>(funcAddc, 4);
	addSub->build();

	std::unique_ptr<Demultiplexer> demux = std::make_unique<Demultiplexer>(4);
	demux->build();

	std::unique_ptr<Comparator> comparator = std::make_unique<Comparator>(3);
	comparator->build();

	std::shared_ptr<TruthTable> table = comparator->getTable();

	//table->printHeader();
	table->printHumanReadable();


	for(Function* f : *functions) {
		delete f;
	}

	delete functions;

	return 0;
}

