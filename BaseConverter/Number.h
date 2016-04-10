//#pragma once
#ifndef NUMBER_H
#define NUMBER_H
#include <string>

using namespace std;

class Number
{
protected:
	string num_;
public:
	Number(string& num) :num_(num) {}
	virtual string toDec() = 0;
	virtual string toHex() = 0;
	virtual string toOct() = 0;
	virtual string toBin() = 0;
};

#endif