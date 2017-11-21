// Interface for the AppMain2 class.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _AppMain2_H_
#define _AppMain2_H_

class AppMain2 : public AppWin
{
public:

public:
	AppMain2();

	virtual INT		Init();
	virtual void	Destroy();

	virtual INT		FrameMove();
	virtual INT		Render();

	virtual LRESULT msgPrc(const WinClzz::TWIN_MSG&) override;
};

#endif