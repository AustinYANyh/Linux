#include "class-date.h"


void calDate()
{
	int year;
	int month;
	int day;
	int days;
	cout << "请输入年:";
	cin >> year;
	cout << endl;
	cout << "请输入月:";
	cin >> month;
	cout << endl;
	cout << "请输入日:";
	cin >> day;
	cout << endl;

	Date d5(year, month, day);

	cout << "输入计算的天数(负数向前计算):";
	cin >> days;

	cout << endl;

	if (days > 0)
	{
		d5 += days;
	}
	else if (days < 0)
	{
		d5 -= (-days);
	}
	else
	{
		//do nothing
	}

	cout << "结果为:";	

	d5.PrintDate();
	cout << endl;
}

void delDate()
{
	int year1;
	int month1;
	int day1;

	cout << "请输入年:";
	cin >> year1;
	cout << endl;
	cout << "请输入月:";
	cin >> month1;
	cout << endl;
	cout << "请输入日:";
	cin >> day1;
	cout << endl;

	Date d6(year1, month1, day1);

	int year2;
	int month2;
	int day2;

	cout << "请输入年:";
	cin >> year2;
	cout << endl;
	cout << "请输入月:";
	cin >> month2;
	cout << endl;
	cout << "请输入日:"; 	
	cin >> day2;
	cout << endl;

	Date d7(year2, month2, day2);

	cout << "结果为:";
	int days = d6 - d7;

	cout << (-days);

	cout << endl;
}

void xianyu()
{

}

int main()
{

	typedef void(*Func)();

	Func array[3] = 
	{
		xianyu,
		calDate,
		delDate
	};

	while (true)
	{
		cout << "1.计算日期" << endl;
		cout << endl;

		cout << "2.计算天数之差" << endl;
		cout << endl;

		cout << "3.退出"<<endl;
		cout << endl;

		cout << "请输入您的选择:";

		int choice;
		cin >> choice;

		cout << endl;

		if (choice == 3)
		{
			cout << "GoodBye !"<<endl;
			break;
		}
		array[choice]();	
		cout << endl;
	}

	return 0;
}
