#include<iostream>

using namespace std;

#if 0
class Date
{
public:
	//无参构造函数
	Date()
	{

	}

	//有参构造函数
	Date(int year=1900,int month=1,int day=1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;

};

int main()
{
	Date d1;
	d1.PrintDate();

	Date d2(2019, 6, 16);
	d2.PrintDate();

	system("pause");
	return 0;
}
#endif

#if 0
typedef int Datatype;

class Seqlist
{
public:
	Seqlist(int capacity)
	{
		_array = (Datatype*)malloc(sizeof(Datatype));
		_size = 0;
		_capacity = capacity;
	}

	~Seqlist()
	{
		if (_array)
		{
			free(_array);
			_array = NULL;
			_size = 0;
			_capacity = 0;
		}
	}

private:
	int* _array;
	int _size;
	int _capacity;
};
#endif

#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	Date(const Date& d)
	{
		_year=d._year ;
		_month = d._month;
		_day = d._day;
	}

	bool operator==(const Date& d)
	{
		if (_year == d._year&&
			_month == d._month&&
			_day == d._day)
		{
			return true;
		}
		return false;
	}

	bool operator!=(const Date& d)
	{
		/*if (!(_year == d._year&&
			_month == d._month&&
			_day == d._day))
		{
			return true;
		}
		return false;*/
		return !(*this==d)
	}

private:
	int _year;
	int _month;
	int _day;

};

int main()
{
	Date d1;
	Date d2(d1);

	d1.PrintDate();
	d2.PrintDate();

	Date d3(d1);
	Date d4(2019, 6, 16);

	d3.PrintDate();
	d4.PrintDate();

	if (d1 == d2)
	{
		cout << "d1与d2日期一致" << endl;
	}

	if (d3 != d4)
	{
		cout << "d3与d4日期不一致" << endl;
	}

	system("pause");
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()const
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	Date operator+(int days)
	{
		Date tmp(*this);
		tmp._day += days;
		return tmp;
	}

	Date& operator++()
	{
		_day + 1;
		return *this;
	}

	Date& operator++(int)
	{
		Date tmp(*this);
		_day += 1;
		return tmp;
	}

	Date* operator&()
	{
		return this;
	}

private:
	int _year;
	int _month;
	int _day;

};

int main()
{
	Date d1;
	Date d2(2019, 6, 16);

	d1.PrintDate();
	d2.PrintDate();

	d2 = d1;

	d2.PrintDate();

	d2 = d2 + 10;
	d2.PrintDate();

	system("pause");
	return 0;
}
#endif

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void TestFunc1()
	{
		_day = 1;
	}

	void TestFunc2()const
	{

	}

	void TestWithConst()const
	{
		TestFunc1();
	}

	const Date* operator&()const
	{
		return this;
	}

private:
	int _year;
	int _month;
	int _day;

};

int main()
{
	//const Date d(2019, 6, 16);
	//d.TestFunc();

	Date d(2019, 6, 16);
	d.TestFunc();

	system("pause");
	return 0;
}