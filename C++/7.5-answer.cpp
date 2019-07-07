//欧几里得放蛋糕
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

    return 0;
}

//字符型转为整数型
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
