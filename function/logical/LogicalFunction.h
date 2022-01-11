/*
 * LogicalFunction.h
 *
 *  Created on: 10.01.2022
 *      Author: roman
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
