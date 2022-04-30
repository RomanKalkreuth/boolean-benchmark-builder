/*
 * Implements binary addition with carry
 *
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */


#ifndef FUNCTION_MATHEMATICAL_ADDC_H_
#define FUNCTION_MATHEMATICAL_ADDC_H_

#include "MathematicalFunction.h"
#include <iostream>
#include <algorithm>

class ADDC: public MathematicalFunction {
public:
	ADDC();
	virtual ~ADDC();
	std::vector<std::vector<int>>* execute(std::vector<std::vector<int>>* ops);
};

#endif /* FUNCTION_MATHEMATICAL_ADDC_H_ */
