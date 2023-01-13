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
#include "benchmark/logical/comparative/IdentityComparator.h"
#include "benchmark/logical/comparative/MagnitudeComparator.h"

#include "function/Function.h"

#include "function/logical/AND.h"
#include "function/logical/OR.h"
#include "function/logical/XOR.h"

#include "function/arithmetic/ADDC.h"
#include "function/arithmetic/ADD.h"
#include "function/arithmetic/SUB.h"
#include "function/arithmetic/SUBB.h"

#include "table/TruthTable.h"

#include "export/Exporter.h"

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

	std::shared_ptr<Adder> adder = std::make_shared < Adder > (funcAdd, 2);
	adder->build();

	std::shared_ptr<AdderCarry> adderCarry = std::make_shared < AdderCarry
			> (funcAddc, 2);
	adderCarry->build();

	std::shared_ptr<Subtractor> subtractor = std::make_shared < Subtractor
			> (funcSub, 2);
	subtractor->build();

	std::shared_ptr<SubtractorBorrow> subtractorBorrow = std::make_shared
			< SubtractorBorrow > (funcSubb, 4);
	subtractorBorrow->build();

	std::shared_ptr<AdderSubtractor> addSub = std::make_shared < AdderSubtractor
			> (funcAddc, 4);
	addSub->build();

	std::shared_ptr<Demultiplexer> demux = std::make_shared < Demultiplexer
			> (4);
	demux->build();

	std::shared_ptr<IdentityComparator> identityComparator = std::make_shared
			< IdentityComparator > (3);
	identityComparator->build();

	std::shared_ptr<MagnitudeComparator> magnitudeComparator = std::make_shared
			< MagnitudeComparator > (2);
	magnitudeComparator->build();

	std::shared_ptr<TruthTable> table = magnitudeComparator->getTable();

	//table->printHeader();
	table->printHumanReadable();

	Exporter<long> exporter;

	exporter.to_plu_file(magnitudeComparator, "mcomp");

	for (Function *f : *functions) {
		delete f;
	}

	delete functions;

	return 0;
}

