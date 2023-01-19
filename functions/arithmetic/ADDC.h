/*
 * Implements binary addition with carry
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */


#ifndef FUNCTIONS_ARITHMETIC_ADDC_H_
#define FUNCTIONS_ARITHMETIC_ADDC_H_

#include <iostream>
#include <algorithm>

#include "../../functions/arithmetic/ArithmeticFunction.h"

class ADDC: public ArithmeticFunction {
public:
	ADDC() = default;
	virtual ~ADDC() = default;
	std::vector<std::vector<int>>* execute(std::vector<std::vector<int>> *ops) override;
};

#endif /* FUNCTIONS_ARITHMETIC_ADDC_H_ */
