/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：start.cpp
*   创 建 者：闫云皓
*   创建日期：2019年06月03日
*   描    述：
*
================================================================*/
#include<iostream>

using namespace std;

namespace N1
{
    int a=10;

    int Add(int left,int right)
    {
	return left+right;
    }
}

namespace N2
{
    int a=20;

    int Add(int left,int right)
    {
	return left+right;
    }

    namespace N3
    {
	int a=30;

	int Add(int left,int right)
	{
	    return left+right;
	}
    }
}

void TestFunc(int a=10)
{
    cout<<a<<endl;
}

int Add(int left,int right)
{
    return left+right;
}

double Add(double left,double right)
{
    return left+right;
}


int main()
{
    cout<<Add(10,20)<<endl;
    cout<<Add('2','2')<<endl;
    return 0;
}
