/*
 * 	Implements binary addition
 *
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#include "ADD.h"

ADD::ADD() {

}

ADD::~ADD() {

}

/**
 *   sum = a xor b xor c
 */
std::vector<std::vector<int>>* ADD::execute(
		std::vector<std::vector<int>> *ops) {

	this->setup();
	std::vector<int>* op1 =  &ops->at(0);
	std::vector<int>* op2 =  &ops->at(1);

	result = add(op1,op2);

	return result;
}

