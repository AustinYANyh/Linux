#include "commo.h"
#include "mainWindow.h"

using namespace std;

CDuiString mainWind::GetSkinFolder()
{
	return _T("");
}

CDuiString mainWind::GetSkinFile()
{
	return _T("mainWind.xml");
}

LPCTSTR mainWind::GetWindowClassName(void) const
{
	return _T("mainWind");
}

void mainWind::Notify(TNotifyUI& msg)
{
	if (msg.sType == _T("click"))
	{
		if (msg.pSender->GetName() == _T("BTN_CLOSE"))
		{
			Close();
		}
		else if (msg.pSender->GetName() == _T("BTN_MIN"))
		{
			::SendMessage(m_hWnd, WM_SYSCOMMAND, SC_MINIMIZE, 0);
		}
		else if (msg.pSender->GetName() == _T("BTN_SHOW"))
		{
			mainWind::Show();
		}
		else if (msg.pSender->GetName() == _T("BTN_CLEAR") || msg.pSender->GetName() == _T("BTN_CLEAR2"))
		{
			mainWind::Clear();
		}
		else if (msg.pSender->GetName() == _T("BTN_SEARCH"))
		{
			mainWind::Search();
		}
	}
}

std::string StringFromLPCTSTR(LPCTSTR str)
{
#ifdef _UNICODE
	int size_str = WideCharToMultiByte(CP_UTF8, 0, str, -1, 0, 0, NULL, NULL);

	char* point_new_array = new char[size_str];

	WideCharToMultiByte(CP_UTF8, 0, str, -1, point_new_array, size_str, NULL, NULL);

	std::string return_string(point_new_array);
	delete[] point_new_array;
	point_new_array = NULL;
	return return_string;
#else
	return std::string(str);
#endif
}

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	//CPaintManagerUI::SetInstance(hInstance);

	//MainWd duiFrame;

	//duiFrame.Create(NULL, _T("DUIMainFrame"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);

	//duiFrame.ShowModal();


	CPaintManagerUI::SetInstance(hInstance);

	mainWind mainWind;
	//HICON hIcon = ::LoadIcon(hInstance, L"IDI_ICON_LOGO");
	
	mainWind.Create(NULL, _T("mainWind"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	//HICON hIcon = ::LoadIcon(hInstance, MAKEINTRESOURCE("IDI_ICON_LOGO"));
	//::SendMessage(mainWind.GetHWND(), STM_SETICON, IMAGE_ICON, (LPARAM)(UINT)hIcon);

	mainWind.CenterWindow();

	mainWind.ShowModal();

	return 0;
}