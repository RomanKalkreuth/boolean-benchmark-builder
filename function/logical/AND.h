/*
 *  AND.h
 *
 *  Created on: 22.12.2021
 *  Author: Roman Kalkreuth
 */

#ifndef FUNCTION_AND_H_
#define FUNCTION_AND_H_

#include "../Function.h"

class AND : public Function {
public:
	AND();
	virtual ~AND();
	int execute(int *ops);
};

#endif /* FUNCTION_AND_H_ */
