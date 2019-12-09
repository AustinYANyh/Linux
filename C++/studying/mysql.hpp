#pragma once

#include<iostream>
#include<WinSock2.h>
#include<mysql.h>
#include<string>
#include<vector>

using namespace std;

class MySQL
{
public:
	MySQL()
	{

	}

	bool MySQLInit();

	vector<vector<string>> Select(const string& strSQL);

	bool Insert(string& strSQL);

	bool Delete(const string& strSQL);

	bool Check(const string& strSQL);

	bool Update(const string& strSQL);

	~MySQL()
	{
		mysql_close(_mySql);
	}
private:
	MYSQL* _mySql;
};

bool MySQL::MySQLInit()
{
	_mySql = mysql_init(NULL);

	mysql_options(_mySql, MYSQL_SET_CHARSET_NAME, "utf8");

	if (mysql_real_connect(_mySql, "111.229.13.33", "luzihan", "124152", "myeverything", 3306, NULL, 0) == NULL)
	{
		cout << "Á´½ÓÊ§°Ü" << endl;
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

bool MySQL::Insert(string& strSQL)
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