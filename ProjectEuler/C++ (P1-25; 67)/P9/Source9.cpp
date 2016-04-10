/*A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a2 + b2 = c2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.*/
#include<iostream>;
using namespace std;

int findProduct();

int main()
{
	cout << findProduct() << endl;

	return 0;
}
//Answer: 31875000

int findProduct()
{
	int a = 0, b = 0, c = 1000;
	int max = 1000;

	while (a<=max)
	{
		while (b<=max)
		{
			if (pow(a, 2) + pow(b, 2) == pow(c, 2) && a != b && a != c && b != c)
			{
				return a*b*c;
			}
			b++;
			c--;
		}
		max--;
		a++;
		c = max - a;
		b = a;

	}
	return -1;
}