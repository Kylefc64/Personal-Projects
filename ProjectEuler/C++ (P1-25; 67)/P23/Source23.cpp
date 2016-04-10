/*
A perfect number is a number for which the sum of its proper divisors
is exactly equal to the number. For example, the sum of the proper divisors
of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is
less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16,
the smallest number that can be written as the sum of two abundant numbers is 24.
By mathematical analysis, it can be shown that all integers greater than 28123 can be
written as the sum of two abundant numbers. However, this upper limit cannot be reduced
any further by analysis even though it is known that the greatest number that cannot be
expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/
/*Answer: 4179871 in 360.664s*/
#include <iostream>
#include <time.h>

using namespace std;

static const int MAX = 28123;

bool isAbundant(long long);

int main()
{
	clock_t tStart = clock(); //

	/*cout << isAbundant(114) << '\n';
	cout << isAbundant(176) << '\n';
	cout << isAbundant(196) << '\n';
	cout << isAbundant(222) << '\n';
	cout << isAbundant(246) << '\n';
	cout << isAbundant(270) << '\n';
	cout << isAbundant(54) << '\n';*/

	long long sum = 0;
	long long half = 0;
	bool flag = false;
	long long i = 12;
	for (long long num = 0; num <= MAX; num++)
	{
		half = num / 2;
		flag = false;
		for (i = 12; i <= half; i++)
		{
			if (isAbundant(i) && isAbundant(num - i))
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			sum += num;
			cout << num << endl;
			cout << sum << endl;
		}
	}
	cout << sum << '\n';

	printf("Time taken: %.3fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC); //
	return 0;
}
bool isAbundant(long long num)
{
	long long denominator = 2;
	long long sum = 1;
	for (size_t i = 2; i < num / denominator; i++)
	{
		if (num % i == 0 && num / i > i)
		{
			sum += i + (num / i);
			denominator = i;
		}
		else if (num % i == 0 && num / i == i)
		{
			sum += i;
			denominator = i;
		}
	}
	if (sum > num)
	{
		return true;
	}
	else
	{
		return false;
	}
}