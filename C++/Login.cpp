#include "LogIn.h"
#include "MainWind.h"

CDuiString LoginWind::GetSkinFolder()//xml�ļ�Ŀ¼
{
	return _T("");
}

CDuiString LoginWind::GetSkinFile()//xml�ļ���
{
	return _T("LoginWind.xml");
}

LPCTSTR LoginWind::GetWindowClassName(void) const//�����������
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
			//MessageBox(NULL, _T("��С��"), _T("��ʾ��Ϣ"), IDOK);
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
	//�ӱ༭���ȡ�û���������
	CEditUI* pEditUserName = (CEditUI*)m_PaintManager.FindControl(_T("edtLogin"));
	CDuiString strUsername = pEditUserName->GetText();

	CEditUI* pEditUserPasswoed = (CEditUI*)m_PaintManager.FindControl(_T("edtPassword"));
	CDuiString strUserPassword = pEditUserPasswoed->GetText();

	if (strUsername.IsEmpty())
	{
		MessageBox(m_hWnd, _T("�������û���!"), _T("��ʾ��Ϣ"), IDOK);
	}

	if (strUserPassword.IsEmpty())
	{
		MessageBox(m_hWnd, _T("����������!"), _T("��ʾ��Ϣ"), IDOK);
	}
	//��ѯ���ݿ�,�����û��Ƿ����

	//���ص�½����
	ShowWindow(false);

	//����������
	MainWd mainWd;

	mainWd.Create(NULL, _T("LoginWind"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	mainWd.CenterWindow();
	mainWd.ShowModal();
}