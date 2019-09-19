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

//j=0当作循环判断,意思是,j如果是用0来赋值,就为真,进入循环,这里j=-1,是用-1赋值,循环条件为假,不进入循环
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
#if 0
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
#endif

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

//求最小公倍数(标准答案)
#if 0
#include<iostream>

using namespace std;

int Func(int A, int B)
{
	int C;
	while (C = A%B)
	{
		A = B;
		B = C;
	}
	return B;
}
int main()
{
	int A, B;

	while (cin >> A >> B)
	{


		cout << A*B / Func(A,B) << endl;
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

#if 0
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
#endif


#if 0
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string Func(int m, int n)
{
	string s;
	string table("0123456789ABCDEF");

	bool flag = false;

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

	return s;
}

int main()
{
	int A;
	while (cin >> A)
	{
		string s;
		s = Func(A, 2);

		string s1;
		string s2;

		int count = 0;
		int max = 0;

		for (size_t i = 0; i < s.length(); ++i)
		{
			while (s[i] == '1')
			{
				count++;
				i++;

				if (i == s.size())
				{
					break;
				}
			}

			if (count >= max)
			{
				max = count;
				count = 0;
			}
		}

		cout << max << endl;
	}

	system("pause");
	return 0;
}
#endif

#if 0
#include<iostream>

using namespace std;

class Test{
public:
	int a;
	int b;
	virtual void fun() {}
	Test(int temp1 = 0, int temp2 = 0)
	{
		a = temp1;
		b = temp2;
	}
	int getA()
	{
		return a;
	}
	int getB()
	{
		return b;
	}
};
int main()
{
	Test obj(5, 10);
	// Changing a and b
	int* pInt = (int*)&obj;
	*(pInt + 0) = 100;
	*(pInt + 1) = 200;
	cout << "a = " << obj.getA() << endl;
	cout << "b = " << obj.getB() << endl;
	return 0;
}
#endif

#if 0
#include<iostream>

class UnusualAdd 
{
public:
	int addAB(int A, int B)
	{
		int sum = 0;
		int C = 0;

		while (B != 0)
		{
			sum = A^B;
			C = (A&B) << 1;
			A = sum;
			B = C;
		}
		return sum;
	}
};
#endif

//跳石板,没做出来
#if 0
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void divnumber(int n, vector<int>& divNum)
{
	for (int i = 2; i < n; ++i)
	{
		if (n % i == 0)
		{
			divNum.push_back(i);
			continue;
		}
	}
}

int jump(int n, int m)
{
	vector<int> sepNum(m + 1, 0);
	sepNum[n] = 1;

	for (int i = n; i < m; ++i)
	{
		vector<int> divNum;

		if (divNum[i] == 0)
		{
			continue;
		}

		divnumber(i, divNum);

		for (int j = 0; j < divNum.size(); ++j)
		{
			if ((divNum[j] + 1) <= m&&sepNum[divNum[j] + 1] != 0)
			{
				sepNum[divNum[j] + 1] = min(sepNum[divNum[j] + 1], sepNum[i] + 1);
			}
			else if ((divNum[j] + 1) <= m)
			{
				sepNum[divNum[j] + 1] = sepNum[i] + 1;
			}
		}
	}

	if (sepNum[m] == 0)
	{
		return -1;
	}
	else
	{
		return sepNum[m] - 1;
	}
}

int main()
{
	int n;
	int m;

	while (cin >> n >> m)
	{
		cout << jump(n, m) << endl;
	}

	system("pause");
	return 0;
}
#endif

//参数解析(标准答案)
#if 0
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	string s;

	while (getline(cin, s))
	{
		bool flag = false;

		vector<string> v;

		string s1;

		for (int i = 0; i < s.size(); ++i)
		{
			if (flag)
			{
				if (s[i] != '\"')
				{
					s1 += s[i];
				}
				else
				{
					flag = false;
				}
			}
			else
			{
				if (s[i] == ' ')
				{
					v.push_back(s1);
					s1 = "";
				}
				else if (s[i] == '\"')
				{
					flag = true;
				}
				else
				{
					s1 += s[i];
				}
			}
		}
		v.push_back(s1);
		cout << v.size() << endl;

		for (auto e : v)
		{
			cout << e << endl;
		}
	}

	return 0;
}
#endif

//计算当前天数
#if 0
#include<iostream>
#include<vector>

using namespace std;

bool isYear(int year)
{
	if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0)
	{
		return true;
	}
	return false;
}

