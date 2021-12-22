/*
 * ALU.cpp
 *
 *  Created on: 09.12.2021
 *  Author: Roman Kalkreuth
 */

#include "ALU.h"

ALU::ALU(std::vector<Function>* p_functions) {
	if (p_functions != nullptr){
		this->functions = p_functions;
	}
	else {
		throw std::invalid_argument("Function set is NULL!");
	}

}

ALU::~ALU() {

}

void build(){

}

