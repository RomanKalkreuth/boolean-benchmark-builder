/*
 * 	Implements binary multiplication
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */


#ifndef FUNCTION_ARITHMETIC_MUL_H_
#define FUNCTION_ARITHMETIC_MUL_H_

#include "ArithmeticFunction.h"

class MUL: public ArithmeticFunction {
public:
	MUL();
	virtual ~MUL();
	std::vector<std::vector<int>>* execute(std::vector<std::vector<int>> *ops);
	std::vector<std::vector<int>>* execute(std::vector<int> *bin1,
					std::vector<int> *bin2);
};

#endif /* FUNCTION_ARITHMETIC_MUL_H_ */
