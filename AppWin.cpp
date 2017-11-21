// Implementation of the AppWin class.
//
//////////////////////////////////////////////////////////////////////


#include "_StdAfx.h"


class CAppWin : public WinClzz::IWinBase
{
public:
	AppWin* m_app {};

public:
	CAppWin(LPVOID onwer=NULL);
	virtual	LRESULT msgPrc(const WinClzz::TWIN_MSG&) override;
};

CAppWin::CAppWin(LPVOID onwer)
{
	m_app = (AppWin*)onwer;
}

LRESULT CAppWin::msgPrc(const WinClzz::TWIN_MSG& msg)
{
	if(m_app)
		return m_app->msgPrc(msg);
	return IWinBase::msgPrc(msg);
}


AppWin::AppWin()
{
}

INT AppWin::create(const WinClzz::TWIN_PARAM& param)
{
	INT hr =0;
	m_app_win = new CAppWin(this);

	hr = m_app_win->create(param);
	if(FAILED(hr))
		goto END;

	if(FAILED(Init()))
		goto END;

	return 0;
END:
	SAFE_DELETE(m_app_win);
	return -1;
}

void AppWin::Cleanup()
{
	SAFE_DELETE( m_app_win );
}

LRESULT AppWin::msgPrc(const WinClzz::TWIN_MSG& msg)
{
	switch( msg.message )
	{
		case WM_KEYDOWN:
		{
			switch(msg.wParam)
			{
				case VK_ESCAPE:
				{
					SendMessage(msg.hwnd, WM_DESTROY, 0,0);
					break;
				}
			}

			break;

		}
		case WM_DESTROY:
		{
			Cleanup();
			DestroyWindow(msg.hwnd);
			break;
		}
	}
	return ::DefWindowProc(msg.hwnd, msg.message, msg.wParam, msg.lParam);
}


INT AppWin::Render3D()
{
	return 0;
}

