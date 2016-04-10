#include "Bin.h"
#include "Stack.h"

string Bin::self()
{
	return num_;
}
string Bin::toBin()
{
	int len = num_.size();
	int count = len - 1;
	int max = count;
	string str = "";
	Stack<char> stk;
	while (count >= 0)
	{
		stk.push(num_[count]);
		count--;
		if (((max - count) % 8) == 0)
		{
			stk.push(' ');
		}
	}
	count = 0;
	len = stk.size();
	while (count < len)
	{
		str += stk.pop();
		count++;
	}
	return str;
}
string Bin::toOct()
{
	stringstream str("");
	int len = num_.size();
	int reset = len % 3;
	if (reset == 0)
	{
		reset = 3;
	}
	int power = reset - 1;
	int outerCt = 0;
	int innerCt = 0;
	long long num = 0;
	while (outerCt < len)
	{
		while (innerCt < reset)
		{
			if (num_[outerCt] == '1')
			{
				num += pow(2, power);
			}
			innerCt++;
			outerCt++;
			power--;
		}
		str << num;
		num = 0;
		reset = 3;
		innerCt = 0;
		power = reset - 1;
	}
	return str.str();
}
string Bin::toDec()
{
	int len = num_.size();
	int power = len - 1;
	int count = 0;
	long long num = 0;
	while (count < len)
	{
		if (num_[count] == '1')
		{
			num += pow(2, power);
		}
		power--;
		count++;
	}
	stringstream str;
	str << num;
	return str.str();
}
string Bin::toHex()
{
	stringstream str("");
	int len = num_.size();
	int reset = len % 4;
	if (reset == 0)
	{
		reset = 4;
	}
	int power = reset - 1;
	int outerCt = 0;
	int innerCt = 0;
	long long num = 0;
	while (outerCt < len)
	{
		while (innerCt < reset)
		{
			if (num_[outerCt] == '1')
			{
				num += pow(2, power);
			}
			innerCt++;
			outerCt++;
			power--;
		}
		if (num > 9)
		{
			if (num == 10)
			{
				str << 'A';
			}
			else if (num == 11)
			{
				str << 'B';
			}
			else if (num == 12)
			{
				str << 'C';
			}
			else if (num == 13)
			{
				str << 'D';
			}
			else if (num == 14)
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
			str << num;
		}
		num = 0;
		reset = 4;
		innerCt = 0;
		power = reset - 1;
	}
	return str.str();
}