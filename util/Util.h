/*
 * Class that contains various helper functions.
 *
 *  Author: Roman Kalkreuth,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://www.researchgate.net/profile/Roman-Kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */


#ifndef UTIL_UTIL_H_
#define UTIL_UTIL_H_

#include <vector>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <bitset>
#include <algorithm>
#include <cassert>

class Util {
public:
	Util() = default;
	virtual ~Util()  = default;
	static unsigned long pow(int x, unsigned int p);
	static int binToInt(std::vector<int> &bin);
	static long binToLong(std::vector<int>* bin);
	static std::vector<int>* intToBin(int dec);
	static unsigned long factorial(unsigned int n);
	static unsigned long binomCoeff(unsigned int n, unsigned int k);
	static int ctoi(char c);
};

#endif /* UTIL_UTIL_H_ */
