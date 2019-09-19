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

#if 0
#include<iostream>

using namespace std;

int main()
{
	int a[5] = { 1, 3, 5, 7, 9 };
	int *p = (int *)(&a + 1);
	printf("%d,%d", *(a + 1), *(p - 1));

	system("pause");
	return 0;
}


#include<stdio.h>
int cnt = 0;
int fib(int n)
{
	cnt++;
	if (n == 0)
		return 1;
	else if (n == 1)
		return 2;
	else
		return fib(n - 1) + fib(n - 2);
}

int main()
{
	fib(8);
	printf("%d", cnt);
}
#endif

#if 0
//进制转换标准答案
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	string s;
	string table("0123456789ABCDEF");

	bool flag = false;

	int m, n;

	cin >> m;
	cin >> n;

	if (m < 0)
	{
		flag = true;
		m = 0 - m;
	}

	while (m != 0)
	{
		s += table[m%n];
		m /= n;
	}

	if (flag == true)
	{
		s += '-';
	}

	reverse(s.begin(), s.end());

	cout << s << endl;

	return 0;
}
#endif

//7.5 欧几里得放蛋糕、字符串转换整数
#if 0
#include <iostream>

using namespace std;

int main()
{
	int W;
	int H;
	cin >> W;
	cin >> H;
	
	int array[1000][1000];

	for (int i = 0; i < W; ++i)
	{
		for (int j = 0; j < H; ++j)
		{
			array[i][j] = 1;
		}
	}

	int count = 0;

	for (int i = 0; i < W ; ++i)
	{
		for (int j = 0; j < H ; ++j)
		{
			if (array[i][j] == 1)
			{
				count++;

				if ((i + 2) < W)
				{
					array[i + 2][j] = 0;
				}
				if ((j + 2) < H)
				{
					array[i][j + 2] = 0;
				}
			}
		}
	}

	cout << count << endl;

	system("pause");
	return 0;
}
#endif

//使用vector的方法
#if 0
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int W;
	int H;
	cin >> W;
	cin >> H;

	vector<vector<int>> array;

	array.resize(W);

	for (auto& e : array)
	{
		e.resize(H, 1);
	}

	int count = 0;

	for (int i = 0; i < W; ++i)
	{
		for (int j = 0; j < H; ++j)
		{
			if (array[i][j] == 1)
			{
				count++;

				if ((i + 2) < W)
				{
					array[i + 2][j] = 0;
				}
				if ((j + 2) < H)
				{
					array[i][j + 2] = 0;
				}
			}
		}
	}

	cout << count << endl;

	system("pause");
	return 0;
}
#endif

#if 0
#include <iostream>

using namespace std;

int main()
{
	int W, H;
	cin >> W >> H;

	int array[][1024] = { 0 };
}
#endif

//字符型转为整数型
#if 0
#include <iostream>
#include <string>

using namespace std;

int StrToInt(string str)
{
	if (str.empty())
	{
		return 0;
	}

	int flag = 1;

	if (str[0] == '+')
	{
		flag = 1;
		str[0] = '0';
	}
	else if (str[0] = '-')
	{
		flag = -1;
		str[0] = '0';
	}

	int res = 0;

	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] <= '0' || str[i] >= '9')
		{
			res = 0;
		}

		res = res * 10 + str[i] - '0';
	}

	return flag*res;
}

int main()
{
	string s1;

	getline(cin, s1);

	cout << StrToInt(s1)<<endl;

	system("pause");
	return 0;
}

#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stdio.h>

using namespace std;

int main()
{
	int a;
	int b;
	scanf("%2d%6d", &a, &b);
	printf("%d\n%d\n", a, b);

	system("pause");
	return 0;
}
#endif


//偶数位变为大写
#if 0
#include<stdio.h>

using namespace std;

int main()
{
	char a = 0, ch;
	while ((ch = getchar()) != '\n')
	{
		if (a % 2 != 0 && (ch >= 'a' &&ch <= 'z'))
			ch = ch - 'a' + 'A';
		a++;
		putchar(ch);
	}
	printf("\n");

	//system("pause");
	return 0;
}
#endif

//括号合法序列检测
#if 0
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;


bool chkParenthesis(string A, int n)
{
	if (n % 2 != 0)
	{
		return false;
	}

	string B(A);

	reverse(B.begin(), B.end());

	for (int i = 0; i < n; ++i)
	{
		if ((A[i] == '('&& B[i] == ')') || (A[i] == ')'&&B[i] == '(') || (A[i] == '(' && B[i] == '(') || (A[i] == ')'&&B[i] == ')'))
		{
			continue;
		}
		return false;
	}
	return true;
}


int main()
{
	string A("(()())");
	
	cout << chkParenthesis(A, 6) << endl;

	system("pause");

	return 0;
}
#endif

