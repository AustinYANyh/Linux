#include "scanManage.hpp"
#include <signal.h>
#include <iostream>

MYSQL* mysql = MySQLInit();
MySQL mySql(mysql);

mutex _mutex;

int main()
{
	signal(SIGINT, [](int)
	{
		MySQLRelease(mysql);
		exit(0);
	});

	scanManage::CreateIntance();

	system("pause");
	return 0;
}