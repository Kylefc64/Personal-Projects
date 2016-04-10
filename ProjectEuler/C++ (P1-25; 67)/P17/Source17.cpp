/*
If the numbers 1 to 5 are written out in words:
one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand)
inclusive were written out in words, how many letters would be used?


NOTE: Do not count spaces or hyphens. For example,
342 (three hundred and forty-two) contains 23 letters and
115 (one hundred and fifteen) contains 20 letters.
The use of "and" when writing out numbers is in compliance with British usage.
*/
#include <iostream>
#include <time.h>
#include <string>
#include <fstream>

using namespace std;

static const string one = "one";
static const string two = "two";
static const string three = "three";
static const string four = "four";
static const string five = "five";
static const string six = "six";
static const string seven = "seven";
static const string eight = "eight";
static const string nine = "nine";
static const string ten = "ten";
static const string eleven = "eleven";
static const string twelve = "twelve";
static const string thirteen = "thirteen";
static const string fourteen = "fourteen";
static const string fifteen = "fifteen";
static const string sixteen = "sixteen";
static const string seventeen = "seventeen";
static const string eighteen = "eighteen";
static const string nineteen = "nineteen";
static const string twenty = "twenty";
static const string thirty = "thirty";
static const string forty = "forty";
static const string fifty = "fifty";
static const string sixty = "sixty";
static const string seventy = "seventy";
static const string eighty = "eighty";
static const string ninety = "ninety";
static const string and = "and";
static const string hundred = "hundred";
static const int MAX = 1000;

string hundreds(int);
string tens(int);
string ones(int);
string toString(int);

int main()
{
	clock_t tStart = clock(); //

	string str = "";
	ofstream os("output.txt");
	for (size_t i = 1; i < MAX; i++)
	{
		os << toString(i) << '\n';
		str += toString(i);
	}
	str += "one thousand";
	os << "one thousand";
	os.close();
	long count = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] != '-' && str[i] != ' ')
		{
			count++;
		}
	}
	cout << count << endl;

	printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC); //
	return 0;
}
/*Answer: 21124*/

string toString(int num)
{
	string str = "";
	str += hundreds(num);
	str += tens(num);
	return str;
}
string hundreds(int num)
{

	if (num < 100)
	{
		return "";
	}
	else if (num < 200)
	{
		return one + " " + hundred;
	}
	else if (num < 300)
	{
		return two + " " + hundred;
	}
	else if (num < 400)
	{
		return three + " " + hundred;
	}
	else if (num < 500)
	{
		return four + " " + hundred;
	}
	else if (num < 600)
	{
		return five + " " + hundred;
	}
	else if (num < 700)
	{
		return six + " " + hundred;
	}
	else if (num < 800)
	{
		return seven + " " + hundred;
	}
	else if (num < 900)
	{
		return eight + " " + hundred;
	}
	else if (num < 1000)
	{
		return nine + " " + hundred;
	}
	else
	{
		return "invalid";
	}
}
string tens(int num)
{
	string str = "";
	int x = num % 100;
	if (x != 0 && num > 100)
	{
		str += " " + and + " ";
	}
	if (x < 10)
	{
		str += ones(num);
	}
	else if (x == 10)
	{
		str += ten;
	}
	else if (x == 11)
	{
		str += eleven;
	}
	else if (x == 12)
	{
		str += twelve;
	}
	else if (x == 13)
	{
		str += thirteen;
	}
	else if (x == 14)
	{
		str += fourteen;
	}
	else if (x == 15)
	{
		str += fifteen;
	}
	else if (x == 16)
	{
		str += sixteen;
	}
	else if (x == 17)
	{
		str += seventeen;
	}
	else if (x == 18)
	{
		str += eighteen;
	}
	else if (x == 19)
	{
		str += nineteen;
	}
	else if (x < 30)
	{
		str += twenty + ones(num);
	}
	else if (x < 40)
	{
		str += thirty + ones(num);
	}
	else if (x < 50)
	{
		str += forty + ones(num);
	}
	else if (x < 60)
	{
		str += fifty + ones(num);
	}
	else if (x < 70)
	{
		str += sixty + ones(num);
	}
	else if (x < 80)
	{
		str += seventy + ones(num);
	}
	else if (x < 90)
	{
		str += eighty + ones(num);
	}
	else if (x < 100)
	{
		str += ninety + ones(num);
	}

	return str;
}
string ones(int num)
{
	int x = num % 10;
	string str = "";
	if (x != 0 && num % 100 > 19)
	{
		str += '-';
	}
	if (x == 1)
	{
		str += one;
	}
	else if (x == 2)
	{
		str += two;
	}
	else if (x == 3)
	{
		str += three;
	}
	else if (x == 4)
	{
		str += four;
	}
	else if (x == 5)
	{
		str += five;
	}
	else if (x == 6)
	{
		str += six;
	}
	else if (x == 7)
	{
		str += seven;
	}
	else if (x == 8)
	{
		str += eight;
	}
	else if (x == 9)
	{
		str += nine;
	}
	return str;
}