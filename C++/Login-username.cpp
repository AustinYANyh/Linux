#include "LogIn.h"
#include "MainWind.h"
#include "MySQL.h"

using namespace std;

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
	else if (strUserPassword.IsEmpty())
	{
		MessageBox(m_hWnd, _T("����������!"), _T("��ʾ��Ϣ"), IDOK);
	}

	//��ѯ���ݿ�,�����û��Ƿ����
	else
	{
		//��CDuistringת��Ϊstring
		string username = StringFromLPCTSTR(strUsername.GetData());
		string password = StringFromLPCTSTR(strUserPassword.GetData());

		string que = "select * from employee where name = '"
			+ username + "' and password = '"
			+ password + "'";
				
		MySQL mysql;

		mysql.ConnectMysql("localhost", "root", "123123", "supmarket");

		if (mysql.UpDate(que)==true)
		{
			//���ص�½����
			ShowWindow(false);

			//����������
			MainWd mainWd;

			mainWd.Create(NULL, _T("LoginWind"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
			mainWd.CenterWindow();
			mainWd.ShowModal();
		}
		else
		{
			//�û���������
			MessageBox(m_hWnd, _T("�û��������벻����!"), _T("��ʾ��Ϣ"), NULL);
		}
	}
}