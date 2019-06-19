#include "class-date.h"

int main()
{
	Date d1(2019, 6, 18);
	cout << "d1:";
	d1.PrintDate();
	cout << endl;

	Date d2;
	d2 = d1 - 1;
	cout << "d2=d1-1:";
	d2.PrintDate();
	cout << endl;

	Date d3(2019, 6, 17);
	cout << "d3:";
	d3.PrintDate();
	cout << endl;

	if (d3 == d2)
	{
		cout << "d3 is the same as d2 !" << endl;
	}
	cout << endl;

	cout << "d3-=40:";
	d3 -= 40;
	d3.PrintDate();
	cout << endl;

	int days = d3 - d2;
	cout << "d3与d2相差:";
	cout << days << endl;
	cout << endl;

	if (d3 < d2)
	{
		cout << "d3 is earlier than d2 !" << endl;
	}
	cout << endl;

	cout << "出生日期:";
	Date d4(1996, 9, 10);
	d4.PrintDate();
	cout << endl;

	d4 += 10000;
	Date d5(d4);
	cout << "出生10000天纪念日:";
	d5.PrintDate();
	cout << endl;

	system("pause");
	return 0;
}