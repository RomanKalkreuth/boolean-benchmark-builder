/*
 * SUBB.h
 *
 *  Created on: 06.01.2023
 *      Author: roman
 */

#ifndef FUNCTIONS_ARITHMETIC_SUBB_H_
#define FUNCTIONS_ARITHMETIC_SUBB_H_

#include "../../functions/arithmetic/ArithmeticFunction.h"

class SUBB: public ArithmeticFunction  {
public:
	SUBB() = default;
	virtual ~SUBB()  = default;
	std::vector<std::vector<int>>* execute(std::vector<std::vector<int>> *ops) override;
	std::vector<std::vector<int>>* execute(std::vector<int> *bin1,
					std::vector<int> *bin2);
};

#endif /* FUNCTIONS_ARITHMETIC_SUBB_H_ */
