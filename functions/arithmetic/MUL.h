/*
 * 	Implements binary multiplication
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */


#ifndef FUNCTIONS_ARITHMETIC_MUL_H_
#define FUNCTIONS_ARITHMETIC_MUL_H_

#include "../../functions/arithmetic/ArithmeticFunction.h"

class MUL: public ArithmeticFunction {
public:
	MUL();
	virtual ~MUL();
	std::vector<std::vector<int>>* execute(std::vector<std::vector<int>> *ops) override;
	std::vector<std::vector<int>>* execute(std::vector<int> *bin1,
					std::vector<int> *bin2);
};

#endif /* FUNCTIONS_ARITHMETIC_MUL_H_ */
