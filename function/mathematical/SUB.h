/*
 * 	Implements binary subtraction
 *
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#ifndef FUNCTION_MATHEMATICAL_SUB_H_
#define FUNCTION_MATHEMATICAL_SUB_H_

#include "MathematicalFunction.h"

class SUB: public MathematicalFunction  {
public:
	SUB();
	virtual ~SUB();
	std::vector<std::vector<int>>* execute(std::vector<std::vector<int>>* ops);
	std::vector<int>* complement(std::vector<int>* bin);
};

#endif /* FUNCTION_MATHEMATICAL_SUB_H_ */
