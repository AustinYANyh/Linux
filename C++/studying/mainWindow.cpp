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
		else if (msg.pSender->GetName() == _T("BTN_CLEAR"))
		{
			mainWind::Clear();
		}
	}
}

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	//CPaintManagerUI::SetInstance(hInstance);

	//MainWd duiFrame;

	//duiFrame.Create(NULL, _T("DUIMainFrame"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);

	//duiFrame.ShowModal();


	CPaintManagerUI::SetInstance(hInstance);

	mainWind mainWind;

	mainWind.Create(NULL, _T("mainWind"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);

	mainWind.CenterWindow();

	mainWind.ShowModal();

	return 0;
}