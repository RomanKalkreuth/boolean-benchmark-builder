/*
 * 	Abstract base class for logical and mathematical functions.
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#ifndef FUNCTION_FUNCTION_H_
#define FUNCTION_FUNCTION_H_

#include <vector>
#include <exception>
#include <iostream>

class Function {
public:
	Function();
	virtual ~Function();
	virtual std::vector<std::vector<int>>* execute(std::vector<std::vector<int>>* ops) = 0;
protected:
	std::vector<int>* res;
	std::vector<std::vector<int>>* result;
	void setup();
};

#endif /* FUNCTION_FUNCTION_H_ */
