/*
 * ADD.h
 *
 *  Created on: 10.01.2022
 *      Author: roman
 */

#ifndef FUNCTION_MATHEMATICAL_ADD_H_
#define FUNCTION_MATHEMATICAL_ADD_H_

#include "MathematicalFunction.h"

class ADD: public MathematicalFunction {
public:
	ADD();
	virtual ~ADD();
	std::vector<std::vector<int>>* execute(std::vector<std::vector<int>>* ops);
};

#endif /* FUNCTION_MATHEMATICAL_ADD_H_ */
