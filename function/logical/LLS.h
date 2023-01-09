/*
 * LLS.h
 *
 *  Created on: 09.01.2023
 *      Author: roman
 */

#ifndef FUNCTION_LOGICAL_LLS_H_
#define FUNCTION_LOGICAL_LLS_H_

#include <algorithm>
#include "../../util/Util.h"
#include "LogicalFunction.h"

class LLS : public LogicalFunction{
public:
	LLS();
	virtual ~LLS();
	int execute(int *ops) override;
	std::vector<std::vector<int>>* execute(std::vector<std::vector<int>>* ops) override;
};

#endif /* FUNCTION_LOGICAL_LLS_H_ */
