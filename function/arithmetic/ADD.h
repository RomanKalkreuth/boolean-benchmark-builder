/*
 * 	Implements binary addition
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#ifndef FUNCTION_ARITHMETIC_ADD_H_
#define FUNCTION_ARITHMETIC_ADD_H_

#include "ArithmeticFunction.h"

class ADD: public ArithmeticFunction {
public:
	ADD() = default;
	virtual ~ADD() = default;
	std::vector<std::vector<int>>* execute(std::vector<int> *bin1,
			std::vector<int> *bin2);
	std::vector<std::vector<int>>* execute(std::vector<std::vector<int>> *ops);
};

#endif /* FUNCTION_ARITHMETIC_ADD_H_ */
