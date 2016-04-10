/*If we list all the natural numbers below 10 that are multiples of 3 or 5, 
we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.*/
#include <iostream>
using namespace std;

int main()
{
	int count = 0;
	for (size_t i = 5; i < 1000; i+=5)
	{
		count += i;
	}
	for (size_t i = 3; i < 1000; i+=3)
	{
		count += i;
	}
	for (size_t i = 15; i < 1000; i+=15)
	{
		count -= i;
	}
	cout << count << endl;

	return 0;
}