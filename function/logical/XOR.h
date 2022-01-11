/*
 * XOR.h
 *
 *  Created on: 27.12.2021
 *
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#ifndef FUNCTION_XOR_H_
#define FUNCTION_XOR_H_

#include "LogicalFunction.h"

class XOR: public LogicalFunction {
public:
	XOR();
	virtual ~XOR();
	int execute(int *ops);
	std::vector<std::vector<int>>* execute(std::vector<std::vector<int>>* ops);
};

#endif /* FUNCTION_XOR_H_ */
