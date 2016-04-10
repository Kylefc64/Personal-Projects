/*
By starting at the top of the triangle below and moving
to adjacent numbers on the row below, the maximum total
from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom in triangle.txt
(right click and 'Save Link/Target As...'), a 15K text file
containing a triangle with one-hundred rows.

NOTE: This is a much more difficult version of Problem 18.
It is not possible to try every route to solve this problem,
as there are 2^99 altogether! If you could check one trillion (1012)
routes every second it would take over twenty billion years to check
them all. There is an efficient algorithm to solve it. ;o)
*/
#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

static const int ROWS = 100;

void populateArray(int**&);
void printArray(int**);
int findLongest(int**&, int**&, int, int);

int main()
{
	clock_t tStart = clock(); //

	int** array = NULL;
	populateArray(array);
	//printArray(array);

	//initialize array where recursive calls are stored
	int** rCall = new int*[ROWS];
	for (size_t i = 0; i < ROWS; i++)
	{
		rCall[i] = new int[i + 1]{ 0 };
	}

	findLongest(array, rCall, 0, 0);
	cout << rCall[0][0] << endl;

	printf("Time taken: %.3fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC); //
	return 0;
}
/*Answer: 7273 (0.006s)*/
void populateArray(int**& array)
{
	array = new int*[ROWS];
	ifstream in("p067_triangle.txt");
	int COLS = 1;
	int num = 0;
	while (in.peek() != EOF)
	{
		array[COLS - 1] = new int[COLS];
		for (size_t i = 0; i < COLS; i++)
		{
			num = 10 * (in.get() - '0');
			num += in.get() - '0';
			array[COLS - 1][i] = num;
			if (in.peek() == ' ' || in.peek() == '\n')
			{
				in.get();
			}
		}
		COLS++;
	}
	in.close();
}
void printArray(int** array)
{
	ofstream out("pyramid.txt");
	int COLS = 1;
	for (size_t i = 0; i < ROWS; i++)
	{
		if (array[i][0] < 10)
		{
			out << 0;
		}
		out << array[i][0];
		for (size_t j = 1; j < COLS; j++)
		{
			out << ' ';
			if (array[i][j] < 10)
			{
				out << 0;
			}
			out << array[i][j];
		}
		out << '\n';
		COLS++;
	}
}
int findLongest(int**& array, int**& rCall, int row, int position)
{
	if (rCall[row][position])
	{
		return rCall[row][position];
	}
	else
	{
		if (row == ROWS - 1)
		{
			return array[row][position];
		}
		else
		{
			int below = findLongest(array, rCall, row + 1, position);
			int belowRight = findLongest(array, rCall, row + 1, position + 1);
			if (below > belowRight)
			{
				return (rCall[row][position] = array[row][position] + below);
			}
			else // if (belowRight > below)
			{
				return (rCall[row][position] = array[row][position] + belowRight);
			}
		}
	}
}

//(failed) attempted solution #1
/*
int findLongest(int**& array, int**& rCall, int row, int position, int current, int& largest)
{
	current += array[row][position];
	if (rCall[row][position])
	{
	return rCall[row][position];
	}
	else
	{
	if (row == ROWS - 1) //row == 99
	{
	//cout << current << endl; //
	if (current > largest)
	{
	largest = current;
	}
	}
	else
	{
	int below = findLongest(array, rCall, row + 1, position, current, largest);
	int belowRight = findLongest(array, rCall, row + 1, position + 1, current, largest);
	os << below << '\n' << belowRight << '\n';
	if (below > belowRight)
	{
	cout << "test1\n";
	rCall[row][position] = below;
	}
	else
	{
	rCall[row][position] = belowRight;
	}
	}
	return largest;
	}
}
*/