/*
 * 	Abstract base class for mathematical functions.
 *
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
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
