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

#include "benchmark/Adder.h"
#include "benchmark/AdderCarry.h"
#include "table/TruthTable.h"
#include "util/Convert.h"
#include "function/mathematical/SUB.h"
#include "function/mathematical/ADD.h"

int main() {
	const std::string inputNames[] = { "I1", "I2", "I3", "I4", "I5" };
	const std::string outputNames[] = { "O1", "O2", "O3" };

	std::vector<int> *bin1 = new std::vector<int> { 0, 0, 0, 0, 0, 0 };
	std::vector<int> *bin2 = new std::vector<int> { 1, 0, 0, 0, 1, 1 };

	std::vector<std::vector<int>> *vec = new std::vector<std::vector<int>>();
	std::vector<std::vector<int>> *result;

	vec->push_back(*bin1);
	vec->push_back(*bin2);

	SUB *sub = new SUB();
	ADD *add = new ADD();

	Adder *adder = new Adder(3, add);
	adder->build();

	TruthTable *table = adder->getTable();

	table->print();
	table->compressToLong();

	return 0;
}

