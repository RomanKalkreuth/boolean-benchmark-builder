/*
 * 	Abstract base class for mathematical functions.
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#ifndef FUNCTION_ARITHMETIC_ARITHMETICFUNCTION_H_
#define FUNCTION_ARITHMETIC_ARITHMETICFUNCTION_H_

#include "../Function.h"

class ArithmeticFunction:public Function {
public:
	ArithmeticFunction();
	virtual ~ArithmeticFunction() = default;
	virtual std::vector<std::vector<int>>* execute(std::vector<std::vector<int>>* ops) = 0;
};

#endif /* FUNCTION_ARITHMETIC_ARITHMETICFUNCTION_H_ */
