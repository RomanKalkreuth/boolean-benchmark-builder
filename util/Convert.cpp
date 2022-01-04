/*
 * Convert.cpp
 *
 *  Created on: 27.12.2021
 *      Author: roman
 */

#include "Convert.h"

Convert::Convert() {

}

Convert::~Convert() {

}

int Convert::binToDec(std::vector<char> *bin) {
	int dec = 0;
	int val = 0;
	int size = bin->size();
	char c;

	for (int i = 0; i < size; i++) {
		c = bin->at(i);
		val = (int) c - '0';
		dec += (int) val * std::pow(2.0, i);
	}

	return dec;
}

std::vector<char>* Convert::decToBin(int dec) {

	std::vector<char> *bin = new std::vector<char>();
	char c;

	while (dec != 0) {
		c = (dec % 2 == 0 ? '0' : '1');
		bin->push_back(c);
		dec /= 2;
	}

	std::reverse(bin->begin(), bin->end());
	return bin;

}

