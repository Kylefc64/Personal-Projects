#include "BigInteger.h"

//friend functions:
BigInteger operator+(const BigInteger& BI1, const BigInteger& BI2)
{
	BigInteger newBI(BI1);
	int index = 0, remainder = 0;
	while (remainder != 0 || index < BI2.size_)
	{
		/*if (index == newBI.capacity_)
		{
			newBI.doubleCapacity();
		}*/
		if (index == newBI.size_)
		{
			newBI.size_++;
			if (newBI.size_ > newBI.capacity_)
			{
				newBI.doubleCapacity();
			}
		}
		if (index < BI2.size_)
		{
			remainder += BI2.array_[index];
		}
		remainder += newBI.array_[index];
		newBI.array_[index] = remainder % 10;
		remainder /= 10;
		index++;
	}
	return newBI;
}
BigInteger operator*(const BigInteger& BI1, const BigInteger& BI2)
{
	long long size1 = BI1.size_;
	long long size2 = BI2.size_;
	BigInteger BI;
	if (size1 > size2)
	{
		BI.capacity(BI1.capacity_);
	}
	else
	{
		BI.capacity(BI2.capacity_);
	}
	long long position = 0, index1 = 0, index2 = 0;
	int remainder = 0;
	while (index2 < size2)
	{
		position = index2;
		index1 = 0;
		while (index1 < size1 || remainder != 0)
		{
			/*if (position == BI.capacity_)
			{
				BI.doubleCapacity();
			}*/
			if (position == BI.size_)
			{
				BI.size_++;
				if (BI.size_ > BI.capacity_)
				{
					BI.doubleCapacity();
				}
			}
			if (index1 < size1)
			{
				remainder += BI2.array_[index2] * BI1.array_[index1];
			}
			remainder += BI.array_[position];
			BI.array_[position] = remainder % 10;
			remainder /= 10;
			index1++;
			position++;
		}
		index2++;
	}
	return BI;
}
//BigInteger operator-(const BigInteger& BI1, const BigInteger& BI2)
//{
//
//}
BigInteger operator+(const BigInteger& bi, const long long& x)
{
	BigInteger BI(bi);
	long long num = x;
	int remainder = 0;
	int index = 0;
	while (remainder != 0 || num != 0)
	{
		/*if (index == BI.capacity_)
		{
			BI.doubleCapacity();
		}*/
		if (index == BI.size_)
		{
			BI.size_++;
			if (BI.size_ > BI.capacity_)
			{
				BI.doubleCapacity();
			}
		}
		remainder += BI.array_[index] + (num % 10);
		BI.array_[index] = remainder % 10;
		num /= 10;
		remainder /= 10;
		index++;
	}
	return BI;
}
BigInteger operator*(const BigInteger& BI, const long long& x)
{
	long long num = x;
	const long long size = BI.size_;
	BigInteger newBI;
	newBI.capacity(BI.capacity_);
	long long pivot = 0, index = 0, position = 0;
	int remainder = 0;
	while (num != 0)
	{
		index = 0;
		position = pivot;
		while (index < size || remainder != 0)
		{
			/*if (position == newBI.capacity_)
			{
				newBI.doubleCapacity();
			}*/
			if (position == newBI.size_)
			{
				newBI.size_++;
				if (newBI.size_ > newBI.capacity_)
				{
					newBI.doubleCapacity();
				}
			}
			if (index < size)
			{
				remainder += BI.array_[index] * (num % 10);
			}
			remainder += newBI.array_[position];
			newBI.array_[position] = remainder % 10;
			remainder /= 10;
			index++;
			position++;
		}
		num /= 10;
		pivot++;
	}
	return newBI;
}
//BigInteger operator-(const BigInteger& BI, const long long& num)
//{
//
//}
bool operator==(const BigInteger& BI1, const BigInteger& BI2)
{
	if (BI1.size_ != BI2.size_)
	{
		return false;
	}
	for (size_t i = 0; i < BI1.size_; i++)
	{
		if (BI1.array_[i] != BI2.array_[i])
		{
			return false;
		}
	}
	return true;
}

