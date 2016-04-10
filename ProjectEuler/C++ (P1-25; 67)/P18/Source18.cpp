/*
By starting at the top of the triangle below and
moving to adjacent numbers on the row below,
the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route.
However, Problem 67, is the same challenge with a triangle containing one-hundred rows;
it cannot be solved by brute force, and requires a clever method! ;o)

(See Dijkstra's Algorithms)
*/
#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

static const int ROWS = 15;
void pathSize(int**&, int row, int position, int& current, int& largest);

int main()
{
	clock_t tStart = clock(); //

	//construct an array to hold pyramid values
	int** array = new int*[ROWS];
	for (size_t i = 0; i < ROWS; i++)
	{
		array[i] = new int[i + 1];
	}

	//populate the array from "Pyramid.txt"
	ifstream is("Pyramid.txt");
	for (size_t i = 0; i < ROWS; i++)
	{
		for (size_t j = 0; j < i + 1; j++)
		{
			is >> array[i][j];
		}
		is.get();
	}
	is.close();

	//display the array to verify input
	/*for (size_t i = 0; i < ROWS; i++)
	{
		for (size_t j = 0; j < i + 1; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << '\n';
	}*/
	/*
	From any location array[i][j], one can move to array[i+1][j] or array[i+1][j+1]
	as long as j < ROWS - 1
	For any location array[i][j], a parent exists at location array[i-1][j-1] and array[i-1][j]
	as long as i > 1
	*/
	int current = 0, largest = 0;
	pathSize(array, 0, 0, current, largest);
	cout << largest << endl;

	printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC); //
	return 0;
}
/*Answer: 1074*/
void pathSize(int**& array, int row, int position, int& current, int& largest)
{
	current += array[row][position];

	//For testing purposes:
	/*static long long x = 1;
	cout << "Function call#: " << x << '\n';
	x++;
	cout << "array[" << row << "][" << position << "]: " << array[row][position] << '\n'
		<< "Current sum value: " << current << '\n'
		<< "Largest sum value: " << largest << "\n\n";*/

	if (row == ROWS - 1)
	{
		if (current > largest)
		{
			largest = current;
		}
		current -= array[row][position];
		return;
		//return current + array[row][position];
	}

	pathSize(array, row + 1, position, current, largest);

	pathSize(array, row + 1, position + 1, current, largest);

	current -= array[row][position];

	//Part of an attempt at a different solution:
	/*if (position == 0) //&& position != ROWS
	{
		int left = pathSize(array, ++row, position, current, largest);
		if (left > largest)
		{
			largest = left;
		}
	}
	int right = pathSize(array, ++row, ++position, current, largest);
	if (right > largest)
	{
		largest = right;
	}*/
}