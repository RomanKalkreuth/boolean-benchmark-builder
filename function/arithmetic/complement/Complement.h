/*
 * COMPL.h
 *
 *  Created on: 11.12.2022
 *      Author: roman
 */

#ifndef FUNCTION_ARITHMETIC_COMPL_H_
#define FUNCTION_ARITHMETIC_COMPL_H_

#include <vector>
#include "../ADD.h"

class Complement {
public:
	Complement();
	virtual ~Complement();
	std::vector<int>* complement(std::vector<int> *bin);
private:
	ADD* funcAdd;
};

#endif /* FUNCTION_ARITHMETIC_COMPL_H_ */
