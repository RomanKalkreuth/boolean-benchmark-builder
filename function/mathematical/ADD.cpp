/*
 * ADD.cpp
 *
 *  Created on: 10.01.2022
 *      Author: roman
 */

#include "ADD.h"

ADD::ADD() {

}

ADD::~ADD() {

}

/**
 *   sum = a xor b xor c
 */
std::vector<std::vector<int>>* ADD::execute(
		std::vector<std::vector<int>> *ops) {

	this->setup();
	std::vector<int>* op1 =  &ops->at(0);
	std::vector<int>* op2 =  &ops->at(1);

	result = add(op1,op2);

	return result;
}

