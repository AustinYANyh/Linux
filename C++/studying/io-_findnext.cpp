#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
#include<vector>
#include<io.h>

using namespace std;

int main()
{
	_finddata_t file;
	string path;
	cout << "����·��:" << endl;

	while(cin >> path)
	{
		vector<string> dirs;
		vector<string> files;
		path += "\\*.*";
		intptr_t handle = _findfirst(path.c_str(), &file);
		if (handle == -1)
		{
			cout << "open file failed" << endl;
			return 0;
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

		cout << "Ŀ¼����" << dirs.size() << "��" << endl;

		for (auto e : dirs)
		{
			cout << e << endl;
		}

		cout << "�ļ�����:" << files.size() << "��" << endl;

		for (auto e : files)
		{
			cout << e << endl;
		}
	}

	system("pause");
	return 0;
}