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
	virtual ~ArithmeticFunction();
	std::vector<std::vector<int>>*  add(std::vector<int> *bin1, std::vector<int> *bin2);
	std::vector<std::vector<int>>*  addc(std::vector<int> *bin1, std::vector<int> *bin2, int carry);
	virtual std::vector<std::vector<int>>* execute(std::vector<std::vector<int>>* ops);
};

#endif /* FUNCTION_ARITHMETIC_ARITHMETICFUNCTION_H_ */
