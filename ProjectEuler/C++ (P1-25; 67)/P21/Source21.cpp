/*
Let d(n) be defined as the sum of proper divisors of n
(numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ? b,
then a and b are an amicable pair and
each of a and b are called amicable numbers.

For example, the proper divisors of 220 are
1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284.
The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
*/
#include <iostream>
#include <time.h>

using namespace std;

static const int MAX = 10000;

long long d(long long n);

int main()
{
	clock_t tStart = clock(); //

	/*int array[MAX];
	for (size_t i = 0; i < MAX; i++)
	{
		array[i] = i;
	}

	long long sum = 0;
	for (size_t a = 0; a < MAX; a++)
	{
		if (array[a] != -1)
		{
			long long b = d(a);
			if (a != b && a == d(b))
			{
				sum += a + b;
				array[b] = -1;
			}
		}
	}*/

	long long sum = 0;
	for (size_t a = 0; a < MAX; a++)
	{
			long long b = d(a);
			if (a != b && a == d(b))
			{
				sum += a;// +b;
			}
	}
	cout << sum << endl;

	printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC); //
	return 0;
}
/*Answer: 31626*/
long long d(long long n)
{
	long long sum = 1;
	long long denominator = 2;
	for (size_t i = 2; i < n / denominator; i++)
	{
		if (n % i == 0)
		{
			sum += i;
			if (n / i != i)
			{
				sum += n / i;
			}
			denominator = i;
		}
	}
	return sum;
}