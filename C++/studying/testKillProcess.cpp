#include "test1/test.hpp"
#include <windows.h>
#include <stdint.h>
#include <tlhelp32.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <tchar.h> //使用_T()

using namespace std;

DWORD GetProcessIDByName(const char *pName)
{
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (INVALID_HANDLE_VALUE == hSnapshot)
    {
        return NULL;
    }
    PROCESSENTRY32 pe = {sizeof(pe)};
    for (BOOL ret = Process32First(hSnapshot, &pe); ret; ret = Process32Next(hSnapshot, &pe))
    {
        if (strcmp((char *)pe.szExeFile, pName) == 0)
        {
            CloseHandle(hSnapshot);
            return pe.th32ProcessID;
        }
    }
    CloseHandle(hSnapshot);
    return 0;
}

bool KillProcess(DWORD dwPid)
{
    printf("Kill进程Pid = %d\n", dwPid);
    getchar();
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
#if 0 
    // system("chcp 65001");
    // system("cls");
    // string a = "123";
    // cout << 123 << endl;
    // cout << "这边字符串居然不乱码" << endl;

    // int aa = 10;
    // int bb = 20;
    // TestFunc *tst = new TestFunc();
    // cout << tst->add(aa, bb) << endl;
#endif

    //HWND hq = FindWindowA(nullptr, "C:\\Users\\29572\\Desktop\\CncTask.exe");
    // TCHAR szBuffer[MAX_PATH] = {0};
    // OPENFILENAME ofn = {0};
    // ofn.lStructSize = sizeof(ofn);
    // ofn.lpstrFilter = _T("Exe文件(*.exe)\0*.exe\0所有文件(*.*)\0*.*\0"); //要选择的文件后缀
    // ofn.lpstrInitialDir = _T("C:\\Users\\29573\\Desktop");               //默认的文件路径
    // ofn.lpstrFile = szBuffer;                                            //存放文件的缓冲区
    // ofn.nMaxFile = sizeof(szBuffer) / sizeof(*szBuffer);
    // ofn.nFilterIndex = 0;
    // ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER; //标志如果是多选要加上OFN_ALLOWMULTISELECT
    // BOOL bSel = GetOpenFileName(&ofn);

    //USES_CONVERSION;
    string filename;
    cin >> filename;
    HWND hq = FindWindowA(nullptr, filename.c_str()); //W2A(szBuffer));
    if (hq != nullptr)
    {
        //ShowWindow(hq, 0); //隐藏这个窗口
        DWORD dwPID;
        DWORD dwThreadID = ::GetWindowThreadProcessId(hq, &dwPID);
        KillProcess(dwPID);
    }
    return 0;
}