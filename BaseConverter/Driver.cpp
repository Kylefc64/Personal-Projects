#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Dec.h"
#include "Bin.h"
#include "Hex.h"
#include "Oct.h"

using namespace std;

void promptUser(string&, int&); //assumes valid input is entered

int main()
{
	Number* numPtr;
	int base = 0;
	string num = "";
	promptUser(num, base); //"q" to quit

	while (num != "q")
	{
		if (base == 2)
		{
			numPtr = new Bin(num);
		}
		else if (base == 8)
		{
			numPtr = new Oct(num);
		}
		else if (base == 10)
		{
			numPtr = new Dec(num);
		}
		else if (base == 16)
		{
			numPtr = new Hex(num);
		}
		else
		{
			cout << "Base " << base << " is not supported by this program.\n";
			break;
		}

		cout << "Base 2, Binary: " << numPtr->toBin() << '\n'
			<< "Base 8, Octal: " << numPtr->toOct() << '\n'
			<< "Base 10, Decimal: " << numPtr->toDec() << '\n'
			<< "Base 16, Hexadecimal: " << numPtr->toHex() << endl << endl;

		promptUser(num, base);
	}


	return 0;
}

void promptUser(string &num, int& base)
{
	cout << "Enter data in the following format: [number] [base]\n";
	cin >> num;
	if (num == "q")
	{
		return;
	}
	cin >> base;
	cin.ignore(1000, '\n');
	cout << endl;
}