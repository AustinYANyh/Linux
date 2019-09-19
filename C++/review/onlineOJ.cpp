
#if 0
#include<string>

using namespace std;

int main()
{
	string s1;
	string s2;

	getline(cin, s1);
	getline(cin, s2);
	
	for (int i = 0; i < s2.length(); ++i)
	{
		for (int j = 0; j < s1.length(); ++j)
		{
			if (s1[j] == s2[i])
			{
				s1.erase(j,1);
			}
		}
	}

	cout << s1 << endl;

	return 0;
}
#endif


#include<iostream>

using namespace std;

void swap(int* a, int* b)
{
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void BubbleSort(int* array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = size - 1; j>i; --j)
		{
			if (array[j] < array[j - 1])
			{
				swap(&array[j], &array[j - 1]);
			}
		}
	}
}

int main()
{
	int n = 0;
	cin >> n;
	int size = 3 * n;
	int array[1024] = { 0 };

	for (int i = 0; i < size; ++i)
	{
		cin >> array[i];
	}

	BubbleSort(array, size);

	int a = 0;

	for (int i = 1; i <= n;++i)
	{
		if ((3 * n) % 2 != 0)
		{
			a += array[2 * i + 1];
		}
		else
		{
			a += array[2 * i];
		}
	}

	cout << a << endl;

	system("pause");
	return 0;
}