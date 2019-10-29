#define _CRT_SECURE_NO_WARNINGS

#if 0
#include<iostream>
#include<vector>

using namespace std;

void Func(vector<int> v1, vector<int> v2)
{
	int count = 1;

	for (int i = 0; i < v2.size() - 1; ++i)
	{
		if (v2[i]>v1[i + 1])
		{
			count++;
		}
	}

	cout << count << endl;
}

int main()
{

		vector<int> v1;
		vector<int> v2;

		//v1.push_back(900); 
		//v1.push_back(940);
		//v1.push_back(950);
		//v1.push_back(1100);

		v2.push_back(910);
		v2.push_back(1200);
		v2.push_back(1120);
		v2.push_back(1130);

	Func(v1, v2);

	system("pause");
	return 0;
}
#endif

#include<iostream>
#include<vector>

using namespace std;

#if 0
int main()
{

	vector<int> v1;
	vector<int> v2;

	char c;
	int value1;
	int value2;

	while (cin >> value1)
	{
		v1.push_back(value1);
		c = cin.get();

		if (c != ' ')
		{
			break;
		}
	}

	while (cin >> value2)
	{
		v2.push_back(value2);
		c = cin.get();

		if (c != ' ')
		{
			break;
		}
	}

	int count = 1;

	for (int i = 0; i < 3; ++i)
	{
		if (v2[i]>v1[i + 1])
		{
			count++;
		}
	}

	cout << count << endl;

	return 0;
}

#endif

void replaceSpace(char*& str, int length)
{
	if (str == nullptr || length < 0)
	{
		return;
	}

	int i = 0;
	int count = 0;
	int agolength = 0;

	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			count++;
		}
		agolength++;
		i++;
	}

	if (agolength + count * 2 > length)
	{
		return;
	}

	char* tmp = new char[length];
	int j = 0;

	for (int i = 0; i<agolength; ++i)
	{
		if (str[i] == ' ')
		{
			tmp[j++] = '%';
			tmp[j++] = '2'; 
			tmp[j++] = '0';
		}
		else
		{
			tmp[j] = str[i];
			j++;
		}
	}

	str = new char[length];
	strcpy(str, tmp);
}

int main()
{

	char* str = "hello lua a";

	replaceSpace(str, 15);

	cout << str << endl;

	system("pause");
	return 0;
}