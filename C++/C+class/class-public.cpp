#include<iostream>

using namespace std;

#if 0
class person
{
public:
	virtual void BuyTicket()
	{
		cout << "全价票" << endl;
	}
};

class student :public person
{
public:
	virtual void BuyTicket()
	{
		cout << "半价票" << endl;
	}
};

class soldier :public person
{
public:
	virtual void BuyTicket()
	{
		cout << "优先购票" << endl;
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


//公有继承
#if 0
class student:public person
{
protected:
	int _sumID;
};
#endif

#if 0
//protected继承
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

	//luzihan.person::_name = "陆子涵";

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

	//基类不可以给派生类赋值
	//luzihan = yanyunhao;

	//基类的指针可以指向派生类对象
	//Person* pobj = &luzihan;

	//Student* sobj = &yanyunhao;
	Student* sobj;

	//public继承下,sobj可以指向四个内容(name,sex,age,stuid),而基类只有三个类容,C++避免了这样的隐式转换
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