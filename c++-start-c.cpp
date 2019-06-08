#include <iostream>

using namespace std;

namespace N1
{
	int a = 10;

	int Add(int left,int right)
	{
		return left + right;
	}
}

namespace N2
{
	int a = 20;
	
	int Add(int left, int right)
	{
		return left + right;
	}

	namespace N3
	{
		int a = 30;

		int Add(int left, int right)
		{
			return left + right;
		}
	}
}

void swap(int& left, int& right)
{
	int tmp = left;
	left = right;
	right = tmp;
}

int& Add(int a, int b)
{
	int c = a + b;
	return c;
}





#if 0
#include <time.h> 
struct A {    int a[10000]; };


void TestFunc1(A a) 
{}

void TestFunc2(A& a) 
{}

void TestRefAndValue() 
{
	A a;
	// ��ֵ��Ϊ��������    
	size_t begin1 = clock();    
	for (size_t i = 0; i < 10000; ++i)
	{
		TestFunc1(a);
	}
	size_t end1 = clock();

	// ��������Ϊ��������    
	size_t begin2 = clock();   
	for (size_t i = 0; i < 10000; ++i)
	{
		TestFunc2(a);
	}
	size_t end2 = clock();

	// �ֱ���������������н������ʱ��    
	cout << "TestFunc1(int*)-time:" << end1 - begin1 << endl;    
	cout << "TestFunc2(int&)-time:" << end2 - begin2 << endl; 
}

// ���ж�Σ����ֵ�������ڴ��η����Ч������ 
int main() 
{    
	for (int i = 0; i < 10; ++i)    
	{        
		TestRefAndValue();    
	}  

	system("pause");
	return 0; 
}
#endif

void TestFor()
{
	int array[] = { 1, 2, 3, 4, 5 };
	for (auto& e : array)
	{
		 e*=2 ;
	}

	for (auto e : array)
	{
		cout << e << endl;
	}
}

int main()
{
	TestFor();
	system("pause");
}