//public functions:
BigInteger::BigInteger()
{
	capacity_ = INITIAL_SIZE;
	array_ = new int[capacity_] { 0 };
	size_ = 0;
}
BigInteger::BigInteger(const BigInteger& BI)
{
	size_ = BI.size_;
	capacity_ = BI.capacity_;
	array_ = new int[capacity_] { 0 };
	for (size_t i = 0; i < size_; i++)
	{
		array_[i] = BI.array_[i];
	}
}
BigInteger::BigInteger(const string& str)
{
	size_ = str.size();
	capacity_ = str.capacity();
	array_ = new int[capacity_] { 0 };
	for (int i = size_ - 1, j = 0; i >= 0; i--, j++)
	{
		array_[j] = static_cast<int>(str[i]) - 48;
	}
}
BigInteger::BigInteger(const long long& num)
{
	long long temp = num;
	long long size = 0;
	while (temp % 10 != 0)
	{
		temp /= 10;
		size++;
	}
	array_ = new int[size * 2]{ 0 };
	temp = num;
	for (size_t i = 0; i < size; i++)
	{
		array_[i] = temp % 10;
		temp /= 10;
	}
	size_ = size;
	capacity_ = size * 2;
}
BigInteger::~BigInteger()
{
	delete[] array_;
	array_ = NULL;
}
BigInteger BigInteger::operator=(const BigInteger& BI)
{
	delete[] array_;
	size_ = BI.size_;
	capacity_ = BI.capacity_;
	array_ = new int[capacity_] { 0 };
	for (size_t i = 0; i < size_; i++)
	{
		array_[i] = BI.array_[i];
	}
	return *this;
}
BigInteger BigInteger::operator=(const string& str)
{
	delete[] array_;
	size_ = str.size();
	capacity_ = str.capacity();
	array_ = new int[capacity_] { 0 };
	for (size_t i = 0; i < size_; i++)
	{
		array_[i] = static_cast<int>(str[i]) - 48;
	}
	return *this;
}
BigInteger BigInteger::operator=(const long long& num)
{
	long long temp = num;
	long long size = 0;
	while (temp % 10 != 0)
	{
		temp /= 10;
		size++;
	}
	delete[] array_;
	array_ = new int[size * 2] { 0 };
	temp = num;
	for (size_t i = 0; i < size; i++)
	{
		array_[i] = temp % 10;
		temp /= 10;
	}
	size_ = size;
	capacity_ = size * 2;
	return *this;
}
BigInteger BigInteger::operator+=(const BigInteger& BI)
{
	/*BigInteger newBI((*this) + BI);
	delete[] array_;
	size_ = newBI.size_;
	capacity_ = newBI.capacity_;
	array_ = new int[capacity_] { 0 };
	for (size_t i = 0; i < size_; i++)
	{
		array_[i] = newBI.array_[i];
	}*/

	return (*this = *this + BI);
}
BigInteger BigInteger::operator*=(const BigInteger& BI)
{
	return (*this = *this * BI);
}
//BigInteger BigInteger::operator-=(const BigInteger& BI)
//{
//
//}
BigInteger BigInteger::operator+=(const long long& num)
{
	return (*this = *this + num);
}
BigInteger BigInteger::operator*=(const long long& num)
{
	return (*this = *this * num);
}
//BigInteger BigInteger::operator-=(const long long& num)
//{
//
//}
void BigInteger::capacity(long long cap)
{
	if (cap <= 0)
	{
		cap = 1;
	}
	if (size_ == 0)
	{
		capacity_ = cap;
		return;
	}
	int* temp = new int[size_] { 0 };
	for (size_t i = 0; i < size_; i++)
	{
		temp[i] = array_[i];
	}
	delete[] array_;
	array_ = new int[cap] { 0 };
	if (cap > size_)
	{
		for (size_t i = 0; i < size_; i++)
		{
			array_[i] = temp[i];
		}
		capacity_ = cap;
	}
	else
	{
		for (size_t i = 0; i < cap; i++)
		{
			array_[i] = temp[i];
		}
		capacity_ = size_ = cap;
	}
	delete[] temp;
	temp = NULL;
}
long long BigInteger::sumDigits() const
{
	long long sum = 0;
	for (size_t i = 0; i < size_; i++)
	{
		sum += array_[i];
	}
	return sum;
}
string BigInteger::toString() const
{
	ostringstream os;
	for (int i = size_ - 1; i >= 0; i--)
	{
		os << array_[i];
	}
	
	return os.str();
}
void BigInteger::print(ostream& os)
{
	for (int i = size_ - 1; i >= 0; i--)
	{
		os << array_[i];
	}
}

//private functions:
void BigInteger::doubleCapacity()
{
	int* temp = new int[size_] { 0 };
	for (size_t i = 0; i < size_; i++)
	{
		temp[i] = array_[i];
	}
	delete[] array_;
	array_ = new int[capacity_ * 2]{ 0 };
	for (size_t i = 0; i < size_; i++)
	{
		array_[i] = temp[i];
	}
	capacity_ *= 2;
	delete[] temp;
	temp = NULL;
}