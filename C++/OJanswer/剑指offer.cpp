#include<iostream>
#include<stack>

using namespace std;

//9.27

//栈实现队列
class Solution
{
public:
    void push(int node) 
    {
        s1.push(node);
    }

    int pop() 
    {
        while(s1.empty()==false)
        {
            s2.push(s1.top());
            s1.pop();
        }
        
        int i=s2.top();
        
        s2.pop();
        
        while(s2.empty()==false)
        {
            s1,push(s2.top());
            s2.pop();
        }
        return i;
    }

private:
    stack<int> s1;
    stack<int> s2;
};

//旋转数组的最小数字
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) 
    {
        if(rotateArray.size()==0)
        {
            return 0;
        }
        
        int min=rotateArray[0];
        
        for(int i=1;i<rotateArray.size();++i)
        {
            if(min>rotateArray[i])
            {
                min=rotateArray[i];
            }
        }
        return min;
    }
};

//斐波那契数列
class Solution {
public:
    int Fibonacci(int n) 
    {
        vector<int> fib;
        fib.resize(39,0);
        
        fib[1]=1;
        fib[2]=1;
        
        for(int i=3;i<=39;++i)
        {
            fib[i]=fib[i-1]+fib[i-2];
        }
        
        return fib[n];
    }
};

//跳台阶
class Solution {
public:
    int jumpFloor(int number) 
    {
        if(number==0)
        {
            return 0;
        }
        else if(number<3)
        {
            return number;
        }
        else
        {
            int f=0;
            int f1=1;
            int f2=2;
            
            for(int i=3;i<=number;++i)
            {
                f=f1+f2;
                f1=f2;
                f2=f;
            }
            return f;
        }
    }
};

//变态跳台阶
#include<vector>

class Solution 
{
public:
    int jumpFloorII(int number) 
    {
        //动态规划问题
        
        //状态:青蛙调到台阶上的方法数
        
        //初始化
        vector<int> F(number+1);
        
        F[0]=1;
        F[1]=1;
        F[2]=2;
        
        //状态转移方程:F(n)=F(n-1)+F(n-2)+F(n-3)...+F(1)
        //F(n-1)=F(n-2)+F(n-3)...+F(1)
        //F(n)=2F(n-1)
        for(int i=3;i<=number;++i)
        {
            F[i] = 2 * F[i - 1];
        }
        //返回结果:F(n)
        return F[number];
    }
};

//矩形覆盖(变式斐波那契)
class Solution {
public:
    int rectCover(int number) 
    {
        if(number<=0)
        {
            return 0;
        }
        else if(number<=2)
        {
            return number;
        }
        else
        {
            return rectCover(number-1)+rectCover(number-2);
        }
    }
};

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

