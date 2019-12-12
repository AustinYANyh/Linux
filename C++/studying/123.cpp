#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <io.h>
#include <WinSock2.h>
#include <mysql.h>

using namespace std;

void dataList(string path, vector<string>& dirs, vector<string>& files)
{
	path += "\\*.*";
	_finddata_t file;
	dirs.clear();
	files.clear();
	intptr_t handle = _findfirst(path.c_str(), &file);
	if (handle == -1)
	{
		cout << "open file failed" << endl;
		return;
	}

	while (_findnext(handle, &file) == 0)
	{
		if (file.attrib & _A_SUBDIR)
		{
			if (strcmp(file.name, ".") != 0 && strcmp(file.name, "..") != 0)
			{
				dirs.push_back(file.name);
			}
		}
		else
		{
			files.push_back(file.name);
		}
	}
}

int main()
{
	vector<string> dirs;
	vector<string> files;
	dataList("D:/test", dirs, files);

	for (auto e : dirs)
	{
		cout << e << endl;
	}

	char sql[4096] = { 0 };
	//"insert into everything values(13,'D:/TEXT',\"新建\");";
	string a = "新建";
	sprintf(sql, "insert into everything values(8,'D:/TEXT','%s');", a.c_str());
	MYSQL* mysql = nullptr;
	mysql = mysql_init(mysql);
	//mysql_set_character_set(mysql, "gbk");
	mysql_options(mysql, MYSQL_SET_CHARSET_NAME, "gbk");

	if (mysql_real_connect(mysql, "111.229.13.33", "luzihan", "124152", "myeverything", 3306, NULL, 0) == NULL)
	{
		cout << "失败了" << endl;
	}

	mysql_query(mysql, "set names 'gbk'");
	mysql_query(mysql, sql);

	system("pause");
	return 0;
}