//#pragma once
#ifndef BIN_H
#define BIN_H
#include "Number.h"
#include <sstream>

class Bin :public Number
{
public:
	Bin(string& num) :Number(num) {}
	virtual string toDec();
	virtual string toHex();
	virtual string toOct();
	virtual string toBin();
	string self();
};

#endif