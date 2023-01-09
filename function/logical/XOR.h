/*
 * 	Implements bitwise exclusive or
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#ifndef FUNCTION_XOR_H_
#define FUNCTION_XOR_H_

#include "LogicalFunction.h"

class XOR: public LogicalFunction {
public:
	XOR() = default;
	virtual ~XOR() = default;
	int execute(int *ops) override;
	std::vector<std::vector<int>>* execute(std::vector<std::vector<int>>* ops) override;
};

#endif /* FUNCTION_XOR_H_ */
