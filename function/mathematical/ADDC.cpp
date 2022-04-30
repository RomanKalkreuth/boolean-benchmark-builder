/*
 * 	Implements binary addition with carry
 *
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#include "ADDC.h"

ADDC::ADDC() {
}

ADDC::~ADDC() {

}

/**
 *   sum = a xor b xor c
 *   carry = ab+bc+ca
 */
std::vector<std::vector<int>>* ADDC::execute(
		std::vector<std::vector<int>> *ops) {

	this->setup();
	std::vector<int> *op1 = &ops->at(0);
	std::vector<int> *op2 = &ops->at(1);
	std::vector<int> *op3 = &ops->at(2);

	std::vector<int> sum;

	int carryIn = op3->at(0);

	result = addc(op1,op2, carryIn);

	return result;

}

