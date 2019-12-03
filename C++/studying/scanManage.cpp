#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<iostream>
#include<vector>
#include<io.h>
#include"mysql.h"
#include<set>

using namespace std;

//扫描当前路径下目录和文件
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

class scanManage
{
public: 
	scanManage() 
	{

	}

	void scanInit(string path)
	{
		vector<string> localDirs;
		vector<string> localFiles;
		MySQL mysql;

		string whereStr = "select * from everything where path = '";
		whereStr += path;
		whereStr += "';";
		vector<vector<string>> res = mysql.Select(whereStr);

		dataList(path, localDirs, localFiles);
		set<string> setLocal;
		set<string> setDb;

		setLocal.insert(localDirs.begin(), localDirs.end());
		setLocal.insert(localFiles.begin(), localFiles.end());

		for (int i = 0; i < res.size(); ++i)
		{
			setDb.insert(res[i][2]);
		}

		auto dbIt = setDb.begin();
		auto localIt = setLocal.begin();

		while (localIt != setLocal.end() && dbIt != setDb.end())
		{
			//本地有,数据库没有,则给数据库插入
			char sql[4096] = { 0 };
			sprintf(sql, "select * from everything;");
			if (*localIt < *dbIt)
			{
				vector<vector<string>> res = mysql.Select(sql);
				int lineno = res.size();
				sprintf(sql, "insert into everything values(%d,'%s','%s');", lineno + 1, path.c_str(),(*localIt).c_str());
				mysql.Insert(sql);
				localIt++; 
			}
			else if (*localIt > *dbIt)
			{
				sprintf(sql, "delete from everything where name='%s';", (*dbIt).c_str());
				mysql.Delete(sql);
				dbIt++;
			}
			else
			{
				localIt++;
				dbIt++;
			}
		}

		//其中一方有多余,插入到后面或者删除多余部分
		while (localIt != setLocal.end())
		{
			char sql[4096] = { 0 }; 
			sprintf(sql, "select * from everything;");
			vector<vector<string>> res = mysql.Select(sql);
			int lineno = res.size();
			sprintf(sql, "insert into everything values(%d,'%s','%s');", lineno + 1, path.c_str(),(*localIt).c_str());
			mysql.Insert(sql);
			localIt++;
		}
		while (dbIt != setDb.end())
		{
			char sql[4096] = { 0 };
			sprintf(sql, "delete from everything where name='%s';", (*dbIt).c_str());
			mysql.Delete(sql);
			dbIt++;
		}

		//递归操作子文件夹
		for (auto &e : localDirs)
		{
			string subPath = path;
			subPath += "\\";
			subPath += e;
			scanInit(subPath);
		}
	}



	void getDataList()
	{
		MySQL mysql;
		char sql[4096] = { 0 };
		sprintf(sql, "select * from everything;");
		vector<vector<string>> res = mysql.Select(sql);

		for (int i = 0; i < res.size(); ++i)
		{
			cout << res[i][1] << "       " << res[i][2] << endl;
		}
	}

	~scanManage()
	{

	}
public:
	MySQL* _mysql;
private:
	_finddata_t _file; 
	string _path;
};

int main()
{
	scanManage scan;
	vector<string> localDirs;
	vector<string> localFiles;

	string path;
	cout << "输入路径:" << endl;
	cin >> path;

	scan.scanInit(path);
	scan.getDataList();
	
	system("pause");
	return 0;
}