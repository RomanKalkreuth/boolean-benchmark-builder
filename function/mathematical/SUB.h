/*
 * SUB.h
 *
 *  Created on: 03.01.2022
 *      Author: roman
 */

#ifndef FUNCTION_MATHEMATICAL_SUB_H_
#define FUNCTION_MATHEMATICAL_SUB_H_

#include "../Function.h"

class SUB: public Function  {
public:
	SUB();
	virtual ~SUB();
	int execute(int *ops);
};

#endif /* FUNCTION_MATHEMATICAL_SUB_H_ */
