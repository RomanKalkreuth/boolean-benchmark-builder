/*
 * Convert.h
 *
 *  Created on: 27.12.2021
 *      Author: Roman Kalkreuth
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
	int binToDec(std::vector<char>* bin);
	std::vector<char>* decToBin(int dec);
};

#endif /* UTIL_CONVERT_H_ */
