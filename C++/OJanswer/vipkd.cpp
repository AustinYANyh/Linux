#include<iostream>
#include<math.h>

using namespace std;

bool isprim(int n)
{
	for (int i = 2; i <= n/2; ++i)
	{
		if (n%i == 0)
		{
			return false;
		}
	}
	return true;
}

void Func(int n)
{
	for (int i = 6; i <= n; ++i)
	{
		if (i % 2 == 0)
		{
			for (int j = 3; j <= i / 2; ++j)
			{
				if (isprim(j) && isprim(i - j))
				{
					cout << i << '=' << j << "+" << i - j << endl;
				}
			}
		}
	}
}

#if 0
int main()
{
	int N;

	while (cin >> N)
	{
		Func(N);
	}

	system("pause");
	return 0;
}
#endif


int a[100];
int Count;
int n;

void dfs(int k,int sum,int p)
{
	if (sum == n)
	{
		//cout << n << '=' << a[0];
		cout << a[0];

		for (int i = 1; i < p; ++i)
		{
			cout << '+' << a[i];
		}
		Count++;

		cout << endl;
	}

	for (int i = k; i <= n; ++i)
	{
		if (sum + i <= n)
		{
			a[p] = i;
			dfs(i, sum + i, p + 1);
		}
		else
		{
			break;
		}
	}
}

int main()
{
	Count = 0;

	while (cin >> n)
	{
		dfs(1, 0, 0);
	}

	return 0;
}