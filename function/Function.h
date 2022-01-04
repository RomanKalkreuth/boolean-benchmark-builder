/*
 * Function.h
 *
 *  Created on: 09.12.2021
 *  Author: Roman Kalkreuth
 */

#ifndef FUNCTION_FUNCTION_H_
#define FUNCTION_FUNCTION_H_

class Function {
public:
	Function();
	virtual ~Function();
	virtual int execute(int *ops) = 0;

	int inputs;
	int outputs;
};

#endif /* FUNCTION_FUNCTION_H_ */
