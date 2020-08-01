#include <iostream>
#include <windows.h>
#include <tlhelp32.h>
#include <string>
#include <winnls.h>

using namespace std;

string aaaa(wchar_t* wText)
{
	string szDst;
	DWORD dwNum = WideCharToMultiByte(CP_OEMCP, NULL, wText, -1, NULL, 0, NULL, FALSE);
	char* psText;
	psText = new char[dwNum];
	WideCharToMultiByte(CP_OEMCP, NULL, wText, -1, psText, dwNum, NULL, FALSE);
	szDst = psText;
	// 删除临时du变量
	delete[] psText;
	return szDst;
}

bool KillProcess(DWORD dwPid)
{
	cout << endl << endl;
	printf("Kill进程Pid = %d\n", dwPid);
	//关闭进程
	HANDLE killHandle = OpenProcess(PROCESS_TERMINATE | PROCESS_QUERY_INFORMATION | // Required by Alpha
		PROCESS_CREATE_THREAD |                     // For CreateRemoteThread
		PROCESS_VM_OPERATION |                      // For VirtualAllocEx/VirtualFreeEx
		PROCESS_VM_WRITE,                           // For WriteProcessMemory);
		FALSE, dwPid);
	if (killHandle == nullptr)
		return false;
	TerminateProcess(killHandle, 0);
	return true;
}

int main()
{
	DWORD tokillpid;
	HANDLE hsnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (INVALID_HANDLE_VALUE == hsnap)
	{
		cout << "sorry create snap of the processes failed!" << endl;
		return 0;
	}
	else
	{
		PROCESSENTRY32 pe;
		pe.dwSize = sizeof(PROCESSENTRY32);
		int b = ::Process32First(hsnap, &pe);
		while (b)
		{
			cout << "进程名:" << aaaa(pe.szExeFile) << "  进程ID:"
				<< pe.th32ProcessID << endl;
			if (aaaa(pe.szExeFile).find("TaskController") != -1 ||
				aaaa(pe.szExeFile).find("CncTask") != -1)
			{
				KillProcess(pe.th32ProcessID);
				cout << endl << endl << "已杀死 " << aaaa(pe.szExeFile) << endl << endl;
				system("pause");
				return 0;
			}
			b = ::Process32Next(hsnap, &pe);
		}
	}
	::CloseHandle(hsnap);
	cout << endl << endl << "未找到TaskController 或者 CncTask的进程...." << endl << endl;

	system("pause");
	return 0;
}
