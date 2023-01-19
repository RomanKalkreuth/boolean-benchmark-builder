/*
 * LLS.h
 *
 *  Created on: 09.01.2023
 *      Author: roman
 */

#ifndef FUNCTIONS_LOGICAL_LLS_H_
#define FUNCTIONS_LOGICAL_LLS_H_

#include <algorithm>

#include "../../functions/logical/LogicalFunction.h"
#include "../../util/Util.h"

class LLS : public LogicalFunction{
public:
	LLS();
	virtual ~LLS();
	int execute(int *ops) override;
	std::vector<std::vector<int>>* execute(std::vector<std::vector<int>>* ops) override;
};

#endif /* FUNCTIONS_LOGICAL_LLS_H_ */
