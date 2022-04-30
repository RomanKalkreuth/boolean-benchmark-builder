/*
 * Class that contains various helper functions.
 *
 * Author: 	Roman Kalkreuth, roman.kalkreuth@tu-dortmund.de,
 *         	https://orcid.org/0000-0003-1449-5131,
 *          https://ls11-www.cs.tu-dortmund.de/staff/kalkreuth,
 *         	https://twitter.com/RomanKalkreuth
 */

#include "Util.h"

Util::Util() {

}

Util::~Util() {

}


unsigned long Util::pow(int x, unsigned int p)
{
  if (p == 0) return 1;
  if (p == 1) return x;

  unsigned long tmp = pow(x, p/2);
  if (p%2 == 0) return tmp * tmp;
  else return x * tmp * tmp;
}

int Util::binToInt(std::vector<int> *bin) {
	int dec = 0;
	int val = 0;
	int size = bin->size();

	for (int i = 0; i < size; i++) {
		val = bin->at(i);
		dec += (int) val * std::pow(2, i);
	}
	return dec;
}

long Util::binToLong(std::vector<int> *bin) {
	long dec = 0;
	int val = 0;
	int size = bin->size();

	for (int i = 0; i < size; i++) {
		val = bin->at(i);
		dec += (long) val * std::pow(2, i);
	}
	return dec;
}

std::vector<int>* Util::intToBin(int dec) {

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

int Util::ctoi(char c) {
	return (int) c - '0';
}


