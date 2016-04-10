/*
n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/
#include <iostream>
#include <time.h>

using namespace std;

static const int MAX_SIZE = 201;
static const int FACTORIAL = 100;

void factorial(int[MAX_SIZE], int);

int main()
{
	clock_t tStart = clock(); //

	int array[MAX_SIZE] = { 0 };
	array[0] = 1;
	factorial(array, FACTORIAL);
	int count = 0;
	for (size_t i = 0; i < MAX_SIZE; i++)
	{
		count += array[i];
	}
	cout << count << endl;
	
	printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC); //
	return 0;
}
/*Answer: 648*/
void factorial(int array[MAX_SIZE], int fact)
{
	if (fact == 1)
	{
		return;
	}
	long long remainder = 0;
	int index = 0;
	do
	{
		remainder += array[index] * fact;
		array[index] = remainder % 10;
		remainder /= 10;
		index++;
	} while (remainder > 0 || index < MAX_SIZE);
	return factorial(array, fact - 1);
}