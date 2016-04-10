/*

*/
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	clock_t tStart = clock(); //



	printf("Time taken: %.3fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC); //
	return 0;
}
/*Answer: */