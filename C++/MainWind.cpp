#include "MainWind.h"


CDuiString MainWd::GetSkinFolder()//xml�ļ�Ŀ¼
{
	//����Ҫ��,���Զ���exeĿ¼����
	return _T("");
}

CDuiString MainWd::GetSkinFile()//xml�ļ���
{
	return _T("MainWind.xml");
}

LPCTSTR MainWd::GetWindowClassName(void) const//�����������
{
	return _T("MainWind");
}

void MainWd::Notify(TNotifyUI& msg)
{
	if (msg.sType == _T("click"))
	{
		if (msg.pSender->GetName() == _T("btnClose"))
		{
			Close();
		}
		else if (msg.pSender->GetName() == _T("btnMin"))
		{
			::SendMessage(m_hWnd, WM_SYSCOMMAND, SC_MINIMIZE, 0);
		}
	}
	else if (msg.sType == _T("itemselect"))
	{
		if (msg.pSender->GetName() == _T("optEmployee"))
		{

		}
		else if (msg.pSender->GetName() == _T("optGood"))
		{

		}
	}
}