/*
A BigInteger object can represent numbers with up to
2^63 - 1 (or long long size) digits
(easily adaptable to represent numbers with even more digits
by replacing the long long type with a BigInteger type,
provided the system has enough memory...)
*/
#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <string>
#include <sstream>
#include <iostream>
//#include "BigInteger.h"

using namespace std;

class BigInteger {
	//static constants:
	static const int INITIAL_SIZE = 64;

	//friend functions:
	friend BigInteger operator+(const BigInteger&, const BigInteger&);
	friend BigInteger operator*(const BigInteger&, const BigInteger&);
	//friend BigInteger operator-(const BigInteger&, const BigInteger&);
	friend BigInteger operator+(const BigInteger&, const long long&);
	friend BigInteger operator*(const BigInteger&, const long long&);
	//friend BigInteger operator-(const BigInteger&, const long long&);
	friend bool operator==(const BigInteger&, const BigInteger&);
public:
	BigInteger();
	BigInteger(const BigInteger&);
	BigInteger(const string&);
	BigInteger(const long long&);
	~BigInteger();
	BigInteger operator=(const BigInteger&);
	BigInteger operator=(const string&);
	BigInteger operator=(const long long&);
	BigInteger operator+=(const BigInteger&);
	BigInteger operator*=(const BigInteger&);
	//BigInteger operator-=(const BigInteger&);
	BigInteger operator+=(const long long&);
	BigInteger operator*=(const long long&);
	//BigInteger operator-=(const long long&);
	long long size() const { return size_; }
	long long capacity() const { return capacity_; }
	void capacity(long long); //expands or shortens the capacity of the array without altering the contents of the array if possible
	long long sumDigits() const;
	string toString() const;
	void print(ostream& os = cout);
private:
	int* array_;
	long long size_;
	long long capacity_;

	void doubleCapacity();
};
#endif