// CustomControl.h: interface for the CustomControl class.
//
//////////////////////////////////////////////////////////////////////

#ifndef CUSTOMCONTROL_H
#define CUSTOMCONTROL_H

#include "Control.h"

class CustomControl : public Control
{
protected:
	HBRUSH hBackgroundColor;
	HCURSOR hCursor;
	HICON hIcon;
	HICON hSmallIcon;

protected:
	CustomControl();
	virtual ~CustomControl();
	
	virtual BOOL InitCustomControl();
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual LRESULT ObjectProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
	BOOL Create(HWND hParent, DWORD dwId);

};

#endif
