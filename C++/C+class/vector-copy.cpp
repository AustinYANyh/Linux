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
	//�Լ��ṩ�������캯��
	Person(const Person& p)
	{
		_name = new char[strlen(p._name) + 1];
		strcpy(_name, p._name);
		_age = p._age;
	}
#endif

	//����=�����
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

//�ִ���string��д��
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
	//Person a("����", 19);
	//Person b("����", 19);

	//b = a;

	String s("����");
	String b(s);

	printf("%p\n", s);
	printf("%p\n", b);

	system("pause");
	return 0;
}