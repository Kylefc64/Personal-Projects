#include "Oct.h"
#include "Bin.h"

string Oct::binConv()
{
	string sReturn = "";
	for (size_t i = 0; i < num_.length(); i++)
	{
		switch (num_[i])
		{
		case '0': sReturn.append("000"); break;
		case '1': sReturn.append("001"); break;
		case '2': sReturn.append("010"); break;
		case '3': sReturn.append("011"); break;
		case '4': sReturn.append("100"); break;
		case '5': sReturn.append("101"); break;
		case '6': sReturn.append("110"); break;
		case '7': sReturn.append("111"); break;
		}
	}
	return sReturn;
}
string Oct::toBin()
{
	string sReturn = "";
	for (size_t i = 0; i < num_.length(); i++)
	{
		switch (num_[i])
		{
		case '0': sReturn.append("000 "); break;
		case '1': sReturn.append("001 "); break;
		case '2': sReturn.append("010 "); break;
		case '3': sReturn.append("011 "); break;
		case '4': sReturn.append("100 "); break;
		case '5': sReturn.append("101 "); break;
		case '6': sReturn.append("110 "); break;
		case '7': sReturn.append("111 "); break;
		}
	}
	return sReturn;
}
string Oct::toOct()
{
	return num_;
}
string Oct::toDec()
{
	Bin bin(binConv());
	return bin.toDec();
}
string Oct::toHex()
{
	Bin bin(binConv());
	return bin.toHex();
}