int GetMonthDay(int year, int month)
{
	vector<int> days{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (isYear(year) == true)
	{
		days[2] = 29;
	}
	return days[month];
}

int Description(int year, int month, int day)
{
	int sum = 0;

	for (int i = 1; i < month; ++i)
	{
		sum += GetMonthDay(year, i);
	}
	sum += day;

	return sum;
}

int main()
{
	int year, month, day;

	while (cin >> year >> month >> day)
	{
		cout << Description(year, month, day) << endl;
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
	
	while (cin >> n)
	{
		vector<int> v(n);

		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}
		int plus = 0;
		int XxX = 1;

		int count = 0;

		while (v.size() > 1)
		{
			for (auto e : v)
			{
				plus += e;
				XxX *= e;
			}

			if (plus > XxX)
			{
				count++;
			}
			v.pop_back();

			plus = 0;
			XxX = 1;
		}
		cout << count << endl;
	}

	system("pause");
	return 0;
}
#endif

//找出二进制1的个数
#if 0
#include<iostream>

using namespace std;

int findNumberOf1(int num)
{
	int count = 0;

	while (num)
	{
		if ((num & 1) == 1)
		{
			count++;
		}
		num >>= 1;
	}
	return count;
}

int main()
{
	int n;

	while (cin >> n)
	{
		cout << findNumberOf1(n) << endl;
	}

	system("pause");
	return 0;
}
#endif

#if 0
//手套(标准答案)
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Gloves 
{
public:
	int findMinimum(int n, vector<int> left, vector<int> right) 
	{
		int left_sum = 0, left_min = INT_MAX;
		int right_sum = 0, right_min = INT_MAX;
		int sum = 0;

		//遍历每一种颜色的左右手套序列
		for (int i = 0; i < n; i++)
		{
			//对于有0存在的颜色手套，累加
			if (left[i] * right[i] == 0)
			{
				sum += left[i] + right[i];
			}

			//对于左右手都有的颜色手套，执行累加-最小值+1
			//找到最小值和总数
			else
			{
				left_sum += left[i];
				right_sum += right[i];
				left_min = min(left_min, left[i]);
				right_min = min(right_min, right[i]);
			}
		}

		//结果为有左右都有数量的手套序列的结果+有0存在的手套数+最后再加一肯定就能保证了
		return sum + min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
	}
};
#endif


#if 0
class Gloves
{
public:
	int findMinimum(int n, vector<int> left, vector<int> right) 
	{
		int sum = 0;
		int left_sum = 0;
		int right_sum = 0;
		int left_min = INT_MAX;
		int right_min = INT_MAX;

		for (int i = 0; i < n; ++i)
		{
			if (left[i] * right[i] == 0)
			{
				sum += left[i] + right[i];
			}
			else
			{
				left_sum += left[i];
				right_sum += right[i];
				left_min = min(left_min, left[i]);
				right_min = min(right_min, right[i]);
			}
		}
		return sum + min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
	}
};
#endif


//统计完全数个数
#if 0
#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

bool isPerferctNum(int num)
{
	int sum = 0;
	vector<int> v;
	
	for (int i = 1; i < num; ++i)
	{
		if ((num%i) == 0)
		{
			v.push_back(i);
		}
	}

	for (int i = 0; i < v.size(); ++i)
	{
		sum += v[i];
	}

	if (sum == num)
	{
		return true;
	}
	return false;
}

int FindPerNum(int n)
{
	int count = 0;

	for (int i = 0; i < n;++i)
	{
		if (isPerferctNum(i+1) == true)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	int n;

	while (cin >> n)
	{
		cout << FindPerNum(n) << endl; 
	}

	system("pause");
	return 0;
}
#endif

#if 0
//扑克牌大小比较
#include<iostream>
#include<string>

using namespace std;

void ComPare(string& A, string& B)
{
	string s = "345678910JQKA2";

	if (A == "joker JOKER" || B == "joker JOKER")
	{
		cout << "joker JOKER" << endl;
	}
	else if (A.size() == 7 && B.size() != 7)
	{
		cout << A << endl;
	}
	else if (B.size() == 7 && A.size() != 7)
	{
		cout << B << endl;
	}
	else if ((A.size() == B.size()))
	{
		if (A == "JOKER" || B == "JOKER")
		{
			cout << "JOKER" << endl;
		}
		else if ((A == "joker"&&B != "JOKEr") || (B == "joker"&&A != "JOKER"))
		{
			cout << "joker" << endl;
		}

		cout << ((A > B) ? A : B) << endl;
	}
	else if ((A.size() == 2 && B.size() == 1) ||
		(B.size() == 2 && A.size() == 1) ||
		(A.size() == 5 && B.size() == 3) ||
		(B.size() == 5 && A.size() == 3))
	{
		if (s.find(A[0]) > s.find(B[0]))
		{
			cout << A << endl;
		}
		else
		{
			cout << B << endl;
		}
	}
	else if (A.size() > 7 && B.size() > 7)
	{
		if (s.find(A[0]) > s.find(B[0]))
		{
			cout << A << endl;
		}
		else
		{
			cout << B << endl;
		}
	}
	else
	{
		cout << "ERROR" << endl;
	}
}

int main()
{
	string s;

	while (getline(cin, s))
	{
		int position = s.find('-');
		string A = s.substr(0, position);
		string B = s.substr(position + 1);

		ComPare(A, B);
	}

	system("pause");
	return 0;
}
#endif

//超长正整数相加
#if 0
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string AddLongInt(string A, string B)
{
	string C;

	if (A.size() > B.size())
	{
		int n = A.size() - B.size();

		while (n)
		{
			B.insert(B.begin(), '0');
			n--;
		}
	}
	else
	{
		int n = B.size() - A.size();

		while (n)
		{
			A.insert(A.begin(), '0');
			n--;
		}
	}

	for (auto& e : A)
	{
		e -= '0';
	}
	for (auto& e : B)
	{
		e -= '0';
	}

	for (int i = A.size() - 1; i >= 0; --i)
	{
		if ((A[i] + B[i]) >= 10)
		{
			if (i != 0)
			{
				A[i - 1] += 1;
			}

			if (i == 0)
			{
				C.insert(C.begin(), A[i] + B[i]);
			}
			else
			{
				C.insert(C.begin(), (A[i] + B[i]) % 10);
			}
		}
		else
		{
			C.insert(C.begin(), A[i] + B[i]);
		}
	}

	//for (auto& e : C)
	//{
	//	e += '0';
	//}

	//reverse(C.begin(),C.end());

	return C;
}

int main()
{
	string A;
	string B;

	while (cin >> A >> B)
	{
		cout << AddLongInt(A, B) << endl;
	}

	system("pause");
	return 0;
}
#endif

#if 0
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string AddLongInt(string A, string B)
{
	string C;

	if (A.size() > B.size())
	{
		int n = A.size() - B.size();

		while (n)
		{
			B.insert(B.begin(), '0');
			n--;
		}
	}
	else
	{
		int n = B.size() - A.size();

		while (n)
		{
			A.insert(A.begin(), '0');
			n--;
		}
	}

	int flag = 0;

	for (int i = A.size() - 1; i >= 0; --i)
	{
		int temp = (A[i] - '0') + (B[i] - '0') + flag;
		C += char((temp % 10) + '0');
		flag = temp / 10;
	}

	if (flag == 1)
	{
		C += '1';
	}
	//for (auto& e : C)
	//{
	//	e += '0';
	//}

	reverse(C.begin(),C.end());

	return C;
}

int main()
{
	string A;
	string B;

	while (cin >> A >> B)
	{
		cout << AddLongInt(A, B) << endl;
	}

	system("pause");
	return 0;
}
#endif

//杨辉三角变形(找规律)
#if 0
#include<iostream>

using namespace std;

int main()
{
	int n;

	while (cin >> n)
	{
		if (n <= 2)
		{
			cout << -1 << endl;
		}
		else if (n % 2 != 0)
		{
			cout << 2 << endl;
		}
		else if (n % 4 == 0)
		{
			cout << 3 << endl;
		}
		else
		{
			cout << 4 << endl;
		}
	}

	return 0;
}
#endif


//字符串通配符
#if 0
#include<iostream>
#include<string>

using namespace std;

bool stringMatch(string A, string B)
{
	//te?t*.*
	//txt12.xls
	int i = 0;

	for (i; i < A.size(); ++i)
	{
		for (int j = 0; j < B.size(); ++j)
		{
			if (A[i] == B[j])
			{
				i++;
				continue;
			}
			else if (A[i] == '?')
			{
				i++;
				continue;
			}
			else if (A[i] == '*'&&i == A.size() - 1)
			{
				break;
			}
			// *.a
			// a.a
			else if (A[i] == '*'&&A[i + 1] == '.')
			{
				i = A.find('.') + 1;
				j = B.find('.');
				continue;
			}
			else if (A[i] == '*')
			{
				i++;
				continue;
			}
			else
			{
				return false;
				break;
			}
		}
	}

	if (i >= A.size())
	{
		return true;
	}
	return false;
}

int main()
{
	string A;
	string B;

	while (cin >> A >> B)
	{
		if (stringMatch(A, B) == true)
		{
			cout << "true" << endl;
		}
		else
		{
			cout << "false" << endl;
		}
	}

	system("pause");
	return 0;
}
#endif


//汽水瓶(非标准答案)
#if 0
#include<iostream>

using namespace std;

int GetDrink(int n)
{
	if (n == 1)
	{
		return 0;
	}
	else if (n == 2)
	{
		return 1;
	}
	else
	{
		return GetDrink(n - 2) + 1;
	}
}

int main()
{
	int n;

	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		else
		{
			cout << GetDrink(n) << endl;
		}
	}

	return 0;
}
#endif

//查找最大重复子串
#if 0
#include<iostream>
#include<string>

using namespace std;

string FindSameString(string A, string B)
{
	if (A.size() > B.size())
	{
		swap(A, B);
	}

	string s;

	//for (int i = A.size(); i > 0; --i)
	for (int i = 0; i < A.size(); ++i)
	{
		//for (int j = 0; j < A.size(); ++j)
		for(int j = i; j<A.size(); ++j)
		{
			string tmp = A.substr(i, j - i + 1);

			//find返回的是字符串的下标,没找到返回npos

			if (B.find(tmp) == string::npos)
			{
				continue;
			}
			else if (tmp.size()>s.size())
			{
				s = tmp;
			}
		}
	}
	return s;
}

int main()
{
	string A;
	string B;

	while (cin >> A >> B)
	{
		cout << FindSameString(A, B) << endl;
	}

	system("pause");
	return 0;
}
#endif

#if 0
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 3;

	printf("%d %d", ++i, ++i);

	system("pause");
	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;

class Base
{
public:
	virtual int foo(int x)
	{
		return x * 10;
	}

	int foo(char x[14])
	{
		return sizeof(x)+10;
	}
};

class Derived : public Base
{
	int foo(int x)
	{
		return x * 20;
	}

	virtual int foo(char x[10])
	{
		return sizeof(x)+20;
	}
};

int main()
{
	Derived stDerived;
	Base *pstBase = &stDerived;

	char x[10];
	printf("%d\n", pstBase->foo(100) + pstBase->foo(x));

	return 0;
}
#endif

//扑克牌大小比较(正确答案)
#if 0
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string ComPareCard(string S)
{
	if (S.find("joker JOKER") != string::npos)
	{
		return "joker JOKER";
	}
	else
	{
		int pos = S.find('-');
		string A = S.substr(0, pos);
		string B = S.substr(pos + 1);

		//获取空格的个数,牌数为空格数+1
		int C1 = count(A.begin(), A.end(), ' ');
		int C2 = count(B.begin(), B.end(), ' ');
		
		string A1 = A.substr(0, ' ');
		string B1 = B.substr(0, ' ');

		string s = "345678910JQKA2jokerJOKER";

		if (C1 == C2)
		{
			cout << (s.find(C1) > s.find(C2) ? C1 : C2) << endl;
		}
		else
		{
			if (C1 == 3)
			{
				return A1;
			}
			else if (C2 == 3)
			{
				return B1;
			}
			else
			{
				cout << "ERROR" << endl;
			}
		}
	}
}

int main()
{
	string S;

	while (getline(cin, S))
	{
		cout << ComPareCard(S) << endl;
	}

	system("pause");
	return 0;
}
#endif

//杨辉三角的变形(标准答案)
#if 0
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n, m;

	while (cin >> n)
	{
		m = 2 * n - 1;

		vector<vector<int>> v(n, vector<int>(m, 0));

		v[0][0] = 1;

		for (int i = 1; i < n; ++i)
		{
			//第一列和最后一列都是1
			v[i][0] = v[i][2 * i] = 1;

			for (int j = 1; j < 2 * i; ++j)
			{
				//第二列,只是两个元素的和
				if (j == 1)
				{
					v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
				}
				else
				{
					//第i,j元素等于上一行第j-2,j-1,j三列元素之和
					v[i][j] = v[i - 1][j - 2] + v[i - 1][j - 1] + v[i - 1][j];
				}
			}
		}

		int k;

		for (k = 0; k < m; ++k)
		{
			if (v[n - 1][k] % 2 == 0 && v[n - 1][k] != 0)
			{
				cout << k + 1 << endl;
				break;
			}
		}

		if (k == m)
		{
			cout << -1 << endl;
		}
	}

	return 0;
}
#endif

