#pragma once

#include "mysql.h"
#include <vector>
#include <string>
class DataManager
{
public:
	static DataManager* GetInstance()
	{
		static DataManager data;
		data.Init();

		return &data;
	}

	void Init(); 
	vector<vector<string>> Search(string sql);
	void InsertData(string sql);
	void DeleteData(string sql);

private:
	DataManager()   
	{

	}

	MySQL _mysql;
};

void DataManager::Init()
{
	MYSQL* mysql = MySQLInit();
}

vector<vector<string>> DataManager::Search(string sql)
{
	return _mysql.Select(sql);
}

void DataManager::InsertData(string sql)
{
	_mysql.Insert(sql);
}

void DataManager::DeleteData(string sql)
{
	_mysql.Delete(sql);
}