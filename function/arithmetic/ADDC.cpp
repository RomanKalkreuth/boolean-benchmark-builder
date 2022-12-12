/*
 * 	Implements binary addition with carry
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#include "../arithmetic/ADDC.h"

/**
 *   sum = a xor b xor c
 *   carry = ab+bc+ca
 */
std::vector<std::vector<int>>* ADDC::execute(
		std::vector<std::vector<int>> *ops) {

	this->setup();
	std::vector<int> *bin1 = &ops->at(0);
	std::vector<int> *bin2 = &ops->at(1);
	std::vector<int> *bin3 = &ops->at(2);

	std::vector<int> sum;

	int carryIn = bin3->at(0);

	int a = 0;
	int b = 0;
	int s = 0;

	int c = carryIn;
	int dim = bin1->size();

	std::vector<int> carryOut;

	for (int i = 0; i < dim; i++) {
		a = bin1->at(i);
		b = bin2->at(i);
		s = (a ^ b) ^ c;
		sum.push_back(s);
		c = (a & b) | (c & (a ^ b));
	}

	carryOut.push_back(c);

	result->push_back(sum);
	result->push_back(carryOut);

	return result;
}

