// start...
//
////////////////////////////////////////////////////////////////////////////////

#pragma comment(lib, "winmm.lib")

#include "_StdAfx.h"


INT WINAPI WinMain( HINSTANCE, HINSTANCE, LPSTR, INT )
{
	InitCommonControls();

	AppMain	app;
	const char* name="my game";
	if(FAILED(app.create({name, {100, 100, 800, 600},})))
		return -1;


	AppMain2	app2;
	const char* name2="my game2";
	app2.create({name2, {200, 200, 1024, 768},});


	return WinClzz::IWinBase::Run();
}