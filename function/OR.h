/*
 * OR.h
 *
 * Created on: 09.12.2021
 * Author: Roman Kalkreuth
 */

#ifndef FUNCTION_OR_H_
#define FUNCTION_OR_H_

#include "Function.h"

class OR : public Function {
public:
	OR();
	virtual ~OR();
	int execute(int op1, int op2);
};

#endif /* FUNCTION_OR_H_ */
