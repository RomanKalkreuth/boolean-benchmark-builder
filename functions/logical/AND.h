/*
 * 	Implements bitwise AND
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */


#ifndef FUNCTION_AND_H_
#define FUNCTION_AND_H_

#include "../../functions/logical/LogicalFunction.h"

class AND: public LogicalFunction {
public:
	AND() = default;
	virtual ~AND() = default;
	int execute(int *ops) override;
	std::vector<std::vector<int>>* execute(std::vector<std::vector<int>>* ops) override;
};

#endif /* FUNCTION_AND_H_ */
