/*
 * XOR.h
 *
 *  Created on: 27.12.2021
 *      Author: roman
 */

#ifndef FUNCTION_XOR_H_
#define FUNCTION_XOR_H_

#include "../Function.h"

class XOR: public Function {
public:
	XOR();
	virtual ~XOR();
	int execute(int *ops);
};

#endif /* FUNCTION_XOR_H_ */
