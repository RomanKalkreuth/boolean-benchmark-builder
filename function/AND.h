/*
 * AND.h
 *
 *  Created on: 22.12.2021
 *      Author: roman
 */

#ifndef FUNCTION_AND_H_
#define FUNCTION_AND_H_

#include "Function.h"

class AND : public Function {
public:
	AND();
	virtual ~AND();

	int execute(int op1, int op2);
};

#endif /* FUNCTION_AND_H_ */
