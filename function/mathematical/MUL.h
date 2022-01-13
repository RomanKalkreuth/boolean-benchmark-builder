/*
 * MUL.h
 *
 *  Created on: 09.01.2022
 *
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#ifndef FUNCTION_MATHEMATICAL_MUL_H_
#define FUNCTION_MATHEMATICAL_MUL_H_

#include "MathematicalFunction.h"

class MUL: public MathematicalFunction {
public:
	MUL();
	virtual ~MUL();
	std::vector<std::vector<int>>* execute(std::vector<std::vector<int>>* ops);
};

#endif /* FUNCTION_MATHEMATICAL_MUL_H_ */
