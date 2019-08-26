#include<mysql/mysql.h>
#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

int main()
{
    MYSQL* mysql = mysql_init(NULL);

    if(mysql_real_connect(mysql, "127.0.0.1", "root", "123", "image", 3306, NULL, 0)==NULL)
    {
	cout<<mysql_error(mysql)<<endl;
	return -1;
    }

    char sql[4096];

    sprintf(sql,"insert into image_table values('1','tset.jpg',1024,'2019-08-26','png','D:/zhuomian','abcd');");

    mysql_query(mysql,sql);

    mysql_close(mysql);

    return 0;
}
