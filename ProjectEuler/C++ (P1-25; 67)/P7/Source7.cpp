/*By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the 10 001st prime number?*/
#include <iostream>
using namespace std;

bool isPrime(long long);
int main()
{
	long count = 0;
	long long num;
	for (long long i = 2; count < 10001; i++)
	{
		num = i;
		if (isPrime(num))
		{
			count++;
		}
	}
	cout << num << endl;

	return 0;
}
bool isPrime(long long num)
{
	long long root = sqrt(num);
	for (long long i = 2; i <= root; i++)
	{
		if (num%i == 0)
		{
			return false;
		}
	}
	return true;
}