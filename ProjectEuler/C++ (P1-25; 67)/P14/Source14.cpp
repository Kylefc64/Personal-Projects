/*
The following iterative sequence is defined for the set of positive integers:

n ? n/2 (n is even)
n ? 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 ? 40 ? 20 ? 10 ? 5 ? 16 ? 8 ? 4 ? 2 ? 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. 
Although it has not been proved yet (Collatz Problem),
it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/
#include <iostream>
#include <time.h>

using namespace std;

static const long MAX = 1000000;

long seqSize(long long);

int main()
{
	clock_t tStart = clock(); //
	long long num = 1;
	long long greatestNum = num;
	long long size = seqSize(num);
	long long greatestSize = size;
	while (num < MAX)
	{
		if ((size = seqSize(num)) >= greatestSize)
		{
			greatestSize = size;
			greatestNum = num;
		}
		num++;
	}
	cout << greatestNum << endl;
	cout << greatestSize << endl;

	printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC); //
	return 0;
}
/*Answer: 837799*/
long seqSize(long long num)
{
	long long count = 1;
	while (num != 1)
	{
		if (num % 2 == 0)
		{
			num /= 2;
		}
		else
		{
			num *= 3;
			num++;
		}
		count++;
	}
	return count;
}