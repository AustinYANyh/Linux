#if 0
#include<iostream>
#include<string>
#include<set>

using namespace std;

int main()
{
	string s;
	
	while (getline(cin, s))
	{
		set<char> s1;
		int count = 0;

		if (s.size() == 0 )
		{
			cout << 0 << endl;
		}

		for (auto e : s)
		{
			s1.insert(e);
		}
		
		//s1.erase(',');

		for (auto e : s1)
		{
			if (e != ',')
			{
				count++;
			}
		}

		cout << count << endl;
	}

	system("pause");
	return 0;
}
#endif


#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int st_count = 0;

	while (cin >> st_count)
	{
		vector<int> st_score(st_count);

		for (int i = 0; i < st_count; ++i)
		{
			cin >> st_score[i];
		}

		vector<int> cookie;

		cookie.resize(st_count, 1);

		for (int i = 0; i < st_count; ++i)
		{
			if (i == 0)
			{
				if (st_score[i]>st_score[i + 1])
				{
					cookie[i] = 2;
				}
			}
			else if (i == st_count - 1)
			{
				if (st_score[i] > st_score[i - 1])
				{
					cookie[i] = cookie[i - 1] + 1;
				}
				//else
				//{
				//	cookie[i - 1] += 1;
				//}
			}
			else
			{
				if (st_score[i] > st_score[i + 1] && st_score[i] > st_score[i - 1])
				{
					cookie[i] = max(cookie[i - 1], cookie[i + 1]) + 1;
				}
				else if (st_score[i] > st_score[i + 1] )
				{
					cookie[i] = cookie[i + 1] + 1;
				}
				else if (st_score[i] > st_score[i - 1])
				{
					cookie[i] = cookie[i - 1] + 1;
				}
			}
		}

		int cookies = 0;

		for (auto& e : cookie)
		{
			cookies += e;
		}

		cout << cookies << endl;
	}

	system("pause");
	return 0;
}