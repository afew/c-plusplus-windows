// Implementation of the AppMain class.
//
////////////////////////////////////////////////////////////////////////////////


#include "_StdAfx.h"


AppMain::AppMain()
{

}


INT AppMain::Init()
{
	return 0;
}

void AppMain::Destroy()
{
}


INT AppMain::FrameMove()
{
	return 0;
}


INT AppMain::Render()
{
	return 0;
}


LRESULT AppMain::msgPrc(const WinClzz::TWIN_MSG& msg)
{
	switch( msg.message )
	{
		case WM_PAINT:
		{
			char buf[128]={0};
			sprintf(buf, "window handle: %p\n", m_app_win->hwnd());

			PAINTSTRUCT pt;
			HDC hdc = BeginPaint(msg.hwnd, &pt);
			::TextOut(hdc, 10, 10, buf, strlen(buf));
			EndPaint(msg.hwnd, &pt);
			break;
		}
	}

	return AppWin::msgPrc(msg);
}