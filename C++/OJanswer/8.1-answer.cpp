//7.1 ��s1�ַ�����ȥ��s2�ַ���������
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

//��s1�ַ�����ȥ��s2�ַ���������,���Ž�(ӳ��,��s1��û��s2�Ĳ����ó�����ret������)
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

		//���Է��ؽ���������еĸ�����СΪ1
		int ret = 1;

		for (int i = 1; i<n - 1; ++i)
		{
			if ((v[i - 1]<v[i] && v[i]>v[i + 1]) || (v[i - 1]>v[i] && v[i] < v[i + 1]))
			{
				++ret;
			}

			//i��ʾ�м�λ�ã�һ����Ҫ�ƶ�2��
			//�������Ϊż������i=n-3ʱ��ֻ��Ҫ��һ������м�λ�ã���2�����һ��Ԫ�أ�i+1��Խ����

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

//�Լ�д�ĵ�������
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


//��������
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

		//�ߵ�����˵�������ո�,һ�������Ѿ�������,��ʼ����
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

//�������õĸ��Žⷨ
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


//�����ǹ�
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

//�ǵ���,�ǵݼ�,������������еĸ���
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

//����ת��(Ŀǰֻͨ��70%)
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

//j=0����ѭ���ж�,��˼��,j�������0����ֵ,��Ϊ��,����ѭ��,����j=-1,����-1��ֵ,ѭ������Ϊ��,������ѭ��
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

//�ҳ�����������ִ�(�жϺͱ���Ҫ�ڱ�����ʱ�����)
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

//�ҳ������г���һ�����ϵ���
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

//7.4�����ַ��������ܳ�Ϊ���Ĵ��ķ�����(���ı�ԭ����Ҫ��������,���˼��)
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

//��������������ĺ͵����ֵ
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
//����ת����׼��
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

//7.5 ŷ����÷ŵ��⡢�ַ���ת������
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

//ʹ��vector�ķ���
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

//�ַ���תΪ������
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


//ż��λ��Ϊ��д
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

//���źϷ����м��
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

//���źϷ����м��(��ȷ��)
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

//��һ������Ϊ쳲��������Ĳ���
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
	int last3 = 1;//����������
	int last2 = 1;//�����ڶ���
	int a = 0;//���һ��
	for (int n = 3; n <= x; ++n)
	{
		a = last3 + last2;//���һ�����ǰ����֮��
		last3 = last2;//�µĵ���������
		last2 = a;//�µĵ����ڶ���
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

//��Ϊ쳲��������Ĳ���(��׼��)
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

//����С������
#if 0
#include<iostream>

using namespace std;

int Func(int x, int y)
{
	if (x%y == 0)
	{
		return y;//80%40==0,80��40�����Լ������40
	}//80%70==10,��ʱ������70��10�����Լ��,���Ϊ10
	//��ô,10����80��70�����Լ��
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

//����С������(��׼��)
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


//�ж��Ƿ�������������
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

//����ӷ�
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

//n*m�������߷����Լ���˼·��
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

	//���ȼ��
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

	//��ĸ���,���ż��,���ּ��
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

	//��ĸ�÷�
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

	//���ֵ÷�
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

	//���ŵ÷�
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

	//����
	if ((AZflag == 1 || azflag == 1) && count > 0 && sysflag == 0)//��ĸ,������,�޷���
	{
		level += 2;
	}
	else if ((AZflag == 1 || azflag == 1) && count > 0 && syscount > 0)//��ĸ�������ֶ���
	{
		level += 3;
	}
	else if ((AZflag == 1 && azflag == 1) && count > 0 && syscount > 0)//��Сд��ĸ,����,����
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

//��ʯ��,û������
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

//��������(��׼��)
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

//���㵱ǰ����
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

//�ҳ�������1�ĸ���
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
//����(��׼��)
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

		//����ÿһ����ɫ��������������
		for (int i = 0; i < n; i++)
		{
			//������0���ڵ���ɫ���ף��ۼ�
			if (left[i] * right[i] == 0)
			{
				sum += left[i] + right[i];
			}

			//���������ֶ��е���ɫ���ף�ִ���ۼ�-��Сֵ+1
			//�ҵ���Сֵ������
			else
			{
				left_sum += left[i];
				right_sum += right[i];
				left_min = min(left_min, left[i]);
				right_min = min(right_min, right[i]);
			}
		}

		//���Ϊ�����Ҷ����������������еĽ��+��0���ڵ�������+����ټ�һ�϶����ܱ�֤��
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


//ͳ����ȫ������
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
//�˿��ƴ�С�Ƚ�
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

//�������������
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

//������Ǳ���(�ҹ���)
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


//�ַ���ͨ���
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


//��ˮƿ(�Ǳ�׼��)
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

//��������ظ��Ӵ�
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

			//find���ص����ַ������±�,û�ҵ�����npos

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

//�˿��ƴ�С�Ƚ�(��ȷ��)
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

		//��ȡ�ո�ĸ���,����Ϊ�ո���+1
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

//������ǵı���(��׼��)
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
			//��һ�к����һ�ж���1
			v[i][0] = v[i][2 * i] = 1;

			for (int j = 1; j < 2 * i; ++j)
			{
				//�ڶ���,ֻ������Ԫ�صĺ�
				if (j == 1)
				{
					v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
				}
				else
				{
					//��i,jԪ�ص�����һ�е�j-2,j-1,j����Ԫ��֮��
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

//�����ַ�������(���Ӵ�Сд)
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

//ϴ��
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

//�ҳ���һ�����ֵ��ַ�
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

//�������֮·
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

		//��ʼ���
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

//΢�ź��


//�����ַ�������(���䶯̬�滮����)
#if 0
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

	//״̬:��A�ַ�����ΪB�ַ�����Ҫ�Ĳ�����
	//������һ��һ��
	vector<vector<int>> vv(A.size() + 1, vector<int>(B.size() + 1, 0));

	//��ʼ��
	vv[0][0] = 0;

	//״̬ת�Ʒ���
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

	//���ؽ��
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
#endif

//���ս�(·���ද̬�滮����)
#if 0
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Bonus
{
public:
	int getMost(vector<vector<int> > board)
	{
		//״̬:���������õ��������ܼ�ֵ

		//��ȡ�к���
		int m = board.size();
		int n = board[0].size();

		vector<vector<int> > val(m, vector<int>(n, 0));
		val[0][0] = board[0][0];

		//��ʼ����һ�к͵�һ��
		for (int i = 1; i < m; ++i)
		{
			val[0][i] += val[0][i - 1] + board[0][i];
			val[i][0] += val[i - 1][0] + board[i][0];
		}

		//״̬ת�Ʒ���:F[i][j]=max(F[i-1][j],F[i][j-1])+a[i][j];
		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				val[i][j] = max(val[i - 1][j], val[i][j - 1]) + board[i][j];
			}
		}

		//���ؽ��:F[m-1][n-1]
		return val[m - 1][n - 1];
	}
};
#endif

#if 0
#include<iostream>

using namespace std;

int main()
{
	int m = 5;

	if (m++ > 5)
	{
		cout << m << endl;
	}
	else
	{
		cout << --m;
	}

	system("pause");
	return 0;
}
#endif

//MP3������(��׼��)
#if 0
#include<iostream>
#include<string>

using namespace std;

int main()
{
	//�����������
	int n;

	//��������
	string order;

	while (cin >> n >> order)
	{
		//numΪ������ڸ���,firstΪ��ǰ��Ļ��ʾ�ĵ�һ�׸�����
		int num = 1;
		int first = 1;

		if (n <= 4)
		{
			for (int i = 0; i < order.size(); ++i)
			{
				if (num == 1 && order[i] == 'U')
				{
					num = n;
				}
				else if (num == n&&order[i] == 'D')
				{
					num = 1;
				}
				else if (order[i] == 'U')
				{
					num--;
				}
				else
				{
					num++;
				}
			}

			for (int i = 1; i <= n - 1; ++i)
			{
				cout << i << ' ';
			}

			cout << n << endl;
			cout << num << endl;
		}
		else
		{
			//������������4
			for (int i = 0; i < order.size(); ++i)
			{
				if (first == 1 && num == 1 && order[i] == 'U')
				{
					num = n;
					first = n - 3;
				}
				else if (first == n - 3 && num == n&&order[i] == 'D')
				{
					first = 1;
					num = 1;
				}
				else if (first != 1 && num == first&&order[i] == 'U')
				{
					first--;
					num--;
				}
				else if (first != n - 3 && num == first + 3 && order[i] == 'D')
				{
					first++;
					num++;
				}
				else if (order[i] == 'U')
				{
					num--;
				}
				else
				{
					num++;
				}
			}

			for (int i = first; i < first + 3; ++i)
			{
				cout << i << ' ';
			}

			cout << first + 3 << endl;
			cout << num << endl;
		}
	}

	system("pause");
	return 0;
}
#endif

//�Ǽ�����(�Ǳ�׼��)
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

		vector<int> res(10001);

		res[1] = 1;
		res[2] = 2;

		for (int i = 3; i < 10001; ++i)
		{
			res[i] = (res[i - 1] % 10000 + res[i - 2] % 10000) % 10000;
		}

		for (int i = 0; i < n; ++i)
		{
			cout.width(4);
			cout.fill('0');
			cout << res[v[i]];
		}
		cout << endl;
	}

	//int a = 3;

	//cout.width(4);
	//cout.fill('0');
	//cout << a << endl;

	system("pause");
	return 0;
}
#endif


//����
#if 0
#include<iostream>
#include<string>

using namespace std;

int Func(int n)
{
	if (n < 10)
	{
		return n;
	}

	int sum = 0;
	
	while (n>0)
	{
		sum += n % 10;
		n /= 10;
	}

	if (sum < 10)
	{
		return sum;
	}
	else
	{
		return Func(sum);
	}
}

int main()
{
	string n;

	while (cin >> n)
	{
		int sum = 0;

		for (auto& e : n)
		{
			sum += e - '0';
		}

		cout << Func(sum) << endl;
	}

	system("pause");
	return 0;
}
#endif

//��̬��̨��
#if 0
#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
	int jumpFloorII(int number)
	{
		//��̬�滮����

		//״̬:���ܵ���̨���ϵķ�����

		//��ʼ��
		vector<int> F(number);

		F[0] = 1;
		F[1] = 1;
		F[2] = 2;

		//״̬ת�Ʒ���:F(n)=F(n-1)+F(n-2)+F(n-3)...+F(1)
		//F(n-1)=F(n-2)+F(n-3)...+F(1)
		//F(n)=2F(n-1)
		for (int i = 3; i < number; ++i)
		{
			F[i] = 2 * F[i - 1];
		}
		//���ؽ��:F(n)
		return F[number];
	}
};
#endif

