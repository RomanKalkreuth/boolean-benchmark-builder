/*
 * SUB.h
 *
 *  Created on: 03.01.2022
 *
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#ifndef FUNCTION_MATHEMATICAL_SUB_H_
#define FUNCTION_MATHEMATICAL_SUB_H_

#include "../Function.h"

class SUB: public Function  {
public:
	SUB();
	virtual ~SUB();
	int* execute(int* ops);
	std::vector<std::vector<int>>* execute(std::vector<std::vector<int>>*);
};

#endif /* FUNCTION_MATHEMATICAL_SUB_H_ */
