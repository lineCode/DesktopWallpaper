// Control.h: interface for the Control class.
//
//////////////////////////////////////////////////////////////////////

#ifndef CONTROL_H
#define CONTROL_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define MAX_TITLE 256

class Control  
{
protected:
	HWND hWnd;
	HWND hParent;
	DWORD dwId;
	LPVOID lpTag;

	LPTSTR strControlClass;
	CHAR strTitle[MAX_TITLE];
	DWORD dwStyle;
	DWORD dwExStyle;

protected:
	Control();
	virtual ~Control();

public:
	virtual BOOL Create(HWND hParent, DWORD dwId) = 0;
	virtual VOID Resize(DWORD dwX, DWORD dwY, DWORD dwWidth, DWORD dwHeight);
	virtual VOID Kill();

	virtual VOID Show();
	virtual VOID Hide();

	virtual VOID Enable();
	virtual VOID Disable();

	virtual VOID SetTag(LPVOID tag);
	virtual LPVOID GetTag();

	virtual VOID SetTitle(LPTSTR title);
	virtual LPTSTR GetTitle();

	virtual VOID SetFont(HFONT font);
	virtual HFONT GetFont();
	
};

#endif
