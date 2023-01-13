/*
 * SUBB.h
 *
 *  Created on: 06.01.2023
 *      Author: roman
 */

#ifndef FUNCTION_ARITHMETIC_SUBB_H_
#define FUNCTION_ARITHMETIC_SUBB_H_

#include "ArithmeticFunction.h"

class SUBB: public ArithmeticFunction  {
public:
	SUBB() = default;
	virtual ~SUBB()  = default;
	std::vector<std::vector<int>>* execute(std::vector<std::vector<int>> *ops) override;
	std::vector<std::vector<int>>* execute(std::vector<int> *bin1,
					std::vector<int> *bin2);
};

#endif /* FUNCTION_ARITHMETIC_SUBB_H_ */
