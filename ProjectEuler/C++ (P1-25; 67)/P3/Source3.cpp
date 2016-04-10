/*The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?*/
#include<iostream>
using namespace std;

int main()
{
	long long num = 600851475143;
	long lpf = -1;
	for (long potentialFactor = sqrt(num); potentialFactor > 1 && lpf == -1; potentialFactor--)
	{
		if (num%potentialFactor == 0)
		{
			lpf = potentialFactor;
			for (long k = 2; k <= sqrt(potentialFactor); k++)
			{
				if (potentialFactor%k == 0)
				{
					lpf = -1;
					break;
				}
			}
		}
	}
	cout << lpf << endl;

	return 0;
}