//括号合法序列检测(正确答案)
#if 0
class Parenthesis
{
public:
	bool chkParenthesis(string A, int n) 
	{
		stack<char> v;

		for(auto e:A)
		{
			switch(e)
			{
			case '(':v.push(e);break;
			case ')':
				if(v.empty()||v.top()!='(')
				{
					return false;
				}
				else
				{
					v.pop();
				}
				break;
			default:return false;break;
			}
		}
		return true;
	}
};
#endif

//求一个数变为斐波那契数的步数
#if 0
#include<iostream>

using namespace std;

int cre = 0;

int fib(int x)
{
	if (x == 1 || x == 2)
	{
		return 1;
	}
	int last3 = 1;//倒数第三项
	int last2 = 1;//倒数第二项
	int a = 0;//最后一项
	for (int n = 3; n <= x; ++n)
	{
		a = last3 + last2;//最后一项等于前两项之和
		last3 = last2;//新的倒数第三项
		last2 = a;//新的倒数第二项
	}
	return a;
}

int main()
{
	long long n;
	cin >> n;
	int i = 0;

	while (1)
	{
		if (fib(i) < n && n < fib(i + 1))
		{
			cout << n - fib(i) << endl;
			break;
		}
		i++;
	}

	system("pause");
	return 0;
}
#endif

//变为斐波那契数的步数(标准答案)
#include<iostream>

using namespace std;

int main()
{
	int sep1 = 0;
	int sep2 = 0;
	int f0 = 0;
	int f1 = 1;
	int f = 0;

	int n;
	while (cin >> n)
	{
		while (1)
		{
			f = f0 + f1;
			f0 = f1;
			f1 = f;

			if (f < n)
			{
				sep1 = n - f;
			}
			else
			{
				sep2 = f - n;
				break;
			}
		}

		if (sep1 < sep2)
		{
			cout << sep1 << endl;
		}
		else
		{
			cout << sep2 << endl;
		}
	}
	system("pause");
	return 0;
}


//求最小公倍数
#if 0
#include<iostream>

using namespace std;

int Func(int x, int y)
{
	if (x%y == 0)
	{
		return y;//80%40==0,80和40的最大公约数就是40
	}//80%70==10,此时继续求70和10的最大公约数,结果为10
	//那么,10就是80和70的最大公约数
	else return Func(y, x%y);
}

int main()
{
	int A;
	int B;
	int C = 0;

	cin >> A >> B;
	C = Func(A, B);

	if (A%B == 0)
	{
		cout << A << endl;
	}
	else if (B%A == 0)
	{
		cout << B << endl;
	}
	else
	{
		cout << A*B / C << endl;
	}

	system("pause");
	return 0;
}
#endif

