/*
 * 	Implements binary subtraction
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#ifndef FUNCTION_ARITHMETIC_SUB_H_
#define FUNCTION_ARITHMETIC_SUB_H_

#include "ArithmeticFunction.h"

class SUB: public ArithmeticFunction  {
public:
	SUB();
	virtual ~SUB();
	std::vector<std::vector<int>>* execute(std::vector<std::vector<int>>* ops);
	std::vector<int>* complement(std::vector<int>* bin);
};

#endif /* FUNCTION_ARITHMETIC_SUB_H_ */
