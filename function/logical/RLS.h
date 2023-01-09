/*
 * RLS.h
 *
 *  Created on: 09.01.2023
 *      Author: roman
 */

#ifndef FUNCTION_LOGICAL_RLS_H_
#define FUNCTION_LOGICAL_RLS_H_

#include "LogicalFunction.h"
#include "../../util/Util.h"
#include <algorithm>

class RLS : public LogicalFunction {
public:
	RLS() = default;
	virtual ~RLS() = default;
	int execute(int *ops) override;
	std::vector<std::vector<int>>* execute(std::vector<std::vector<int>>* ops) override;
};

#endif /* FUNCTION_LOGICAL_RLS_H_ */
