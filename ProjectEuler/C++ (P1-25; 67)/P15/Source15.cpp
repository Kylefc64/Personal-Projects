/*
Starting in the top left corner of a 2×2 grid,
and only being able to move to the right and down,
there are exactly 6 routes to the bottom right corner.
(See: https://projecteuler.net/problem=15)
How many such routes are there through a 20×20 grid?
*/
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	//cout << 37 * 35 * 11 * 31 * 29 * 3 * 26 * 23 * 2 * 3 << endl; //??????
	//clock_t tStart = clock(); //
	/*
	37*35*11*31*29*3*26*23*2*3
	-----------------------------------------------------------
	*/
	//printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC); //
	return 0;
}
/*Answer: 40C20 = 137,846,528,820*/