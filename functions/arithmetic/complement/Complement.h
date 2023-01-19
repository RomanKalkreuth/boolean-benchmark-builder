/*
 * 	Implements binary complement
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#ifndef FUNCTION_ARITHMETIC_COMPL_H_
#define FUNCTION_ARITHMETIC_COMPL_H_

#include <vector>

#include "../../../functions/arithmetic/ADD.h"

class Complement {
public:
	Complement();
	virtual ~Complement();
	std::vector<int>* complement(std::vector<int> *bin);
private:
	ADD* funcAdd;
};

#endif /* FUNCTION_ARITHMETIC_COMPL_H_ */
