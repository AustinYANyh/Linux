#include "commo.h"
#include "mawin.h"
#include "mysql.h"


CDuiString MainWd::GetSkinFolder()
{
	return _T("");
}

CDuiString MainWd::GetSkinFile()
{
	return _T("MainWind.xml");
}

LPCTSTR MainWd::GetWindowClassName(void) const
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

#if 0
void MainWd::SelectEmployee()
{
	string strSQL = "select * from employee";

	CComboBoxUI* pCombo = (CComboBoxUI*)m_PaintManager.FindControl(_T("comboGender"));
	CDuiString strStyle = pCombo->GetText();

	if (strStyle == _T("��"))
	{
		strSQL += ";";
	}
	else if (strStyle == _T("����"))
	{
		strSQL += " where name='";
		CDuiString strName = (CEditUI*)m_PaintManager.);
	}

	MySQL mysql;
	mysql.ConnectMysql("localhost", "root", "123123", "supmarket");
	mysql.Select(strSQL);
}

void MainWd::InsertEmployee()
{
	//�ӽ����л�ȡԱ������Ϣ
	CDuiString strName=((CEditUI*)m_PaintManager.FindControl(_T("")))->GetText();
	CDuiString strGender = ((CComboBoxUI*)m_PaintManager.FindControl(_T("")))->GetText();
	CDuiString strBirthday = ((CEditUI*)m_PaintManager.FindControl(_T("")))->GetText();
	CDuiString strPosition = ((CComboBoxUI*)m_PaintManager.FindControl(_T("")))->GetText();
	CDuiString strTel = ((CEditUI*)m_PaintManager.FindControl(_T("")))->GetText();
	CDuiString strSal = ((CEditUI*)m_PaintManager.FindControl(_T("")))->GetText();

	CListUI* pListUI = (CListUI*)m_PaintManager.FindControl(_T(""));
	char sz_count[32] = { 0 };
	_itoa(pListUI->GetCount, sz_count, 0);
	pListUI->GetCount();
	
	string strSQL = "insert into employee values(id='";
	strSQL+=
	strSQL += "',name='";
	strSQL += StringFromLPCTSTR(strName);
	strSQL += StringFromLPCTSTR(strName);
	strSQL += "',gender='";
	strSQL += StringFromLPCTSTR(strGender);
	strSQL += "',birthday='";
	strSQL += StringFromLPCTSTR(strBirthday);
	strSQL += "',position='";
	strSQL += StringFromLPCTSTR(strPosition);
	strSQL += "',telphone='"; 
	strSQL += StringFromLPCTSTR(strTel);
	strSQL += "',salary='";
	strSQL += StringFromLPCTSTR(strSal);
	strSQL += "');";

	MySQL mysql;
	mysql.ConnectMysql("localhost", "root", "123123", "supmarket");
	mysql.Insert(strSQL);

	//��Ա����Ϣ���뵽list��

}

void MainWd::DeleteEmployee()
{
	//��ȡ��ǰѡ��
	CListUI* pListUI = (CListUI*)m_PaintManager.FindControl(_T(""));

	int lineno = pListUI->GetCurSel();
	CListTextElementUI* pRow = (CListTextElementUI*)pListUI->GetItemAt(lineno);

	//�����ݿ�ɾ��Ա����Ϣ
	CDuiString strName = pRow->GetText(0);

	string strSQL = "delete from employee where name='";
	strSQL += StringFromLPCTSTR(strName.GetData());
	strSQL += "';";

	MySQL mysql;
	mysql.Delete(strSQL);



	//��list�а���Ϣ�Ƴ�
	pListUI->RemoveAt(lineno);
}
#endif
