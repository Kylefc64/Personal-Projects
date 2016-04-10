//#pragma once
#ifndef HEX_H
#define HEX_H
#include "Number.h"

class Hex :public Number
{
public:
	Hex(string& num) :Number(num) {}
	virtual string toDec();
	virtual string toHex();
	virtual string toOct();
	virtual string toBin();
private:
	string binConv();
};

#endif