//公共字符串计算(无视大小写)
#if 0
#include<iostream>
#include<algorithm>
//#include<cctype>
#include<string>

using namespace std;

int GetCommonStrLength(string A, string B)
{
	transform(A.begin(), A.end(), A.begin(), towupper);
	transform(B.begin(), B.end(), B.begin(), towupper);

	string A1 = A.size() < B.size() ? A : B;
	string B1 = A.size() < B.size() ? B : A;

	string C;

	string tmp;

	for (int i = 0; i < A1.size(); ++i)
	{
		for (int j = A1.size()-1; j >= 0; --j)
		{
			tmp = A1.substr(i, j);

			if (B1.find(tmp) != string::npos)
			{
				if (tmp.size()>C.size())
				{
					C = tmp;
				}
			}
		}
	}

	return C.size();;
}

int main()
{
	string A;
	string B;

	while (cin >> A >> B)
	{
		cout << GetCommonStrLength(A, B) << endl;
	}
	return 0;
}
#endif

//洗牌
#if 0
#include<iostream>
#include<vector>

using namespace std;

vector<int> Func(vector<int> A)
{
	vector<int> v(A.size());

	int j = 0;

	for (int i = 0; i < v.size() / 2; ++i)
	{
		v[j] = A[i];
		j += 2;
	}

	j = v.size() - 1;

	for (int i = v.size() - 1; i >= v.size() / 2; --i)
	{
		v[j] = A[i];
		j -= 2;
	}

	return v;
}

