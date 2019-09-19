//7.1 在s1字符串中去除s2字符串的内容
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

//在s1字符串中去除s2字符串的内容,更优解(映射,把s1中没有s2的部分拿出来用ret存起来)
#if 0
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s1;
	string s2;

	getline(cin, s1);
	getline(cin, s2);

	int hashtable[256] = { 0 };

	for (int i = 0; i < s2.length(); ++i)
	{
		hashtable[s1[i]]++;
	}

	string ret;

	for (int i = 0; i < s1.length(); ++i)
	{
		if (hashtable[s1[i]] == 0)
		{
			ret += s1[i];
		}
	}

	cout << ret << endl;

	return 0;
}
#endif


#if 0
#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n = 0;
	long long a = 0;

	while (cin >> n)
	{

		vector<int> array(3 * n);

		for (int i = 0; i < 3*n; ++i)
		{
			cin >> array[i];
		}

		sort(array.begin(), array.end());

		for (int i = 1; i <= n; ++i)
		{
			a += array[3 * n - 2 * i];
		}

		cout << a << endl;
	}

	system("pause");
	return 0;
}
#endif


#if 0
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
#endif

//自己写的单词逆置
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


//单词逆置
#if 0
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	string s;
	getline(cin, s);

	reverse(s.begin(), s.end());

	auto start = s.begin();

	while (start != s.end())
	{
		auto end = start;

		while (*end != ' ' && end != s.end())
		{
			end++;
		}

		//走到这里说明遇到空格,一个单词已经遍历完,开始逆置
		reverse(start, end);

		if (end != s.end())
		{
			start = end + 1;
		}
		else
		{
			start = end;
		}
	}

	cout << s << endl;

	return 0;
}
#endif

//单词逆置的更优解法
#if 0
#include <iostream>
#include<string>

using namespace std;

int main()
{
	string s1;
	string s2;

	cin >> s1;

	while (cin >> s2)
	{
		s1 = s2 + ' ' + s1;
	}

	cout << s1 << endl;

	system("pause");
	return 0;
}
#endif


//计算糖果
#if 0
#include<iostream>

using namespace std;

int main()
{
	int a, b, c, d;

	int A = 0;
	int B = 0;
	int C = 0;

	while (cin >> a >> b >> c >> d)
	{
		A = (a + c) >> 1;
		C = (d - b) >> 1;
		B = (c - a) >> 1;

		if (((c - a) >> 1) == ((b + d) >> 1))
		{
			cout << A << ' ' << B << ' ' << C << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}

	system("pause");
	return 0;
}
#endif


#if 0
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	getline(cin, s);

	int i = 0;
	int count = 0;
	while (s[i+1])
	{
		if (s[i + 1] == s[i] + 1)
		{
			count++;
			i++;
		}
		else if (s[i + 1] == s[i] + 1 && count != 1)
		{
			count = 0;
			count++;
			i++;
		}
		else
		{
			count = 0;
			i++;
		}

		if (s[i + 1] == '\0')
		{
			cout << count + 1 << endl;
		}
	}


	system("pause");
	return 0;
}
#endif

//非递增,非递减,求出排序子序列的个数
#if 0
#include<iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v(n + 1);

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	int i = 0;
	int count = 0;

	while (i < n)
	{
		if (v[i] < v[i + 1])
		{
			while (i < n && v[i] <= v[i + 1])
			{
				i++;
			}
			count++;
			i++;;
		}
		else if (v[i] == v[i + 1])
		{
			i++;
		}
		else
		{
			while (i < n && v[i] >= v[i + 1])
			{
				i++;
			}
			count++;
			i++;
		}
	}

	cout << count << endl;

	return 0;
}
#endif

//进制转换(目前只通过70%)
#if 0
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int M;
	int N;

	vector<int> v;

	while (cin >> M >> N)
	{
		while (M != 0)
		{
			v.push_back(M%N);
			M /= N;
		}

		if (N <= 9)
		{
			vector<int>::reverse_iterator rit = v.rbegin();

			while (rit != v.rend())
			{
				cout << *rit;
				rit++;
			}
		}
		else
		{
			vector<int>::reverse_iterator rit = v.rbegin();

			while (rit != v.rend())
			{
				switch (*rit)
				{
				case 10:cout << 'A';
					break;
				case 11:cout << 'B';
					break;
				case 12:cout << 'C';
					break;
				case 13:cout << 'D';
					break;
				case 14:cout << 'E';
					break;
				case 15:cout << 'F';
					break;
				default:cout << *rit;
					break;
				}
				rit++;
			}
		}
	}

	return 0;
}
#endif

#if 0
#include<iostream>

using namespace std;

int func()
{
	int i, j, k = 0;
	for (i = 0, j = -1; j = 0; i++, j++)
	{
		k++;
	}
	return k;
}

int main()
{
	cout << (func());

	system("pause");
	return 0;
}
#endif

//找出最长的连续数字串(判断和保存要在遍历的时候就做)
#if 0
#include<iostream>
#include <string>

using namespace std;

int main()
{
	string s1;
	string s2;
	string s3;

	cin >> s1;

	for (int i = 0; i < s1.length(); ++i)
	{
		if (s1[i] >= '0'&&s1[i] <= '9')
		{
			s2 += s1[i];
		}
		else
		{
			if (s3.size() > s2.size())
			{
				s2.clear();
			}
			else
			{
				s2 = s3;
			}
		}
	}

	cout << s2 << endl;

	return 0;
}
#endif

//找出数组中出现一半以上的数
#if 0
class Solution
{
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		if (numbers.empty())
		{
			return 0;
		}

		int time = 1;

		int result = numbers[0];

		for (int i = 1; i < numbers.size(); ++i)
		{
			if (time==0)
			{
				result = numbers[i];
			}
			else if (numbers[i] == result)
			{
				time++;
			}
			else
			{
				time--;
			}
		}

		time = 0;

		for (int i = 0; i < numbers.size(); ++i)
		{
			if (numbers[i]==result)
			{
				time++;
			}
		}

		if (time>(numbers.size() >> 1))
		{
			return numbers[numbers.size() >> 1];
		}
		else
		{
			return 0;
		}

	}
};
#endif

//7.4插入字符串返回能成为回文串的方法数(不改变原串就要借别的来存,编程思想)
#if 0
#include<iostream>
#include <algorithm>
#include <string>

using namespace std;

bool Check(string& s1)
{
	string s2(s1);
	
	reverse(s1.begin(), s1.end());

	if (s1 == s2)
	{
		return true;
	}
	return false;
}

int main()
{
	string s1;
	string s2;

	getline(cin, s1);
	getline(cin, s2);

	int res = 0;

	string s3(s1);

	for (int i = 0; i < s1.length(); ++i)
	{
			s3.insert(i, s2);

			if (Check(s3))
			{
				res++;
			}

			s3 = s1;
	}

	cout << res << endl;

	system("pause");
	return 0;
}
#endif

#if 0
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s1;
	getline(cin, s1);

	s1.insert(0, "ABC");

	cout << s1 << endl;

	system("pause");
	return 0;
}
#endif

//返回连续子数组的和的最大值
#if 0
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	long long n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < v.size(); ++i)
	{
		cin >> v[i];
	}

	int sum = 0;
	int max = v[0];

	for(int i = 0; i<v.size(); ++i)
	{
		sum += v[i];

		if (sum>max)
		{
			max = sum;
		}

		if (sum < 0)
		{
			sum = 0;
		}
	}

	cout << max << endl;

	return 0;
}
#endif