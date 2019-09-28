#include<iostream>

using namespace std;

//9.27

//二进制位1的数量,负数采用补码表示
class Solution1 {
public:
	int  NumberOf1(int n)
	{
		int count = 0;
		
		unsigned int nn = n;

		while (nn>0)
		{
			if ((nn & 1) == 1)
			{
				count++;
			}
			nn >>= 1;
		}
		return count;
	}
};

#include<algorithm>
#include<math.h>

//幂运算
class Solution2 {
public:
	double Power(double base, int exponent)
	{
		return pow(base, exponent);
	}
};

#include<vector>

//调整数组奇数和偶数的位置
class Solution3 {
public:
	void reOrderArray(vector<int> &array)
	{
		vector<int> v;

		for (auto e : array)
		{
			if (e % 2 != 0)
			{
				v.push_back(e);
			}
		}

		for (auto e : array)
		{
			if (e % 2 == 0)
			{
				v.push_back(e);
			}
		}

		array = v;
	}
};

