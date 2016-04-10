/*A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.*/
#include <iostream>
#include <string>
using namespace std;

void toArray(int arr[6], long num);
bool isPalindrome(long num);
long findPalindrome();
int main()
{
	cout << findPalindrome() << endl;

	return 0;
}
void toArray(int arr[6], long num)
{
	long divisor = 10;
	for (int i = 5; i >= 0; i--)
	{
		arr[i] = (num%divisor) / (divisor / 10);
		num -= arr[i] * (divisor / 10);
		divisor *= 10;
	}
}
bool isPalindrome(long num)
{
	int arr[6];
	toArray(arr, num);
	return (arr[0] == arr[5] && arr[1] == arr[4] && arr[2] == arr[3]);
}
long findPalindrome()
{
	for (int i = 999; i > 900; i--)
	{
		for (int k = 999; k > 900; k--)
		{
			if (isPalindrome(k*i))
			{
				return k*i;
			}
		}
	}
	return -1;
}