//�쵽������
#if 0
#include<iostream>

using namespace std;

int main()
{
	long double n, r;

	while (cin >> n >> r)
	{
		if (n <= (2 * 3.14*r))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}

	return 0;
}
#endif

//���üӼ��˳����ӷ�
#if 0
#include<iostream>

using namespace std;

int Add(int num1, int num2)
{
	//λ����,A��λ,B���
	while (num1 != 0)
	{
		int tmp = num2;
		num2 = num1^num2;
		num1 = num1&tmp;
		num1 <<= 1;
	}
	return num2;
}

int main()
{
	int a, b;

	while (cin >> a >> b)
	{
		cout << Add(a, b) << endl;
	}

	system("pause");
	return 0;
}
#endif


//������
#if 0
#include<iostream>

using namespace std;

int main()
{
	long double a, b, c;

	while (cin >> a >> b >> c)
	{
		if ((a + b > c) && (a + c > b) && (b + c > a))
		{
			cout << "Yes" << endl;
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

//����λ��������ż��λ����ż��
#if 0
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
public:
	/**
	*  ����λ�϶�����������ż��λ�϶���ż��
	*  ���룺����arr�����ȴ���2
	*  len��arr�ĳ���
	*  ��arr����������λ�϶�����������ż��λ�϶���ż��
	*/
	void oddInOddEvenInEven(vector<int>& arr, int len)
	{
		int i = 0;
		int j = 1;

		while (i<len&&j<len)
		{
			if (arr[i] % 2 == 0)
			{
				i += 2;
				continue;
			}

			if (arr[j] % 2 == 1)
			{
				j += 2;
				continue;
			}

			if (arr[i] % 2 != 0 && arr[j] % 2 == 0)
			{
				swap(arr[i], arr[j]);
				i += 2;
				j += 2;
			}
		}
	}
};

int main()
{
	Solution s;

	int n;

	while (cin >> n)
	{
		vector<int> v(n);

		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}

		s.oddInOddEvenInEven(v, n);

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

	}

	system("pause");
	return 0;
}
#endif

//���ӷ���
#if 0
#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int n;

	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}

		cout << (long)pow(5, n) - 4 << " " << (long)pow(4, n) + n - 4 << endl;
	}

	system("pause");
	return 0;
}
#endif


