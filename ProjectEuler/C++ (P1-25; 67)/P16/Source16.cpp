/*
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?

2^1000 = 4^500 = 16^250 = 256^125
*/
#include <iostream>
#include <time.h>

using namespace std;

static const int START_SIZE = 64;
static const int POWER = 125; //125
static const int BASE = 256; //256

void doubleCapacity(int*&, int&);

int main()
{
	clock_t tStart = clock(); //

	int capacity = START_SIZE;
	int* array = new int[capacity] { 0 };
	array[0] = 1;
	int size = 1;
	//long long product;
	long long remainder;
	int index;
	for (size_t i = 0; i < POWER; i++)
	{
		index = 0;
		//product = 0;
		remainder = 0;
		do
		{
			//product = array[index] * BASE;
			//remainder += product;
			remainder += array[index] * BASE;
			array[index] = remainder % 10;
			remainder /= 10;
			index++;
			if (index == capacity)
			{
				doubleCapacity(array, capacity);
			}
			if (remainder > 0 && index == size)
			{
				size++;
			}
		} while (remainder > 0 || index <= size);
	}

	//display results
	long sum = 0;
	for (size_t i = 0; i < capacity; i++)
	{
		if (array[capacity - i - 1] != 0)
		{
			cout << array[capacity - i - 1];
			sum += array[capacity - i - 1];
		}
	}
	cout << "\n\n" << "Sum: " << sum << endl;

	printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC); //
	return 0;
}
/*Answer: 1366*/

void doubleCapacity(int*& array, int& capacity)
{
	int* temp = new int[capacity] {0};
	for (size_t i = 0; i < capacity; i++)
	{
		temp[i] = array[i];
	}
	delete[] array;
	array = new int[capacity*2] {0};
	for (size_t i = 0; i < capacity; i++)
	{
		array[i] = temp[i];
	}
	capacity *= 2;
	delete[] temp;
	temp = NULL;
}