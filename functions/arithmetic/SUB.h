/*
 * 	Implements binary subtraction
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#ifndef FUNCTIONS_ARITHMETIC_SUB_H_
#define FUNCTIONS_ARITHMETIC_SUB_H_

#include "../../functions/arithmetic/ArithmeticFunction.h"

class SUB: public ArithmeticFunction  {
public:
	SUB() = default;
	virtual ~SUB() = default;
	std::vector<std::vector<int>>* execute(std::vector<std::vector<int>> *ops) override;
	std::vector<std::vector<int>>* execute(std::vector<int> *bin1,
					std::vector<int> *bin2);
};

#endif /* FUNCTIONS_ARITHMETIC_SUB_H_ */
