#define  _AFXDLL
#include <iostream>
#include <direct.h>
#include <io.h>
#include <afx.h>
#include <atlbase.h>

using namespace std;

int main()
{
	CFileFind finder;
	char buffer[1024];

	//"C:\\Users\\29572\\Desktop\\cpp\\*.*";
	CString path = _getcwd(buffer, 1024); 

	USES_CONVERSION;
	//LPCWSTR	pName = T2W(path);
	bool res = finder.FindFile(path);
	while (res)
	{
		res = finder.FindNextFile();
		wcout << finder.GetFileName().GetString() << endl;
	}
	return 0;
}