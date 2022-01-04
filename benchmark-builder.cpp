//============================================================================
// Name        : boolean-benchmark-builder.cpp
// Author      : Roman Kalkreuth
// Version     :
// Copyright   : 
// Description :
//============================================================================

#include <iostream>
#include <cmath>
#include <vector>
#include <string>

#include "table/TruthTable.h"
#include "util/Convert.h"

int main() {
	int inputs=5;
	int outputs=3;
	std::string inputNames[]  = {"I1", "I2", "I3", "I4", "I5"};
	std::string outputNames[] = {"O1", "O2", "O3"};
	std::vector<char>* bin = new std::vector<char>{ '1', '0', '1', '1', '1', '1' };

	Convert* converter = new Convert();


	TruthTable table(inputs,outputs, inputNames, outputNames);

	int dec = converter->binToDec(bin);

	std::cout << dec << std::endl;

	delete bin;

	bin = converter->decToBin(108);

	for (char i: *bin)
	    std::cout << i << ' ';

	//table.print(true);


	delete converter;

	return 0;
}

