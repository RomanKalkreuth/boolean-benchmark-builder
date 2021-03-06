/*
 * 	Implements bitwise OR
 *
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */


#ifndef FUNCTION_OR_H_
#define FUNCTION_OR_H_

#include "LogicalFunction.h"

class OR: public LogicalFunction {
public:
	OR();
	virtual ~OR();
	int execute(int *ops);
	std::vector<std::vector<int>>* execute(std::vector<std::vector<int>>* ops);
};

#endif /* FUNCTION_OR_H_ */
