#include "LogIn.h"
#include "MainWind.h"

CDuiString LoginWind::GetSkinFolder()//xml文件目录
{
	return _T("");
}

CDuiString LoginWind::GetSkinFile()//xml文件名
{
	return _T("LoginWind.xml");
}

LPCTSTR LoginWind::GetWindowClassName(void) const//窗口类的名字
{
	return _T("LoginWind");
}

void LoginWind::Notify(TNotifyUI& msg)
{
	if (msg.sType == _T("click"))
	{
		if (msg.pSender->GetName() == _T("btnClose"))
		{
			Close();
		}
		else if (msg.pSender->GetName() == _T("btnMin"))
		{
			//MessageBox(NULL, _T("最小化"), _T("提示信息"), IDOK);
			::SendMessage(m_hWnd,WM_SYSCOMMAND,SC_MINIMIZE,0);
		}
		else if (msg.pSender->GetName() == _T("btnLogin"))
		{
			LoginWind::Login();
		}
	}
}

void LoginWind::Login()
{
	//从编辑框获取用户名和密码
	CEditUI* pEditUserName = (CEditUI*)m_PaintManager.FindControl(_T("edtLogin"));
	CDuiString strUsername = pEditUserName->GetText();

	CEditUI* pEditUserPasswoed = (CEditUI*)m_PaintManager.FindControl(_T("edtPassword"));
	CDuiString strUserPassword = pEditUserPasswoed->GetText();

	if (strUsername.IsEmpty())
	{
		MessageBox(m_hWnd, _T("请输入用户名!"), _T("提示信息"), IDOK);
	}

	if (strUserPassword.IsEmpty())
	{
		MessageBox(m_hWnd, _T("请输入密码!"), _T("提示信息"), IDOK);
	}
	//查询数据库,检测该用户是否存在

	//隐藏登陆窗口
	ShowWindow(false);

	//创建主窗口
	MainWd mainWd;

	mainWd.Create(NULL, _T("LoginWind"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	mainWd.CenterWindow();
	mainWd.ShowModal();
}