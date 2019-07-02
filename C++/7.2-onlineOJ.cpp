
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

#if 0
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
#endif


#include<iostream>
#include<vector>

using namespace std;

int main()
{
		int n;
		cin >> n;
		vector<int> v;
		v.resize(n);

		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}

		//用以返回结果，子序列的个数最小为1
		int ret = 1;

		for (int i = 1; i<n - 1; ++i)
		{
			if ((v[i - 1]<v[i] && v[i]>v[i + 1]) || (v[i - 1]>v[i] && v[i] < v[i + 1]))
			{
				++ret;
			}

			//i表示中间位置，一次需要移动2格
			//如果个数为偶数，当i=n-3时，只需要走一格就是中间位置，走2格到最后一个元素，i+1就越界了

			//if (i != n - 3)
			//{
			//	i++;
			//}
		}

	cout << ret << endl;

	system("pause");
	return 0;
}


#if 0
#include<iostream>
#include<string>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	getline(cin, s);

	reverse(s.begin(),s.end());

	cout << s << endl;

	int i = 0;

	while (s[i]!='\0')
	{
		int begin = 0;
		int end = 0;

		if (s[i] != ' ')
		{
			begin = i;

			while (s[i] != '\0' && s[i] != ' ')
			{
				i++;
			}
			end = i - 1;
		}

		while (end > begin)
		{
			char tmp = s[begin];
			s[begin] = s[end];
			s[end] = tmp;
			end--;
			begin++;
		}
	
		if (i != s.length())
		{
			i++;
		}
	}

	cout << s << endl;

	system("pause");
	return 0;
}
#endif