int main()
{
	int T;

	cin >> T;

	while (T--)
	{
		int n, k;

		cin >> n >> k;

		vector<int> A(2 * n);

		//cout << endl;

		for (int i = 0; i < 2 * n; ++i)
		{
			cin >> A[i];
		}

		while (k--)
		{
			A=Func(A);
		}

		//for (auto e : A)
		//{
		//	cout << " " << e;
		//}

		cout << A[0];

		for (int i = 1; i < A.size(); ++i)
		{
			cout << " " << A[i];
		}

		cout << endl;

	}

	system("pause");
	return 0;
}
#endif

//找出第一个出现的字符
#if 0
#include<iostream>
#include<string>

using namespace std;

void Func(string A)
{
	int i;

	for (i = 0; i < A.size(); ++i)
	{
		if (A.find(A[i]) == A.rfind(A[i]))
		{
			cout << A[i] << endl;
			break;
		}
	}

	if (i >= A.size())
	{
		cout << -1 << endl;
	}
}

int main()
{
	string A;

	while (cin >> A)
	{
		Func(A);
	}

	system("pause");
	return 0;
}
#endif

//打怪升级之路
#if 0
#include<iostream>
#include<vector>

using namespace std;

int Func(int a, int b)
{
	//80 40--->40
	if (a%b == 0)
	{
		return b;
	}
	//80 70 --->70 10-->10
	return Func(b, a%b);
}

