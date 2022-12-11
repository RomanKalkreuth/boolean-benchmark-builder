/*
 * 	Implements binary addition
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#include "../arithmetic/ADD.h"

ADD::ADD() {

}

ADD::~ADD() {

}

std::vector<std::vector<int>>* ADD::execute(
		std::vector<std::vector<int>> *ops) {

	std::vector<int> *bin1 = &ops->at(0);
	std::vector<int> *bin2 = &ops->at(1);

	result = this->execute(bin1, bin2);

	return result;
}

std::vector<std::vector<int>>* ADD::execute(std::vector<int> *bin1,
		std::vector<int> *bin2) {

	this->setup();

	int dim = bin1->size();
	int a = 0;
	int b = 0;
	int s = 0;
	int c = 0;

	std::vector<int> sum;
	std::vector<int> carry;

	std::vector<std::vector<int>> *result = new std::vector<std::vector<int>>();

	for (int i = 0; i < dim; i++) {
		a = bin1->at(i);
		b = bin2->at(i);
		s = ((a ^ b) ^ c);
		c = (a & b) | (c & (a ^ b));
		sum.push_back(s);
	}
	carry.push_back(c);

	result->push_back(sum);
	result->push_back(carry);

	return result;
}


