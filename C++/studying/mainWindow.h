#include "commo.h"
#include "scan.hpp"
#include "dataManage.hpp"
#include <iostream>
//#include "scanManage.hpp"

class mainWind :public WindowImplBase
{
public:
	mainWind()
	{

	}

	void Notify(TNotifyUI& msg);

	void Show();

	void Clear();

protected:

	virtual CDuiString GetSkinFolder();

	virtual CDuiString GetSkinFile();

	virtual LPCTSTR GetWindowClassName(void) const;
};

void mainWind::Show()
{
	//scanManage::CreateIntance()->getDataList();

	//将数据库中的内容显示到列表中
	//////////////////////////////////////////////////////////////////////////
	char sql[4096] = { 0 };
	sprintf_s(sql, "select * from everything;");
	vector<vector<string>> res = DataManager::GetInstance()->Search(sql);

	CListUI* pListUI = (CListUI*)m_PaintManager.FindControl(_T("LISTDATA"));
	pListUI->RemoveAll();

	for (int i = 0; i < res.size(); ++i)
	{
		//std::cout << "[" << i + 1 << "]" << " " << res[i][1] << "		      		" << res[i][2] << std::endl;
		vector<string>& strItem = res[i];
		CListTextElementUI* pData = new CListTextElementUI;

		pData->SetAttribute(_T("align"), _T("center"));
		pListUI->Add(pData);

		//需要的是PLCSTR类型的
		pData->SetText(0, strItem[1].c_str());
		pData->SetText(1, strItem[2].c_str());
	}
	//////////////////////////////////////////////////////////////////////////
}

void mainWind::Clear()
{
	CListUI* pListUI = (CListUI*)m_PaintManager.FindControl(_T("LISTDATA"));
	pListUI->RemoveAll();
}