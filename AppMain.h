// Interface for the AppMain class.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _AppMain_H_
#define _AppMain_H_

class AppMain : public AppWin
{
public:

public:
	AppMain();

	virtual INT		Init();
	virtual void	Destroy();

	virtual INT		FrameMove();
	virtual INT		Render();

	virtual LRESULT msgPrc(const WinClzz::TWIN_MSG&) override;
};

#endif