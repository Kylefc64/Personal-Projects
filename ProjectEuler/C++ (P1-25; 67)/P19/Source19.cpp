/*
You are given the following information,
but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4,
but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	clock_t tStart = clock(); //

	int year = 1900;
	long long month = 1;
	long long day = 1;
	long long count = 0;
	while (year < 2001)
	{
		month = 1;
		while (month < 13)
		{
			if (month == 1)
			{
				day += 31;
			}
			else if (month == 2)
			{
				day += 28;
				/*A leap year occurs on any year evenly divisible by 4,
				but not on a century unless it is divisible by 400.*/
				if (year % 400 == 0)
				{
					day++;
				}
				else if (year % 4 == 0 && year % 100 != 0)
				{
					day++;
				}
			}
			else if (month == 3)
			{
				day += 31;
			}
			else if (month == 4)
			{
				day += 30;
			}
			else if (month == 5)
			{
				day += 31;
			}
			else if (month == 6)
			{
				day += 30;
			}
			else if (month == 7)
			{
				day += 31;
			}
			else if (month == 8)
			{
				day += 31;
			}
			else if (month == 9)
			{
				day += 30;
			}
			else if (month == 10)
			{
				day += 31;
			}
			else if (month == 11)
			{
				day += 30;
			}
			else if (month == 12)
			{
				day += 31;
			}
			month++;
			if (day % 7 == 6 && year != 1900)
			{
				count++;
			}
		}
		year++;
	}
	cout << count << endl;

	printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC); //
	return 0;
}
/*Answer: 171*/