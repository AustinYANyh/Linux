#include <iostream>

using namespace std;

#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1,int a=0) :_year(year), _month(month), _day(day), _a(a)
	{
		int _year = year;
		int _month = month;
		int _day = day;
		int _a = a;
	}

	~Date()
	{

	}

private:
	int _year;
	int _month;
	int _day;
	int& _a;
};

int main()
{

	system("pause");
	return 0;
}
#endif

#if 0
class A
{
public:
	A()
	{
		++_count;
	}

	~A()
	{

	}

	A(const A& a)
	{
		_a = a._a;
		++_count;
	}

	static int Getcount()
	{
		return _count;
	}

private:
	int _a;
	static int _count;
};

int A::_count = 0;

int main()
{
	A a;
	A a2;
	A a3(a2);

	cout << a.Getcount() << endl;

	system("pause");
	return 0;
}
#endif


#if 0
class Date
{
	friend ostream& operator<<(ostream& _cout,const Date& d);
public:
	Date(int year = 1900, int month = 1,int day = 1) :_year(year), _month(month), _day(day)
	{

	}

	~Date()
	{

	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

private:
	int _year;
	int _month;
	int _day;
};


ostream& operator<<(ostream& _cout,const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

int main()
{
	//Date d;
	//d << cout;

	Date d2(1996, 7, 28);
	//d2 << cout;

	cout << d2;

	system("pause");
	return 0;
}
#endif


#if 0
class Time
{
	friend class Date;
public:
	Time(int hour = 0, int minute = 0, int second = 0) :_hour(hour), _minute(minute), _second(second)
	{

	}

	~Time()
	{

	}

	Time(const Time& t)
	{
		_hour = t._hour;
		_minute = t._minute;
		_second = t._second;
	}

	void printTime()
	{
		cout << _hour << ":" << _minute << ":" << _second << endl;
	}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1) :_year(year), _month(month), _day(day)
	{

	}

	~Date()
	{

	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	void SetTime(int hour,int minute,int second)
	{
		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;
	}

	void printDate()
	{
		cout << _year << "-" << _month << "-" << _day << " "
		<< _t._hour << ":" << _t._minute << ":" << _t._second << endl; 
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

int main()
{
	Date d(2019, 6, 30);
	d.SetTime(15, 27, 30);

	d.printDate();

	system("pause");
	return 0;
}
#endif

class A
{
public:
	class B
	{
	public:
		void TestFun(const A& A)
		{
			cout << A.a << endl;
			cout << A.b << endl;
		}
	};
private:
	int a = 10;
	int b = 10;
};

int main()
{
	A::B b;
	A a;
	b.TestFun(a);
	system("pause");
	return 0;
}