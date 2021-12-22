//============================================================================
// Name        : boolean-benchmark-builder.cpp
// Author      : Roman Kalkreuth
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <vector>
#include <string>

#include "table/TruthTable.h"

int main() {
	int inputs=5;
	int outputs=3;
	std::string inputNames[]  = {"I1", "I2", "I3", "I4", "I5"};
	std::string outputNames[] = {"O1", "O2", "O3"};

	TruthTable table(inputs,outputs, inputNames, outputNames);

	table.print(true);

	return 0;
}

