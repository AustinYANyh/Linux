#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

bool isprime(int n)
{
	int a = sqrt(n);

	for (int i = 2; i <= a; ++i)
	{
		if (n%i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int n;

	while (cin >> n)
	{
		int a = 0;
		int b = 0;

		for (int i = n; i > 0; i--)
		{
			if (isprime(i) == true)
			{
				a = i;
				break;
			}
		}

		for (int i = n; i < 100000; i++)
		{
			if (isprime(i) == true)
			{
				b = i;
				break;
			}
		}

		if ((n - a)>(b - n))
		{
			cout << b << endl;
		}
		else
		{
			cout << a << endl;
		}
	}

	system("pause");
	return 0;
}