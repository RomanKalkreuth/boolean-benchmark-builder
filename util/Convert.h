/*
 * Convert.h
 *
 *  Created on: 27.12.2021
 *      Author: Roman Kalkreuth
 */

#ifndef UTIL_CONVERT_H_
#define UTIL_CONVERT_H_

#include <vector>

class Convert {
public:
	Convert();
	virtual ~Convert();
	int binToDec(const std::vector<char>* bin);
	std::vector<char>* decToBin(int dec);
};

#endif /* UTIL_CONVERT_H_ */
