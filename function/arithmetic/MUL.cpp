/*
 * 	Implements binary multiplication
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */


#include "../arithmetic/MUL.h"

MUL::MUL() {

}

MUL::~MUL() {
}

/**
 *
 */
std::vector<std::vector<int>>* MUL::execute(
		std::vector<std::vector<int>> *ops) {

	this->setup();
	std::vector<int>* op1 =  &ops->at(0);
	std::vector<int>* op2 =  &ops->at(1);

	return result;
}

