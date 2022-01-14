/*
 * Util.h
 *
 *  Created on: 14.01.2022
 *      Author: roman
 */

#ifndef UTIL_UTIL_H_
#define UTIL_UTIL_H_

#include <vector>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <bitset>
#include <algorithm>

class Util {
public:
	Util();
	virtual ~Util();
	static unsigned long pow(int x, unsigned int p);
	static int binToInt(std::vector<int>* bin);
	static long binToLong(std::vector<int>* bin);
	static std::vector<int>* intToBin(int dec);
	static int ctoi(char c);
};

#endif /* UTIL_UTIL_H_ */
