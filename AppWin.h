// Interface for the AppWin class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _AppWin_H_
#define _AppWin_H_

class AppWin
{
protected:
	WinClzz::IWinBase*	m_app_win {};

public:
	AppWin();

	INT		create(const WinClzz::TWIN_PARAM& param);
	void	Cleanup();
	INT		Render3D();

	virtual INT		Init()	{ return 0;	}
	virtual	LRESULT msgPrc(const WinClzz::TWIN_MSG&);
};

#endif