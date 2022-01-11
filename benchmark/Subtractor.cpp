/*
 * Subtractor.cpp
 *
 *  Created on: 10.01.2022
 *      Author: roman
 */

#include "Subtractor.h"

Subtractor::Subtractor(int p_bits) {
	bits = p_bits;
	inputs = bits * 2 + 1;
	outputs = bits + 1;

	table = new TruthTable(inputs, outputs);
	sub = new SUB();

}

Subtractor::~Subtractor() {
}


/**
 *
 */
void Subtractor::build() {

}
