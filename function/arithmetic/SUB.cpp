/*
 * 	Implements binary subtraction
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#include "../arithmetic/SUB.h"

SUB::SUB() {
	funcAdd = new ADD();
	complement = new Complement();
}

SUB::~SUB() {
	delete funcAdd;
}


std::vector<std::vector<int>>* SUB::execute(
		std::vector<std::vector<int>> *ops) {

	this->setup();

	std::vector<int> *bin1 = &ops->at(0);
	std::vector<int> *bin2 = &ops->at(1);

	std::vector<int> *cmpl;

	cmpl = complement->complement(bin2);

	result = funcAdd->execute(bin1,cmpl);

	delete cmpl;

	return result;
}

