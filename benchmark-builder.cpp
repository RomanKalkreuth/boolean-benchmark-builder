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

#include "table/TruthTable.h"

using namespace std;

int main() {
	TruthTable table(5,3);

	table.print();

	return 0;
}