//�������������С������ɺ�
#if 0
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int getFirstUnFormedNum(vector<int> arr, int len) 
{
	int i, j;
	int Min = arr[0], Max = 0;

	for (i = 0; i < len; i++)
	{
		Max += arr[i];

		if (arr[i] < Min)
		{
			Min = arr[i];
		}
	}

	//�ҵ�����[min,max]

	//״̬ת�Ʒ���:F(j)=max(F[j],F[j-a[i]]+a[i])

	vector<int> dp(Max + 1, 0);

	for (i = 0; i < len; i++)
	{
		for (j = Max; j >= arr[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - arr[i]] + arr[i]);
		}
	}

	for (i = Min; i <= Max; i++)
	{
		//�ҵ��������������мӳ����ľͷ���
		if (i != dp[i])
		{
			return  i;
		}
	}
	return  i;
}
#endif

//�Ҽٱ�
#include<iostream>

using namespace std;

int main()
{
	int n;

	while (cin >> n)
	{
		//4--->3 1--->1 1 1     1
		if (n == 0)
		{
			break;
		}
		else if (n == 1)
		{
			cout << 0 << endl;
		}
		else if (n <= 3)
		{
			cout << 1 << endl;
		}
		else
		{
			//�����Ѿ���Ҫ1����
			int count = 1;

			while (n > 3)
			{
				//������ô˵,���ֳ�����
				if (n % 3 == 0)
				{
					n = n / 3;
				}
				else
				{
					n = n / 3 + 1;
				}

				//ÿ��һ�ξͼ�һ
				count++;
			}
			cout << count << endl;
		}
	}

	system("pause");
	return 0;
}