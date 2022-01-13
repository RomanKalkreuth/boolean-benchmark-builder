/*
 * Convert.cpp
 *
 *  Created on: 27.12.2021
 *
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 *
 */

#include "Convert.h"

Convert::Convert() {

}

Convert::~Convert() {

}

int Convert::binToInt(std::vector<int> *bin) {
	int dec = 0;
	int val = 0;
	int size = bin->size();

	for (int i = 0; i < size; i++) {
		val = bin->at(i);
		dec += (int) val * std::pow(2, i);
	}
	return dec;
}

long Convert::binToLong(std::vector<int> *bin) {
	long dec = 0;
	int val = 0;
	int size = bin->size();

	for (int i = 0; i < size; i++) {
		val = bin->at(i);
		dec += (long) val * std::pow(2, i);
	}
	return dec;
}

std::vector<int>* Convert::intToBin(int dec) {

	std::vector<int> *bin = new std::vector<int>();
	int val = 0;

	while (dec != 0) {
		val = (dec % 2 == 0 ? 0 : 1);
		bin->push_back(val);
		dec /= 2;
	}
	std::reverse(bin->begin(), bin->end());
	return bin;
}

int Convert::ctoi(char c) {
	return (int) c - '0';
}

