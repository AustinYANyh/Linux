#pragma ocne

#include<string>
#include<iostream>
#include<vector>
#include<io.h>
#include"dataManage.hpp"
#include<set>
#include<thread>
#include<mutex>
#include<signal.h>

using namespace std;


//扫描当前路径下目录和文件
static void dataList(string path, vector<string>& dirs, vector<string>& files)
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
	void scanInit(string path);

	void startScan()
	{
		string path;
		path = "D:/zhuomian";

		while (1)
		{
			scanInit(path);
			this_thread::sleep_for(chrono::seconds(5));
		}
	}

	static scanManage* CreateIntance()
	{
		static scanManage Scan;
		//static std::thread thd(&startScan, &Scan);
		//thd.join();

		return &Scan;
	}

	void getDataList();

	~scanManage()
	{

	}

public:
	mutex _mutex;
private:
	scanManage()
	{

	}
	_finddata_t _file;
	string _path;
};

void scanManage::scanInit(string path)
{
	vector<string> localDirs;
	vector<string> localFiles;

	string whereStr = "select * from everything where path = '";
	whereStr += path;
	whereStr += "';";

	vector<vector<string>> res = DataManager::GetInstance()->Search(whereStr);

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
		sprintf_s(sql, "select * from everything;");
		if (*localIt < *dbIt)
		{
			vector<vector<string>> res = DataManager::GetInstance()->Search(sql);
			int lineno = res.size();
			sprintf_s(sql, "insert into everything values(%d,'%s','%s');", lineno + 1, path.c_str(), (*localIt).c_str());

			//_mutex.lock();
			DataManager::GetInstance()->InsertData(sql);
			//_mutex.unlock();
			localIt++;
		}
		else if (*localIt > *dbIt)
		{
			sprintf_s(sql, "delete from everything where name='%s';", (*dbIt).c_str());
			//_mutex.lock();
			DataManager::GetInstance()->DeleteData(sql);
			//_mutex.unlock();
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
		sprintf_s(sql, "select * from everything;");
		vector<vector<string>> res = DataManager::GetInstance()->Search(sql);
		int lineno = res.size();
		sprintf_s(sql, "insert into everything values(%d,'%s','%s');", lineno + 1, path.c_str(), (*localIt).c_str());
		//_mutex.lock();
		DataManager::GetInstance()->InsertData(sql);
		//_mutex.unlock();
		localIt++;
	}
	while (dbIt != setDb.end())
	{
		char sql[4096] = { 0 };
		sprintf_s(sql, "delete from everything where name='%s';", (*dbIt).c_str());
		//_mutex.lock();
		DataManager::GetInstance()->DeleteData(sql);
		//_mutex.unlock();
		dbIt++;
	}

	//递归操作子文件夹
	for (auto &e : localDirs)
	{
		string subPath = path;
		subPath += "/";
		subPath += e;
		scanInit(subPath);
	}
}

void scanManage::getDataList()
{
	char sql[4096] = { 0 };
	sprintf_s(sql, "select * from everything;");
	vector<vector<string>> res = DataManager::GetInstance()->Search(sql);

	for (int i = 0; i < res.size(); ++i)
	{
		cout << "[" << i + 1 << "]" << " " << res[i][1] << "		      		" << res[i][2] << endl;
	}
}

/*
int main()
{
signal(SIGINT, [](int)
{
//MySQLRelease(mysql);
exit(0);
});

//DataManager::GetInstance()->Init();
//vector<vector<string>> res = DataManager::GetInstance()->Search("select * from everything;");
//scanManage::CreateIntance()->startScan();
scanManage::CreateIntance()->getDataList();

system("pause");
return 0;
}
*/