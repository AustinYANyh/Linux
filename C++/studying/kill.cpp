//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" ) // 设置入口地址

#include <iostream>
#include <windows.h>
#include <tlhelp32.h>
#include <string>
#include <winnls.h>
#include <cstring>
#include <atlstr.h>

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

//当前进程提权
BOOL EnableDebugPrivilege()
{
	HANDLE hToken;
	BOOL fOk = FALSE;
	if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken))
	{
		TOKEN_PRIVILEGES tp;
		tp.PrivilegeCount = 1;
		LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &tp.Privileges[0].Luid);

		tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
		AdjustTokenPrivileges(hToken, FALSE, &tp, sizeof(tp), NULL, NULL);

		fOk = (GetLastError() == ERROR_SUCCESS);
		CloseHandle(hToken);
	}
	return fOk;
}


HMODULE GetSelfModuleHandle()
{
	MEMORY_BASIC_INFORMATION mbi;
	return ((::VirtualQuery(GetSelfModuleHandle, &mbi, sizeof(mbi)) != 0) ? (HMODULE)mbi.AllocationBase : NULL);
}

CString GetCurrentPath(void)
{
	TCHAR path[MAX_PATH] = { 0 };
	memset(path, 0, sizeof(path));
	GetModuleFileName(GetSelfModuleHandle(), path, sizeof(path));
	int l = _tcslen(path);
	TCHAR ch = 0;
	while ('\\' != (ch = *(path + --l)));
	*(path + l + 1) = 0;
	return CString(path);
}

int main()
{
	if (!EnableDebugPrivilege())
		std::cout << "提权失败!" << std::endl;
	USES_CONVERSION;
	string str(W2A(GetCurrentPath()));
	str.append("kill.exe");
	HWND hq = FindWindowA(nullptr, str.c_str()); //W2A(szBuffer));
	DWORD dwPID;
	if (hq != nullptr)
		ShowWindow(hq, 0); //隐藏这个窗口

	while (true)
	{
		DWORD tokillpid;
		HANDLE hsnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		if (INVALID_HANDLE_VALUE == hsnap)
		{
			std::cout << "sorry create snap of the processes failed!" << endl;
			return 0;
		}
		else
		{
			PROCESSENTRY32 pe;
			pe.dwSize = sizeof(PROCESSENTRY32);
			int b = ::Process32First(hsnap, &pe);
			while (b)
			{
				std::cout << "进程名:" << aaaa(pe.szExeFile) << "  进程ID:"
					<< pe.th32ProcessID << endl;
				if (
					aaaa(pe.szExeFile).find("Overwatch") != -1 ||
					aaaa(pe.szExeFile).find("Battle.net") != -1 ||
					aaaa(pe.szExeFile).find("NemuPlayer") != -1)
				{
					KillProcess(pe.th32ProcessID);
					std::cout << endl << endl << "已杀死 " << aaaa(pe.szExeFile) << endl << endl;
				}
				b = ::Process32Next(hsnap, &pe);
			}
		}
		Sleep(2 * 60 * 1000);
		::CloseHandle(hsnap);
	}

	std::cout << endl << endl << "未找到Nemu模拟器主程序 、Battle.Net 或者 Overwatch的进程...." << endl << endl;

	return 0;
}
