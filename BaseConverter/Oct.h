//#pragma once
#ifndef OCT_H
#define OCT_H
#include "Number.h"

class Oct :public Number
{
public:
	Oct(string& num) :Number(num) {}
	virtual string toDec();
	virtual string toHex();
	virtual string toOct();
	virtual string toBin();
private:
	string binConv();
};

#endif