int main()
{
	int n, a;

	while (cin >> n >> a)
	{
		vector<int> b(n);

		for (int i = 0; i < b.size(); ++i)
		{
			cin >> b[i];
		}

		//开始打怪
		for (int i = 0; i < b.size(); ++i)
		{
			if (b[i] <= a)
			{
				a += b[i];
			}
			else if (b[i]>a)
			{
				a += Func(b[i], a);
			}
		}

		cout << a << endl;
	}

	system("pause");
	return 0;
}
#endif

//微信红包


//计算字符串距离(经典动态规划问题)
//#if 0

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int CalStrDistance(string A, string B)
{
	//if (A.empty())
	//{
	//	return B.size();
	//}
	//else if (B.empty())
	//{
	//	return A.size();
	//}

	//状态:把A字符串变为B字符串需要的操作数
	//多生成一行一列
	vector<vector<int>> vv(A.size() + 1, vector<int>(B.size() + 1, 0));

	//初始化
	vv[0][0] = 0;

	//状态转移方程
	for (unsigned int i = 1; i <= A.size(); i++)
	{
		vv[i][0] = i;
	}

	for (unsigned int j = 0; j <= B.size(); j++)
	{
		vv[0][j] = j;
	}

	for (unsigned int i = 1; i <= A.size(); ++i)
	{
		for (unsigned int j = 1; j <= B.size(); ++j)
		{
			if (A[i - 1] == B[j - 1])
			{
				vv[i][j] = vv[i - 1][j - 1];
			}
			else
			{
				int tmp = min(vv[i - 1][j], vv[i][j - 1]);
				vv[i][j] = min(tmp, vv[i - 1][j - 1]) + 1;
			}
		}
	}

	//返回结果
	return vv[A.size()][B.size()];
}

int main()
{
	string A;
	string B;

	while (getline(cin, A), getline(cin, B))
	{
		cout << CalStrDistance(A, B) << endl;
	}

	system("pause");
	return 0;
}

