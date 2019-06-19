#pragma once

#include <iostream>

using namespace std;

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

	Date& operator=(const Date& d)
	{
		if (_year != d._year&&_month != d._month&&_day != d._day)
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

	Date operator-(int days)
	{
		Date tmp(*this);
		tmp._day -= days;
		return tmp;
	}

	Date& operator++()
	{
		*this=*this+1;
		return *this;
	}

	Date operator++(int)
	{
		Date tmp(*this);
		*this = *this + 1;
		return tmp;
	}

	bool operator>(const Date& d)
	{
		if (_year == d._year)
		{
			if (_month = d._month)
			{
				if (_day > d._day)
				{
					return true;
				}
				return false;
			}
			else if (_month > d._month)
			{
				return true;
			}
			return false;
		}
		else if (_year > d._year)
		{
			return true;
		}
		return false;
	}

	bool operator<(const Date& d)
	{
		return !(*this > d) && (*this != d);
	}

	bool operator>=(const Date& d)
	{
		return !(*this < d);
	}

	bool operator<=(const Date& d)
	{
		return !(*this > d);
	}

	int operator-(const Date& d)
	{
		Date min(*this);
		Date max(d);
		int flag = -1;

		if (*this > d)
		{
			max = *this;
			min = d;
			flag = 1;
		}

		int count = 0;
		while (min != max)
		{
			count++;
			min+=1;
		}
		return flag*count;
	}

	bool operator==(const Date& d)
	{
		if (_year == d._year&&_month == d._month&&_day == d._day)
		{
			return true;
		}
		return false;
	}

	bool operator!=(const Date& d)
	{
		if (_year == d._year&&_month == d._month&&_day == d._day)
		{
			return false;
		}
		return true;
	}

	Date& operator+=(int days)//5.25 6.35 6.4
	{
		_day += days;

		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month += 1;

			if (_month > 12)
			{
				_year += 1;
				_month = 1;
			}
		}
		return *this;
	}

	Date& operator-=(int days)//6.17 6.7
	{
		//5.11 -20 4.41 4.21
		//5.11-11=4.30 4.30-9=4.21
		while (_day < days)
		{
			_month -= 1;

			if (_month == 0)
			{
				_year -= 1;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		_day -= days;
		return *this;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	int GetMonthDay(int year, int month)
	{
		int array[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		if (month == 2 && isYear(year) == true)
		{
			++array[2];
		}
		return array[month];
	}

	bool isYear(int year)
	{
		if (year % 400 == 0)
		{
			return true;
		}
		else if (year % 100 != 0 && year % 4 == 0)
		{
			return true;
		}
		return false;
	}

private:
	int _year;
	int _month;
	int _day;
};