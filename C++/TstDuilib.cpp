#pragma once
#include <UIlib.h>
using namespace DuiLib;

#ifdef _DEBUG
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_ud.lib")
#   else
#       pragma comment(lib, "DuiLib_d.lib")
#   endif
#else
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_u.lib")
#   else
#       pragma comment(lib, "DuiLib.lib")
#   endif
#endif


#if 0
class CDuiFrameWnd : public CWindowWnd, public INotifyUI
{
public:
	virtual LPCTSTR GetWindowClassName() const { return _T("DUIMainFrame"); }
	virtual void    Notify(TNotifyUI& msg) {}

	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		LRESULT lRes = 0;

		if (uMsg == WM_CREATE)
		{
			CControlUI *pWnd = new CButtonUI;
			pWnd->SetText(_T("Hello World"));   // ��������
			pWnd->SetBkColor(0xFF00FF00);       // ���ñ���ɫ

			m_PaintManager.Init(m_hWnd);
			m_PaintManager.AttachDialog(pWnd);
			return lRes;
		}

		if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes))
		{
			return lRes;
		}

		return __super::HandleMessage(uMsg, wParam, lParam);
	}

protected:
	CPaintManagerUI m_PaintManager;
};
#endif

#if 0  
class CDuiFrameWnd : public CWindowWnd, public INotifyUI
{
public:
	virtual LPCTSTR GetWindowClassName() const { return _T("DUIMainFrame"); }
	virtual void    Notify(TNotifyUI& msg)
	{
		if (msg.sType == _T("click"))
		{
			if (msg.pSender->GetName() == _T("btnDeer"))
			{
				::MessageBox(NULL, _T("������,û����Ҫ����"), _T("�޴���¹"), NULL);
			}
			if (msg.pSender->GetName() == _T("btnClose"))
			{
				::MessageBox(NULL, _T("�ر����ɵɵ�Ĵ���"), _T("¹���޴�"), NULL);
				::PostQuitMessage(0);
			}
		}
	}

	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		LRESULT lRes = 0;

		if (uMsg == WM_CREATE)
		{
			CControlUI *pWnd = new CButtonUI;
			pWnd->SetName(_T("btnDeer"));      // ���ÿؼ������ƣ�����������ڱ�ʶÿһ���ؼ�������Ψһ���൱��MFC����Ŀؼ�ID
			pWnd->SetText(_T("stupid deer"));   // ��������
			pWnd->SetBkColor(0xFF00FF00);       // ���ñ���ɫ
			
			//CControlUI *mybutton = new CControlUI;
			//mybutton->SetName(_T("btnClose"));
			//mybutton->SetText(_T("close window"));


			m_PaintManager.Init(m_hWnd);
			
			m_PaintManager.AttachDialog(pWnd);
			//m_PaintManager.AttachDialog(mybutton);

			m_PaintManager.AddNotifier(this);   // ��ӿؼ�����Ϣ��Ӧ��������Ϣ�ͻᴫ�ﵽduilib����Ϣѭ�������ǿ�����Notify����������Ϣ����
			return lRes;
		}

		// ����3����ϢWM_NCACTIVATE��WM_NCCALCSIZE��WM_NCPAINT��������ϵͳ������
#if 0
		else if (uMsg == WM_NCACTIVATE)
		{
			if (!::IsIconic(m_hWnd))
			{
				return (wParam == 0) ? TRUE : FALSE;
			}
		}
		else if (uMsg == WM_NCCALCSIZE)
		{
			return 0;
		}
		else if (uMsg == WM_NCPAINT)
		{
			return 0;
		}

		if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes))
		{
			return lRes;
		}
#endif 
		return __super::HandleMessage(uMsg, wParam, lParam);
	}

protected:
	CPaintManagerUI m_PaintManager;
};

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);

	CDuiFrameWnd duiFrame;
	duiFrame.Create(NULL, _T(""), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	duiFrame.ShowModal();
	return 0;
}
#endif



#include <Windows.h>
#include "../DuiLib/StdAfx.h" 
using namespace DuiLib;
class CMyWnd : public CWindowWnd, public INotifyUI
{
public:
	CMyWnd(){}

	LPCTSTR GetWindowClassName() const
	{
		return L"MyWnd";
	}

	UINT GetClassStyle() const{
		return UI_CLASSSTYLE_FRAME | CS_DBLCLKS;
	}

	void Notify(TNotifyUI& msg)
	{
		//�ж��Ƿ�Ϊ����¼�
		if (msg.sType == L"click")
		{
			//�ж��¼�Դ�����Ƿ�ΪCloseBtn
			if (msg.pSender->GetName() == L"CloseBtn")
			{
				if (IDOK == ::MessageBox(NULL, L"��ϲ���������", L"������", MB_OKCANCEL))
				{
					::PostQuitMessage(0);
				}
			}
		}
	}
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_CREATE:
		{
						  m_PaintMgr.Init(m_hWnd);

						  //������ť
						  m_pCloseBtn = new CButtonUI();
						  m_pCloseBtn->SetName(L"CloseBtn");
						  m_pCloseBtn->SetBkColor(0xFFFF0000);
						  m_pCloseBtn->SetText(L"ÿ��һ��");
						  m_pCloseBtn->SetVisible(true);
						  m_PaintMgr.AttachDialog(m_pCloseBtn);
						  m_PaintMgr.AddNotifier(this);
		}
			break;
		case WM_PAINT:
		{
						 RECT rect = { 100, 100, 200, 150 };
						 m_pCloseBtn->SetPos(rect);
		}
			break;
		case WM_DESTROY:
			::PostQuitMessage(0);
			break;
		}
		LRESULT lRes = 0;
		if (m_PaintMgr.MessageHandler(uMsg, wParam, lParam, lRes)) return lRes;
		return CWindowWnd::HandleMessage(uMsg, wParam, lParam);
	}

	~CMyWnd(){}
private:
	CPaintManagerUI m_PaintMgr;
	CControlUI* m_pCloseBtn;
};
INT WinMain(HINSTANCE hInst, HINSTANCE hPreInst, LPSTR lpCmdLine, INT Show)
{
	CPaintManagerUI::SetInstance(hInst);

	//����������
	CMyWnd* pFrame = new CMyWnd();

	pFrame->Create(NULL, L"¹����", UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	pFrame->CenterWindow();

	//���ô��ڴ�С
	pFrame->ResizeClient(800, 600);
	pFrame->ShowWindow(true);

	CPaintManagerUI::MessageLoop();

	delete pFrame;
	return 0;
}
