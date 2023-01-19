/*
 * RLS.h
 *
 *  Created on: 09.01.2023
 *      Author: roman
 */

#ifndef FUNCTIONS_LOGICAL_RLS_H_
#define FUNCTIONS_LOGICAL_RLS_H_

#include "../../util/Util.h"
#include <algorithm>
#include "../../functions/logical/LogicalFunction.h"

class RLS : public LogicalFunction {
public:
	RLS() = default;
	virtual ~RLS() = default;
	int execute(int *ops) override;
	std::vector<std::vector<int>>* execute(std::vector<std::vector<int>>* ops) override;
};

#endif /* FUNCTIONS_LOGICAL_RLS_H_ */
