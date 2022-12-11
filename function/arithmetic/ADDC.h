/*
 * Implements binary addition with carry
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */


#ifndef FUNCTION_ARITHMETIC_ADDC_H_
#define FUNCTION_ARITHMETIC_ADDC_H_

#include <iostream>
#include <algorithm>

#include "ArithmeticFunction.h"

class ADDC: public ArithmeticFunction {
public:
	ADDC();
	virtual ~ADDC();
	std::vector<std::vector<int>>* execute(std::vector<std::vector<int>> *ops);
};

#endif /* FUNCTION_ARITHMETIC_ADDC_H_ */
