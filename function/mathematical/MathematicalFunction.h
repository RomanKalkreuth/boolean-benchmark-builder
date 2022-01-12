/*
 * MathematicalFunction.h
 *
 *  Created on: 10.01.2022
 *      Author: roman
 */

#ifndef FUNCTION_MATHEMATICAL_MATHEMATICALFUNCTION_H_
#define FUNCTION_MATHEMATICAL_MATHEMATICALFUNCTION_H_

#include "../Function.h"

class MathematicalFunction:public Function {
public:
	MathematicalFunction();
	virtual ~MathematicalFunction();
	std::vector<std::vector<int>>*  add(std::vector<int> *bin1, std::vector<int> *bin2);
	std::vector<std::vector<int>>*  addc(std::vector<int> *bin1, std::vector<int> *bin2, int carry);
	virtual std::vector<std::vector<int>>* execute(std::vector<std::vector<int>>* ops);
};

#endif /* FUNCTION_MATHEMATICAL_MATHEMATICALFUNCTION_H_ */
