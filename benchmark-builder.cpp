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

#include "benchmarks/arithmetic/Adder.h"
#include "benchmarks/arithmetic/AdderCarry.h"
#include "benchmarks/arithmetic/AdderSubtractor.h"
#include "benchmarks/arithmetic/Subtractor.h"
#include "benchmarks/arithmetic/SubtractorBorrow.h"
#include "benchmarks/transmission/Demultiplexer.h"
#include "benchmarks/comparative/IdentityComparator.h"
#include "benchmarks/comparative/MagnitudeComparator.h"
#include "benchmarks/mixed/ArithmeticLogicUnit.h"
#include "functions/logical/AND.h"
#include "table/TruthTable.h"

#include "export/Exporter.h"
#include "functions/arithmetic/ADD.h"
#include "functions/arithmetic/ADDC.h"
#include "functions/arithmetic/SUB.h"
#include "functions/arithmetic/SUBB.h"
#include "functions/Function.h"
#include "functions/logical/AND.h"
#include "functions/logical/OR.h"
#include "functions/logical/XOR.h"

#include "util/Util.h"

int main() {

	SUB *funcSub = new SUB();
	SUBB *funcSubb = new SUBB();
	ADD *funcAdd = new ADD();
	ADDC *funcAddc = new ADDC();

	AND *funcAnd = new AND();
	OR *funcOr = new OR();
	XOR *funcXor = new XOR();

	std::vector<Function*> *functions = new std::vector<Function*>();

	functions->push_back(funcAnd);
	functions->push_back(funcOr);
	functions->push_back(funcXor);
	functions->push_back(funcAdd);
	functions->push_back(funcSub);

	std::shared_ptr<Adder> add = std::make_shared < Adder > (funcAdd, 2);
	add->build();

	std::shared_ptr<AdderCarry> addc = std::make_shared < AdderCarry
			> (funcAddc, 2);
	addc->build();

	std::shared_ptr<Subtractor> sub = std::make_shared < Subtractor
			> (funcSub, 2);
	sub->build();

	std::shared_ptr<SubtractorBorrow> subb = std::make_shared
			< SubtractorBorrow > (funcSubb, 4);
	subb->build();

	std::shared_ptr<AdderSubtractor> addsub = std::make_shared < AdderSubtractor
			> (funcAddc, 4);
	addsub->build();

	std::shared_ptr<Demultiplexer> demux = std::make_shared < Demultiplexer
			> (8);
	demux->build();

	std::shared_ptr<IdentityComparator> icomp = std::make_shared
			< IdentityComparator > (4);
	icomp->build();

	std::shared_ptr<MagnitudeComparator> mcomp = std::make_shared
			< MagnitudeComparator > (5);
	mcomp->build();


	std::shared_ptr<ArithmeticLogicUnit> alu = std::make_shared
			< ArithmeticLogicUnit > (functions,4);
	alu->build();

	std::shared_ptr<TruthTable> table =  alu->getTable();

	//table->printHeader();
	table->printHumanReadable();

	Exporter<long> exporter(32);

	exporter.toPluFile(alu, "alu4");

	for (Function *f : *functions) {
		delete f;
	}

	delete functions;

	return 0;
}

