#if 0
#include<iostream>
#include<set>
#include<vector>

using namespace std;

int main()
{
	int n;

	while (cin >> n)
	{
		vector<int> v(2*n);

		for (int i = 0; i <2* n;++i)
		{
			cin >> v[i];
		}

		set<int> s;

		for (auto e : v)
		{
			s.insert(e);
		}

		cout << s.size() << endl;
	}

	system("pause");
	return 0;
}
#endif

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int N;

	while (cin >> N)
	{
		vector<vector<int>> vv(N);

		for (int i = 0; i < N; ++i)
		{
			vv[i].resize(2);
		}

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				cin >> vv[i][j];
			}
		}

		int in = 0;

		while (in<N)
		{
			int count = 0;
			string k = to_string(vv[in][1]);

			for (int i = 0; i <= vv[in][0]; ++i)
			{
				string s = to_string(i);
				for (int j = 0; j < s.size(); ++j)
				{
					if (s[j] == k[0])
					{
						count++;
						break;
					}
				}
			}
			cout << count << endl;
			in++;
		}
	}

	system("pause");
	return 0;
}