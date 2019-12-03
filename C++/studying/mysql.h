#pragma once

#include <iostream>
#include<WinSock2.h>
#include<mysql.h>
#include<vector>

using namespace std;

static MYSQL* MySQLInit()
{
	MYSQL* mysql = mysql_init(NULL);

	mysql_options(mysql, MYSQL_SET_CHARSET_NAME, "utf8");

	if (mysql_real_connect(mysql, "111.229.13.33", "luzihan", "124152", "myeverything", 3306, NULL, 0) == NULL)
	{
		cout << "链接失败" << endl;
		exit(0);
	}
	return mysql;
}


class MySQL
{
public:
	MySQL()
	{
		_mySql = MySQLInit();
	}

	bool ConnectMysql(const char* host, const char* user, const char* password, const char* dbname);

	~MySQL();

	vector<vector<string>> Select(const string& strSQL);

	bool Insert(const string& strSQL);

	bool Delete(const string& strSQL);

	bool Check(const string& strSQL);

	bool Update(const string& strSQL);

private:
	MYSQL* _mySql;
};



MySQL::~MySQL()
{
	mysql_close(_mySql);
}

bool MySQL::ConnectMysql(const char* host, const char* user, const char* password, const char* dbname)
{
	if (mysql_real_connect(_mySql, host, user, password, dbname, 3306, nullptr, 0) == nullptr)
	{
		cout << "连接数据库失败!" << endl;
		return false;
	}
	return true;
}

vector<vector<string>> MySQL::Select(const string& strSQL)
{
	vector<vector<string>> vRet;

	if (mysql_query(_mySql, strSQL.c_str()))
	{
		cout << mysql_error(_mySql) << endl;
		return vRet;
	}

	MYSQL_RES* mySQLRES = mysql_store_result(_mySql);

	if (mySQLRES == nullptr)
	{
		cout << mysql_error(_mySql) << endl;
		return vRet;
	}

	int itemCount = mysql_num_fields(mySQLRES);

	MYSQL_ROW mySQLROW;

	while (mySQLROW = mysql_fetch_row(mySQLRES))
	{
		vector<string> temp;

		for (size_t i = 0; i < itemCount; ++i)
		{
			temp.push_back(mySQLROW[i]);
		}
		vRet.push_back(temp);
	}

	mysql_free_result(mySQLRES);

	return vRet;
}

bool MySQL::Insert(const string& strSQL)
{
	if (mysql_query(_mySql, strSQL.c_str()))
	{
		cout << mysql_error(_mySql) << endl;
		return false;
	}
	return true;
}

bool MySQL::Delete(const string& strSQL)
{
	if (mysql_query(_mySql, strSQL.c_str()))
	{
		cout << mysql_error(_mySql) << endl;
		return false;
	}
	return true;
}

bool MySQL::Check(const string& strSQL)
{
	mysql_query(_mySql, strSQL.c_str());

	MYSQL_RES* result = mysql_store_result(_mySql);

	if (mysql_num_rows(result))
	{
		return true;
	}
	return false;
}

bool MySQL::Update(const string& strSQL)
{
	if (mysql_query(_mySql, strSQL.c_str()))
	{
		cout << mysql_error(_mySql) << endl;
		return false;
	}
	return true;
}
