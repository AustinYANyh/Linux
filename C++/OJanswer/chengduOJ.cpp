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
		vector<vector<int>> vv(n);

		for (int i = 0; i < n;++i)
		{
			vv[i].resize(2);
		}

		for (int i=0;i<vv.size();++i)
		{
			for(int j=0;j<vv[0].size();++j)
			{
				cin>>vv[i][j];
			}
		}

		set<int> s;

		for (int i=0;i<vv.size();++i)
		{
			for(int j=0;j<vv[0].size();++j)
			{
				s.insert(vv[i][j]);
			}
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