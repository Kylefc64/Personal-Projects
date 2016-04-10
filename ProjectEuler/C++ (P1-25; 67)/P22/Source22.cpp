/*
Using names.txt (right click and 'Save Link/Target As...'),
a 46K text file containing over five-thousand first names,
begin by sorting it into alphabetical order. Then working out the
alphabetical value for each name, multiply this value by its
alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order,
COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name
in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
*/
#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

long long nameValue(const string& name);

int main()
{
	clock_t tStart = clock(); //

	ifstream in("p022_names.txt");
	string name;
	vector<string> list;
	in.get();
	getline(in, name, '"');
	in.get();
	list.push_back(name);
	cout << "Populating vector in alpha-order...\n";
	while (in.get() != EOF)
	{
		getline(in, name, '"');
		in.get(); //extract the comma
		for (size_t i = 0; i < list.size(); i++)
		{
			if (name < list.at(i))
			{
				list.insert(list.begin() + i, name);
				break;
			}
			else if (name > list.at(i) && i + 1 == list.size())
			{
				list.push_back(name);
				break;
			}
		}
	}
	in.close();
	long long sum = 0;
	int size = list.size();
	cout << "Vector size: " << size << '\n'
		<< "Calculating sum...\n";
	for (size_t i = 0; i < size; i++)
	{
		sum += (i + 1) * nameValue(list.at(i));
	}
	cout << "Sum: " << sum << endl;

	printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC); //
	return 0;
}
/*Answer: 871198282 in 71.96s*/
long long nameValue(const string& name)
{
	long long sum = 0;
	int index = 0;
	int size = name.size();
	while (index < size)
	{
		if (name[index] == 'A')
		{
			sum += 1;
		}
		else if (name[index] == 'B')
		{
			sum += 2;
		}
		else if (name[index] == 'C')
		{
			sum += 3;
		}
		else if (name[index] == 'D')
		{
			sum += 4;
		}
		else if (name[index] == 'E')
		{
			sum += 5;
		}
		else if (name[index] == 'F')
		{
			sum += 6;
		}
		else if (name[index] == 'G')
		{
			sum += 7;
		}
		else if (name[index] == 'H')
		{
			sum += 8;
		}
		else if (name[index] == 'I')
		{
			sum += 9;
		}
		else if (name[index] == 'J')
		{
			sum += 10;
		}
		else if (name[index] == 'K')
		{
			sum += 11;
		}
		else if (name[index] == 'L')
		{
			sum += 12;
		}
		else if (name[index] == 'M')
		{
			sum += 13;
		}
		else if (name[index] == 'N')
		{
			sum += 14;
		}
		else if (name[index] == 'O')
		{
			sum += 15;
		}
		else if (name[index] == 'P')
		{
			sum += 16;
		}
		else if (name[index] == 'Q')
		{
			sum += 17;
		}
		else if (name[index] == 'R')
		{
			sum += 18;
		}
		else if (name[index] == 'S')
		{
			sum += 19;
		}
		else if (name[index] == 'T')
		{
			sum += 20;
		}
		else if (name[index] == 'U')
		{
			sum += 21;
		}
		else if (name[index] == 'V')
		{
			sum += 22;
		}
		else if (name[index] == 'W')
		{
			sum += 23;
		}
		else if (name[index] == 'X')
		{
			sum += 24;
		}
		else if (name[index] == 'Y')
		{
			sum += 25;
		}
		else if (name[index] == 'Z')
		{
			sum += 26;
		}
		index++;
	}
	return sum;
}