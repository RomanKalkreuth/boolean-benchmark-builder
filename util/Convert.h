/*
 * Convert.h
 *
 *  Created on: 27.12.2021
 *
 *  Author: Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 *
 */

#ifndef UTIL_CONVERT_H_
#define UTIL_CONVERT_H_

#include <vector>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <bitset>
#include <algorithm>


class Convert {
public:
	Convert();
	virtual ~Convert();
	static int binToInt(std::vector<int>* bin);
	static long binToLong(std::vector<int>* bin);
	static std::vector<int>* intToBin(int dec);
	static int ctoi(char c);
};

#endif /* UTIL_CONVERT_H_ */
