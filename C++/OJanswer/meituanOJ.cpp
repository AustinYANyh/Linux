#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n;

	while (cin >> n)
	{
		vector<vector<double>> vv(n);
		for (int i = 0; i < n; ++i)
		{
			vv[i].resize(n);
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> vv[i][j];
			}
		}

		//遍历找出最大值
		double max = 0;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (max < vv[i][j])
				{
					max = vv[i][j];
				}
			}
		}
	}

	system("pause");
	return 0;
}
