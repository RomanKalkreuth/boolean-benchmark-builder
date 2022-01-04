/*
 * ADD.h
 *
 *  Created on: 03.01.2022
 *      Author: roman
 */

#ifndef FUNCTION_MATHEMATICAL_ADD_H_
#define FUNCTION_MATHEMATICAL_ADD_H_

#include "../Function.h"

class ADD: public Function {
public:
	ADD();
	virtual ~ADD();
	int execute(int *ops);
};

#endif /* FUNCTION_MATHEMATICAL_ADD_H_ */