//判断是否满足两种排序
#if 0
#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool CheckLength(vector<string> v,int n)
{
	for (int i = 1; i < n; ++i)
	{
		if (v[i - 1].length() < v[i].length())
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}

bool CheckDic(vector<string> v, int n)
{
	for (int i = 1; i<n; ++i)
	{
		if (v[i - 1] > v[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	cin >> n;

	vector<string> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	CheckLength(v,n);
	CheckDic(v,n);

	if (CheckDic(v, n) == true && CheckLength(v, n) == true)
	{
		cout << "both" << endl;
	}
	else if (CheckDic(v, n) == true && CheckLength(v, n) == false)
	{
		cout << "lexicographically" << endl;
	}
	else if (CheckDic(v, n) == false && CheckLength(v, n) == true)
	{
		cout << "lengths" << endl;
	}
	else
	{
		cout << "none" << endl;
	}

	system("pause");
	return 0;
}
#endif

//另类加法
#if 0
#include<iostream>

using namespace std;

int addAB(int A, int B)
{
	while(A!=0)
	{
		int tmp=B;
		B=A^B;
		A=A&tmp;
		A<<=1;
	}
	return B;
}

int main()
{
	int x, y;
	while (cin >> x >> y)
	{
		int c = addAB(x, y);

		cout << c << endl;
	}

	system("pause");
	return 0;
}
#endif

//n*m的棋盘走法（自己的思路）
#if 0
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;

	vector<vector<int>> vv;

	vv.resize(m+1);

	for (auto& e : vv)
	{
		e.resize(n+1, 0);
	}

	for (int i = 0; i <= m; ++i)
	{
		vv[i][0] = 1;

		for (int j = 0; j <= n; ++j)
		{
			vv[0][j] = 1;
		}
	} 

	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			vv[i][j] = vv[i - 1][j] + vv[i][j - 1];
		}
	}

	cout << vv[m][n] << endl;

	system("pause");
	return 0;
}
#endif

#if 0
#include<iostream>

using namespace std;

int Count(int m,int n)
{
	if (m == 0 || n == 0)
	{
		return 1;
	}
	return Count(m, n - 1) + Count(m - 1, n);
}

int main()
{
	int m, n;
	cin >> m >> n;

	cout << Count(m, n) << endl;

	system("pause");
	return 0;
}
#endif

#if 0
#include<iostream>

using namespace std;

int PathNum(int m, int n)
{
	if (m > 1 && n > 1)
	{
		return PathNum(m, n - 1) + PathNum(m - 1, n);
	}
	else if (((m >= 1) && n == 1) || ((m == 1) && n >= 1))
	{
		return m + n;
	}
	else
	{
		return 0;
	}
}

int main()
{
	
	int m, n;
	cin >> m >> n;

	cout << PathNum(m, n) << endl;

	system("pause");
	return 0;
}
#endif

#if 0
#include<iostream>
#include <vector>

using namespace std;

class Board
{
public:
	bool checkWon(vector<vector<int> > board)
	{
		if (board[0][0] == 1 && board[0][1] == 1 && board[0][2] == 1)
		{
			return true;
		}
		if (board[1][0] == 1 && board[1][1] == 1 && board[1][2] == 1)
		{
			return true;
		}
		if (board[2][0] == 1 && board[2][1] == 1 && board[2][2] == 1)
		{
			return true;
		}
		if (board[0][0] == 1 && board[1][0] == 1 && board[2][0] == 1)
		{
			return true;
		}
		if (board[0][1] == 1 && board[1][1] == 1 && board[2][1] == 1)
		{
			return true;
		}
		if (board[0][2] == 1 && board[1][2] == 1 && board[2][2] == 1)
		{
			return true;
		}
		if (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1)
		{
			return true;
		}
		if (board[2][2] == 1 && board[1][1] == 1 && board[0][0] == 1)
		{
			return true;
		}
		return false;
	}
};
#endif

#include<iostream>
#include <string>

using namespace std;

int GetPwdSecurityLevel(string password)
{
	int level = 0;

	//长度检测
	if (password.length() <= 4)
	{
		level += 5;
	}
	else if (password.length() >= 5 && password.length() <= 7)
	{
		level += 10;
	}
	else
	{
		level += 25;
	}

	//字母检测,符号检测,数字检测
	int AZflag = 0;
	int azflag = 0;
	int sysflag = 0;
	int count = 0;
	int syscount = 0;

	for (int i = 0; i < password.length(); ++i)
	{
		if (password[i] >= 'a'&&password[i] <= 'z') 
		{
			azflag = 1;
		}
		else if (password[i] >= 'A'&&password[i] <= 'Z')
		{
			AZflag = 1;
		}
		else if (password[i] >= '0'&&password[i] <= '9')
		{
			count++;
		}
		else
		{
			sysflag = 1;
			syscount++;
		}
	}

	//字母得分
	if (azflag == 1 && azflag == 1)
	{
		level += 20;
	}
	else if (azflag == 1 || AZflag == 1)
	{
		level += 10;
	}
	else
	{
		level += 0;
	}

	//数字得分
	if (count == 0)
	{
		level += 0;
	}
	else if (count == 1)
	{
		level += 10;
	}
	else
	{
		level += 20;
	}

	//符号得分
	if (syscount == 0)
	{
		level += 0;
	}
	else if (syscount == 1)
	{
		level += 10;
	}
	else
	{
		level += 25;
	}

	//奖励
	if ((AZflag == 1 || azflag == 1) && count > 0 && sysflag == 0)//字母,数字有,无符号
	{
		level += 2;
	}
	else if ((AZflag == 1 || azflag == 1) && count > 0 && syscount > 0)//字母符号数字都有
	{
		level += 3;
	}
	else if ((AZflag == 1 && azflag == 1) && count > 0 && syscount > 0)//大小写字母,数字,符号
	{
		level += 5;
	}
	else
	{
		level += 0;
	}

	return level;
}

int main()
{
	string pPasswordStr;

	while (getline(cin, pPasswordStr))
	{
		GetPwdSecurityLevel(pPasswordStr);

		if (GetPwdSecurityLevel(pPasswordStr) >= 90)
		{
			cout << "VERY_SECURE" << endl;
		}
		else if (GetPwdSecurityLevel(pPasswordStr) >= 80)
		{
			cout << "SECURE" << endl;
		}
		else if (GetPwdSecurityLevel(pPasswordStr) >= 70)
		{
			cout << "VERY_STRONG" << endl;
		}
		else if (GetPwdSecurityLevel(pPasswordStr) >= 60)
		{
			cout << "STRONG" << endl;
		}
		else if (GetPwdSecurityLevel(pPasswordStr) >= 50)
		{
			cout << "AVERAGE" << endl;
		}
		else if (GetPwdSecurityLevel(pPasswordStr) >= 25)
		{
			cout << "WEAK" << endl;
		}
		else if (GetPwdSecurityLevel(pPasswordStr) >= 0)
		{
			cout << "VERY_WEAK" << endl;
		}
	}

	system("pause");
	return 0;
}
