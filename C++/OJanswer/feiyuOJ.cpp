#if 0
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

void Func(vector<int>& v)
{
	sort(v.begin(), v.end());

	int count = 0;

	for (auto e : v)
	{
		if (e == v[v.size() / 2])
		{
			count++;
		}
	}

	if (count >= v.size() / 2)
	{
		cout << v[v.size() / 2] << endl;
	}
}

int main()
{
	vector<int> v(100*2);

	for (int i = 0;i<)

	system("pause");
	return 0;
}
#endif


#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz! ";
	string s2 = "BCDEFGHIJKLMNOPQRSTUVWXYZAbcdefghijklmnopqrstuvwxyza! ";

	string s3;
	while (getline(cin, s3))
	{
		string s4;
		for (auto e : s3)
		{
			s4 += s2[s1.find(e)];
		}

		cout << s4 << endl;
	}

	system("pause");
	return 0;
}

#if 0
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

bool Func1(string& A, string& B)
{
	for (auto e : B)
	{
		if (A.find(e) == string::npos)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string s;

	while (getline(cin, s))
	{
		string A;
		string B;

		A = s.substr(0, s.find(" "));
		B = s.substr(s.find(" ") + 1, s.size() - 1);

		if (Func1(A, B) == true)
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