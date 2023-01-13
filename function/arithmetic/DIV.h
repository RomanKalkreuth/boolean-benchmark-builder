/*
 * 	Implements binary divison
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#ifndef FUNCTION_ARITHMETIC_DIV_H_
#define FUNCTION_ARITHMETIC_DIV_H_

#include "ArithmeticFunction.h"

class DIV : public ArithmeticFunction  {
public:
	DIV();
	virtual ~DIV();
	std::vector<std::vector<int>>* execute(std::vector<std::vector<int>> *ops) override;
};

#endif /* FUNCTION_ARITHMETIC_DIV_H_ */
