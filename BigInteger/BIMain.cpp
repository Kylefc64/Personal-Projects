/*
The purpose of this project is to develop a class BigInteger,
capable of handling multiplication, addition, and subtraction
(and eventually division)
of an integer of any number of digits
*/
#include <iostream>
#include <time.h>
#include "BigInteger.h"

using namespace std;

int main()
{
	clock_t tStart = clock(); //

	//Addition operations and constructors
	/*
	BigInteger x;
	BigInteger y(x);
	cout << x.toString() << endl;
	cout << y.toString() << endl;
	string str = "11111111111111111111"; //size = 20
	BigInteger z(str);
	cout << z.toString() << endl;
	cout << z.size() << endl;
	cout << z.capacity() << endl;
	cout << str.size() << endl;
	cout << str.capacity() << endl;
	long long lngLng = 1234567898765432123;
	cout << lngLng << endl;
	BigInteger a(lngLng);
	cout << a.toString() << endl;
	a = z;
	cout << a.toString() << endl;
	cout << a.size() << endl;
	cout << a.capacity() << endl;
	cout << z.toString() << endl;
	cout << z.size() << endl;
	cout << z.capacity() << endl;
	str = "111111111111111111111111111111";
	a = str;
	cout << a.toString() << endl;
	cout << a.size() << endl;
	cout << a.capacity() << endl;
	a = lngLng;
	cout << a.size() << endl;
	cout << a.capacity() << endl;
	cout << a.toString() << endl;
	x = y = str;
	x += y;
	cout << y.toString() << endl;
	cout << x.toString() << endl;
	y += a;
	cout << y.toString() << endl;
	cout << y.size() << endl;
	cout << y.capacity() << endl;
	y.capacity(200);
	cout << y.toString() << endl;
	cout << y.size() << endl;
	cout << y.capacity() << endl;
	y.print();
	cout << endl;
	cout << y.sumDigits() << endl;
	x = BigInteger(str);
	y = "22222222222222222222";
	z = y + x;
	cout << z.toString() << endl;
	cout << z.size() << endl;
	cout << z.capacity() << endl;
	*/
	/*
	BigInteger a = "2222222222222222222222222222222222222222222222222222222222222222222222";
	BigInteger b = "3333333333333333333333333333333333333333333333333333333333333333333333";
	cout << a.toString() << endl;
	cout << a.size() << endl;
	cout << a.capacity() << endl;
	cout << b.toString() << endl;
	cout << b.size() << endl;
	cout << b.capacity() << endl;
	a += b;
	a += a;
	for (size_t i = 0; i < 20000; i++)
	{
		a += a;
	}
	cout << a.toString() << endl;
	cout << a.size() << endl;
	cout << a.capacity() << endl;
	*/
	/*
	BigInteger x("5555555555");
	BigInteger y("5555555555");
	long long lngLng = 5555555555;
	BigInteger z = x + lngLng;
	cout << x.toString() << '\n' << lngLng << '\n';
	cout << z.toString() << endl;
	cout << z.size() << endl;
	cout << z.capacity() << endl;
	*/

	//Multiplication operations
	/*
	BigInteger x("999999999");
	BigInteger y("99999999999999999999999999999999999999999999999");
	long long lngLng = 999999999;
	x *= lngLng;
	cout << x.toString() << '\n' << x.size() << '\n' << x.capacity() << endl;
	*/

	//Subtraction operations


	printf("Time taken: %.3fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC); //
	return 0;
}