/*
The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:

F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144
The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
*/
#include <iostream>
#include <time.h>

using namespace std;

static const int MAX = 1000;

int main()
{
	clock_t tStart = clock(); //

	int Fn[3][MAX + 1];
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < MAX + 1; j++)
		{
			Fn[i][j] = -1;
		}
	}
	Fn[0][0] = Fn[1][0] = 1;
	Fn[2][0] = Fn[0][0] + Fn[1][0];
	long long index = 3;
	int digits[3];
	digits[0] = digits[1] = digits[2] = 1;
	long long remainder = 0;
	int arrIndex = 0;
	int currInd, prevInd, nextInd;
	currInd = index % 3;
	prevInd = (index + 2) % 3;
	nextInd = (index + 1) % 3;
	while (digits[currInd] < MAX)
	{
		currInd = index % 3;
		prevInd = (index + 2) % 3;
		nextInd = (index + 1) % 3;
		arrIndex = 0;
		do
		{
			if (Fn[prevInd][arrIndex] != -1)
			{
				remainder += Fn[prevInd][arrIndex];
			}
			if (Fn[nextInd][arrIndex] != -1)
			{
				remainder += Fn[nextInd][arrIndex];
			}
			Fn[currInd][arrIndex] = remainder % 10;
			remainder /= 10;
			arrIndex++;
			if (Fn[currInd][arrIndex] == -1 && (remainder > 0 || Fn[prevInd][arrIndex] != -1 || Fn[nextInd][arrIndex] != -1))
			{
				Fn[currInd][arrIndex] = 0;
				digits[currInd]++;
			}
		} while (remainder > 0 || Fn[prevInd][arrIndex] != -1 || Fn[nextInd][arrIndex] != -1);
		index++;
	}
	cout << "Index of first 1000 digit Fibonacci number: " << index << '\n';
	for (size_t i = 0; i < MAX; i++)
	{
		cout << Fn[currInd][i];
	}
	cout << '\n';
	printf("Time taken: %.3fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC); //
	return 0;
}
/*Answer: 4782*/