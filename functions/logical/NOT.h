/*
 * NOT.h
 *
 *  Created on: 09.01.2023
 *      Author: roman
 */

#ifndef FUNCTIONS_LOGICAL_NOT_H_
#define FUNCTIONS_LOGICAL_NOT_H_

#include "../../functions/logical/LogicalFunction.h"

class NOT : public LogicalFunction  {
public:
	NOT() = default;
	virtual ~NOT() = default;
	int execute(int *ops) override;
	std::vector<std::vector<int>>* execute(std::vector<std::vector<int>>* ops) override;
};

#endif /* FUNCTIONS_LOGICAL_NOT_H_ */
