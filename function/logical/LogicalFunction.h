/*
 * 	Abstract base class for logic functions.
 *
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */


#ifndef FUNCTION_LOGICAL_LOGICALFUNCTION_H_
#define FUNCTION_LOGICAL_LOGICALFUNCTION_H_

#include "../Function.h"

class LogicalFunction: public Function  {
public:
	LogicalFunction();
	virtual ~LogicalFunction();
	virtual int execute(int* ops) = 0;
};

#endif /* FUNCTION_LOGICAL_LOGICALFUNCTION_H_ */
