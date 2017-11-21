// Implementation of the AppMain2 class.
//
////////////////////////////////////////////////////////////////////////////////


#include "_StdAfx.h"


AppMain2::AppMain2()
{

}


INT AppMain2::Init()
{
	return 0;
}

void AppMain2::Destroy()
{
}


INT AppMain2::FrameMove()
{
	return 0;
}


INT AppMain2::Render()
{
	return 0;
}

struct st_user {
	std::string name;
	std::string tel ;
	std::string addr;
	BOOL male;
};

std::vector<st_user> user;

WinClzz::WinControlList* wctl_scene = NULL;
LRESULT AppMain2::msgPrc(const WinClzz::TWIN_MSG& msg)
{
	switch( msg.message )
	{
		case WM_CREATE:
		{
			user.push_back({"Jack","+94+333+2222","London, U.K",TRUE});
			user.push_back({"Andrew","+82+555+5555","Paris, France",TRUE});
			user.push_back({"Alex","+47+111+2222","Seoul, Korea",FALSE});
			user.push_back({"John","+33+555+6666","New York, U.S",TRUE});
			user.push_back({"Brian","+24+999+1111","Tokyo, Japan",FALSE});
			user.push_back({"Nero","+67+777+7777","Beijing, China",TRUE});

			HWND hWnd = msg.hwnd;
			if( !(wctl_scene = WinClzz::WinControlList::create( NULL, {10,10,600,200}, hWnd)))
				return 0;

			HIMAGELIST hImgSm = WinClzz::createImageList(IMAGE_16, 16);
			HIMAGELIST hImgLa = WinClzz::createImageList(IMAGE_32, 32);
			wctl_scene->imageList(hImgSm, LVSIL_SMALL);
			wctl_scene->imageList(hImgLa, LVSIL_NORMAL);

			wctl_scene->insertColumn(0, "name", 150);
			wctl_scene->insertColumn(1, "phone", 150);
			wctl_scene->insertColumn(2, "address", 300);

			for(int i=0; i<(int)user.size(); ++i)
			{
				st_user* p = &user[i];
				char name[256]={0};	strcpy(name, p->name.c_str());
				char tel [256]={0};	strcpy(tel , p->tel .c_str());
				char addr[256]={0};	strcpy(addr, p->addr.c_str());

				wctl_scene->insertItem(i, p, name, p->male ? 0:1);
				wctl_scene->itemText(i,1, tel );
				wctl_scene->itemText(i,2, addr);
			}
			return 0;
		}
		case WM_NOTIFY:
		{
			LRESULT ret = wctl_scene->msgPrc(msg.hwnd,msg.message,msg.wParam,msg.lParam);
			if(FALSE == ret)
				return FALSE;
			break;
		}
		case WM_DESTROY:
		{
			user.clear();
			SAFE_DELETE(wctl_scene);
			break;
		}
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