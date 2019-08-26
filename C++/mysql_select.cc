#include<mysql/mysql.h>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    MYSQL* mysql = mysql_init(NULL);

    if (mysql_real_connect(mysql, "127.0.0.1", "root", "123", "image", 3306, NULL, 0) == NULL)
    {
	cout << mysql_error(mysql) << endl;
	return -1;
    }

    char sql[4096];

    sprintf(sql, "select * from image_table;");

    if (mysql_query(mysql, sql))
    {
	cout << mysql_error(mysql) << endl;
	return -1;
    }

    MYSQL_RES* mySQLRES = mysql_store_result(mysql);

    if (mySQLRES == NULL)
    {
	cout << mysql_error(mysql) << endl;
	return -1;
    }

    int itemCount = mysql_num_fields(mySQLRES);

    MYSQL_ROW mySQLROW;

    while (mySQLROW = mysql_fetch_row(mySQLRES))
    {
	for (size_t i = 0; i < itemCount; ++i)
	{
	    cout << mySQLROW[i] << " ";
	}
	cout<<endl;
    }

    mysql_free_result(mySQLRES);

    mysql_close(mysql);

    return 0;
}
