/*
 * 	Abstract base class for logical and mathematical functions.
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#include "Function.h"

Function::Function() {
	res = new std::vector<int>();
	result = new std::vector<std::vector<int>>();
}

Function::~Function() {
	delete res;
	delete result;
}

void Function::setup() {
	res->clear();
	result->clear();
}
