#define _CRT_SECURE_NO_WARNINGS

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
			bool alive = false;
			while (b)
			{
				//std::cout << "进程名:" << aaaa(pe.szExeFile) << "  进程ID:"
					//<< pe.th32ProcessID << endl;
				if (aaaa(pe.szExeFile).find("kill.exe") != -1)
				{
					alive = true;
					cout << "protect进程正常运行,kill进程运行正常!" << endl << endl;
					break;
				}
				b = ::Process32Next(hsnap, &pe);

			}
			const char* szStr = "C:\\Users\\Austin_Yan\\Desktop\\kill.exe";
			CString str = CString(szStr);
			USES_CONVERSION;
			LPCWSTR wszClassName = new WCHAR[str.GetLength() + 1];
			wcscpy((LPTSTR)wszClassName, T2W((LPTSTR)str.GetBuffer(NULL)));
			str.ReleaseBuffer();

			if (alive == false)
			{
				ShellExecute(NULL, NULL, str, NULL, NULL, SW_SHOWNORMAL);
				cout << "未检测到kill进程,kill进程重新启动!" << endl << endl;
			}
		}
		Sleep(10 * 1000);
		::CloseHandle(hsnap);
	}
}
