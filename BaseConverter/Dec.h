//#pragma once
#ifndef DEC_H
#define DEC_H
#include "Number.h"
#include <sstream>

class Dec :public Number
{
public:
	Dec(string& num) :Number(num) {}
	virtual string toDec();
	virtual string toHex();
	virtual string toOct();
	virtual string toBin();
private:
	string recurse(long long, int);
	string recHex(long long);
	long long toInt();
};

#endif