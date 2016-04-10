#include "Dec.h"
#include "Bin.h"

string Dec::toBin()
{
	Bin bin(recurse(toInt(), 2));
	return bin.toBin();
}
string Dec::toOct()
{
	return recurse(toInt(), 8);
}
string Dec::toDec()
{
	return num_;
}
string Dec::toHex()
{
	return recHex(toInt());
}
string Dec::recurse(long long num, int base)
{
	stringstream str;
	str << num % base;
	if (num / base != 0)
	{
		return  recurse(num / base, base) + str.str();
	}
	return str.str();
}
string Dec::recHex(long long num)
{
	stringstream str;
	int mod = num % 16;
	if (mod > 9)
	{
		if (mod == 10)
		{
			str << 'A';
		}
		else if (mod == 11)
		{
			str << 'B';
		}
		else if (mod == 12)
		{
			str << 'C';
		}
		else if (mod == 13)
		{
			str << 'D';
		}
		else if (mod == 14)
		{
			str << 'E';
		}
		else //if mod == 15
		{
			str << 'F';
		}
	}
	else
	{
		str << mod;
	}

	if (num / 16 != 0)
	{
		return  recHex(num / 16) + str.str();
	}
	return str.str();
}
long long Dec::toInt()
{
	stringstream stream(num_);
	long long num;
	stream >> num;
	return num;
}