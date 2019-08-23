#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>

using namespace std;

class Person
{
public:
	Person(char* name, int age)
	{
		_name = new char[strlen(name) + 1];
		strcpy(_name, name);
		_age = age;
	}

#if 0
	//自己提供拷贝构造函数
	Person(const Person& p)
	{
		_name = new char[strlen(p._name) + 1];
		strcpy(_name, p._name);
		_age = p._age;
	}
#endif

	//重载=运算符
	Person& operator=(const Person& p)
	{
		if (_name == p._name)
		{
			return *this;
		}

		_name = new char[strlen(p._name) + 1];
		strcpy(_name, p._name);
		_age = p._age;

		return *this;
	}

private:
	char* _name;
	int _age;
};

#include<algorithm>

//现代版string类写法
class String
{
public:
	String(const char* name="")
	{
		_name = new char[strlen(name) + 1];
		strcpy(_name, name);
	}

#if 0
	String(const String& s) :_name(nullptr)
	{
		String stemp(s._name);
		swap(_name, stemp._name);
	}
#endif

private:
	char* _name;
};

int main()
{
	//Person a("张三", 19);
	//Person b("李四", 19);

	//b = a;

	String s("张三");
	String b(s);

	printf("%p\n", s);
	printf("%p\n", b);

	system("pause");
	return 0;
}