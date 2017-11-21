
#ifdef _MSC_VER
#pragma once
#endif

#ifndef _ClzzWin_H_
#define _ClzzWin_H_

#define SAFE_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }
#define SAFE_DELETE_ARRAY(p) { if(p) { delete[] (p);   (p)=NULL; } }
#define SAFE_RELEASE(p)      { if(p) { (p)->Release(); (p)=NULL; } }

#include <string>
#include <tuple>
#include <map>

#include <windows.h>
#include <CommCtrl.h>

namespace WinClzz {

struct RECT_L
{
	int x, y, w, h;
};

enum
{
	L_FAIL		= -1,
	L_OK		= 0,
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

::HIMAGELIST createImageList(UINT uId, int cx);

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

struct TWIN_PARAM
{
    LPCSTR    className;
    RECT_L    rc;
	DWORD     dStyle  ={};
    DWORD     exStyle ={};
	HWND      parent  ={};
    HMENU     menu    ={};
    void*     param   ={};
	TWIN_PARAM(LPCSTR clzz, const RECT_L& _rc
				, DWORD style=0, DWORD estyle=0,HWND prn=NULL, HMENU m=NULL, void* p=NULL) 
				: className(clzz), rc(_rc), parent(prn), menu(m), param(p){}
};

struct TWIN_MSG
{
    HWND        hwnd;
    UINT        message;
    WPARAM      wParam;
    LPARAM      lParam;
};

class IWinBase
{
protected:
	HWND			m_hWnd{};		// this
	HWND			m_hPrn{};		// parent
	std::string		m_clzz;			// clazz
	std::string		m_name;			// name
public:
	IWinBase();
	virtual ~IWinBase();

	HWND hwnd()  const { return m_hWnd; }
	HWND parent() const { return m_hPrn; }
	void parent(HWND p) { m_hPrn = p;    }

	virtual INT		create(const TWIN_PARAM&);
	virtual LRESULT msgPrc(const TWIN_MSG&);
	static INT Run();
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class WinControlList : public IWinBase
{
protected:
	int m_asc;

public:
	static WinControlList* create(const char* name, const RECT_L& rc, HWND parent=NULL);
	WinControlList();
	virtual ~WinControlList();
	virtual LRESULT msgPrc(HWND, UINT, WPARAM, LPARAM);

	int   imageList(void* handle, int image_list);
	int   insertColumn(int index, const char* name, int width=150);
	int   insertItem(int index, void* param, const char* name, int image);
	int   itemText(int index, int column, const char* name);
	void* item(int index);								// get item pointer
	std::string itemText(int index, int column=0);		// get item text
protected:
	int  Init(const char*name, const RECT_L& rc, HWND parent=NULL);
	void Destroy();
};


} // namespace WinClzz

#endif
