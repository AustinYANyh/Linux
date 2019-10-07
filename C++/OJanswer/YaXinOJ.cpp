#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>

using namespace std;

int sumofxxx(int k)
{
	int i = 1;
	double sum = 0;

	for (i=1; sum <= k; ++i)
	{
		sum += pow(1, i) / i;
	}

	return i - 1;
}

void fuc(int k, string data,vector<string>& res)
{
	if (k == data.size() - 1)
	{
		res.push_back(data);
	}

	for (int i = k; i < data.size(); ++i)
	{
		if (i != k && data[i] == data[k])
		{
			continue;
		}

		swap(data[i], data[k]);
		fuc(k + 1, data, res);
		swap(data[i], data[k]);
	}
}

vector<string> _func(string data)
{
	vector<string> res;

	fuc(0, data, res);

	sort(res.begin(), res.end());

	return res;
}

int main1()
{
	string a = "abc";

	vector<string> res = _func(a);

	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i].c_str() << endl;
	}

	system("pause");
	return 0;
}

int main()
{
	int k = 10;

	cout << sumofxxx(k) << endl;

	system("pause");
	return 0;
}