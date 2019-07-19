#include<iostream>

using namespace std;

#if 0
class person
{
public:
	virtual void BuyTicket()
	{
		cout << "ȫ��Ʊ" << endl;
	}
};

class student :public person
{
public:
	virtual void BuyTicket()
	{
		cout << "���Ʊ" << endl;
	}
};

class soldier :public person
{
public:
	virtual void BuyTicket()
	{
		cout << "���ȹ�Ʊ" << endl;
	}
};

void TestFunc(person& person)
{
	person.BuyTicket();
}

int main()
{
	person yanyunhao;
	student luzihan;
	soldier yan;

	yanyunhao.BuyTicket();
	luzihan.BuyTicket();
	yan.BuyTicket();


	system("pause");
	return 0;
}
#endif

#if 0
#include<string>

class person
{
public:
	void print()
	{
		cout << _name << endl;
	}
protected:
	string _name;
private:
	int _age;
};
#endif


//���м̳�
#if 0
class student:public person
{
protected:
	int _sumID;
};
#endif

#if 0
//protected�̳�
class student :protected person
{
public:
	void printName()
	{
		cout << _name << endl;
	}
protected:
	int _sumID;
};
int main()
{
	student luzihan;

	//luzihan.person::_name = "½�Ӻ�";

	cout << sizeof(person) << endl;
	cout << sizeof(student) << endl;

	//luzihan.print();

	luzihan.printName();

	system("pause");
	return 0;
}
#endif

#if 0
class Person
{
//protected:
public:
	string _name;
	string _sex;
	int _age;
};

class Student :public Person
{
public:
	int _stuID;
};

void Test()
{
	Student luzihan;

	Person yanyunhao;

	yanyunhao = luzihan;

	//���಻���Ը������ำֵ
	//luzihan = yanyunhao;

	//�����ָ�����ָ�����������
	//Person* pobj = &luzihan;

	//Student* sobj = &yanyunhao;
	Student* sobj;

	//public�̳���,sobj����ָ���ĸ�����(name,sex,age,stuid),������ֻ����������,C++��������������ʽת��
	Person* pobj;
}
#endif

class Person
{
public:
	Person(const char* name = "luzihan") :_name(name)
	{
		cout << "Person()" << endl;
	}

	Person(const Person& p)
	{
		cout << "Person(const Person& p)" << endl;
	}

	Person& operator=(const Person& p)
	{
		if (this != &p)
		{
			_name = p._name;
		}
		return *this;
	}

	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name;
};

class Student :public Person
{
public:
	Student(const char* name, int stuID) :Person(name), _stuID(stuID)
	{
		cout << "Student()" << endl;
	}

	Student(const Student& s) :Person(s), _stuID(s._stuID)
	{
		cout << "Student(const Student& s)" << endl;
	}

	Student& operator=(const Student& s)
	{
		if (this != &s)
		{
			Person::operator=(s);
			_stuID = s._stuID;
		}
		return *this;
	}

	~Student()
	{
		cout << "~Student()" << endl;
	}
protected:
	int _stuID;
};

int main()
{
	Student s1("luzihan", 2);

	Student s2("yanyunhao", 1);

	s2 = s1;

	system("pause");
	return 0;
}