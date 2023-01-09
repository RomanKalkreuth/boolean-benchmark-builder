/*
 * 	Abstract base class for logic functions.
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */


#ifndef FUNCTION_LOGICAL_LOGICALFUNCTION_H_
#define FUNCTION_LOGICAL_LOGICALFUNCTION_H_

#include "../Function.h"

class LogicalFunction: public Function  {
protected:
	int arity;
public:
	LogicalFunction() = default;
	virtual ~LogicalFunction() = default;
	virtual int execute(int* ops) = 0;
	//virtual int validate() = 0;
	virtual std::vector<std::vector<int>>* execute(std::vector<std::vector<int>> *ops) = 0;
};

#endif /* FUNCTION_LOGICAL_LOGICALFUNCTION_H_ */
