#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct ServerInfo
{
	char ip[32];
	int port;
};

struct ConfigManager
{
public:
	ConfigManager(const char* configfile = "TestIo.txt") :_configfile(configfile)
	{

	}

	void WriteBin(const ServerInfo& info)
	{
		ofstream ofs(_configfile, ifstream::out | ifstream::binary);
		ofs.write((const char*)&info, sizeof(ServerInfo));
		ofs.close();
	}

	void ReadBin(ServerInfo& info)
	{
		ifstream ifs(_configfile, ifstream::in | ifstream::binary);
		ifs.read((char*)&info, sizeof(ServerInfo));
		ifs.close();
	}

	void WriteText(const ServerInfo& info)
	{
		ofstream ofs(_configfile);
		ofs << info.ip << endl;
		ofs << info.port << endl;
		ofs.close();
	}

	void ReadText(ServerInfo& info)
	{
		ifstream ifs(_configfile);
		ifs >> info.ip;
		ifs >> info.port;

		ifs.close();
	}

private:
	string _configfile;
};

int main()
{
	ConfigManager cfmager;

	ServerInfo wtinfo;
	ServerInfo rdinfo;

	strcpy(wtinfo.ip, "127.0.0.1");
	wtinfo.port = 80;


	cfmager.WriteBin(wtinfo);
	cfmager.ReadBin(rdinfo);

	cout << rdinfo.ip << endl;
	cout << rdinfo.port << endl;


	cfmager.WriteText(wtinfo);
	cfmager.ReadText(rdinfo);

	cout << rdinfo.ip << endl;
	cout << rdinfo.port << endl;

	system("pause");
	return 0;
}