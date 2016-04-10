/*The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.*/
#include <iostream>

using namespace std;

bool isPrime(long long&);

int main()
{
	long long sum = 0;
	for (long long i = 2; i < 2000000; i++)
	{
		if (isPrime(i))
		{
			sum += i;
		}
	}
	cout << sum << endl;

	return 0;
}
//Answer: 142913828922

bool isPrime(long long& num)
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