/*
A permutation is an ordered arrangement of objects.
For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4.
If all of the permutations are listed numerically or alphabetically,
we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/
/*
Code is not needed for this problem!!
The millionth permutation is 999,999 iterations after the initial permutation...
2*9! + 6*8! + 6*7! + 2*6! + 5*5! + 1*4! + 2*3! + 1*2! + 1*1! = 999,999
In the following calculations, "+n" means that the digit above the "+"
is replaced by the nth digit to the right of the digit above the "+"
(This is effectively shifting the permutation n*(position)! times,
where position = 9! corresponds to the first digit, position = 8! to the second, etc...)
(Iterates 2*9! times:)
0123456789
+2
(Iterates 6*8! times:)
1023456789
 +6
(etc...)
2701345689
  +6
2780134569
   +2
2783014569
    +5
2783901456
     +1
2783910456
      +2
2783915046
       +1
2783915406
        +1
2783915460
*/
/*
#include <iostream>
#include <time.h>

using namespace std;

static const int SIZE = 10;
static const long long MAX = 1000000;
int min(int array[SIZE], int start, int end); //returns min value of an array between element start and end
int max(int array[SIZE], int start, int end); //returns max value of an array between element start and end
void iterate(int array[SIZE], int pivot, long long& count);

int main()
{
	clock_t tStart = clock(); //

	int digits[SIZE], array[SIZE];
	for (size_t i = 0; i < SIZE; i++)
	{
		digits[i] = i;
		array[i] = i;
	}
	long long count = 0;
	iterate(array, 0, count);

	printf("Time taken: %.3fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC); //
	return 0;
}
int min(int array[SIZE], int start, int end)
{

}
int max(int array[SIZE], int start, int end)
{

}
void iterate(int array[SIZE], int pivot, long long& count)
{
	array[pivot] = min(array, pivot + 1, SIZE - 1);
	iterate(array, pivot + 1, count);
}
*/
/*Answer: 2783915460*/