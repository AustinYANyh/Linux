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


	system("pause");
	return 0;
}