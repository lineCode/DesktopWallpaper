// Control.cpp: implementation of the Control class.
//
//////////////////////////////////////////////////////////////////////

#include "Control.h"
#include <string.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Control::Control()
{
	this->hWnd = NULL;
	this->hParent = NULL;
	this->dwId = 0;
	this->lpTag = NULL;

	this->strControlClass = "Control";
	strcpy(this->strTitle, "Title");
	this->dwStyle = NULL;
	this->dwExStyle = NULL;
}

Control::~Control()
{
}

VOID Control::Resize(DWORD dwX, DWORD dwY, DWORD dwWidth, DWORD dwHeight)
{
	::MoveWindow(this->hWnd, dwX, dwY, dwWidth, dwHeight, TRUE);
}

VOID Control::Kill()
{
	::DestroyWindow(this->hWnd);
}

VOID Control::Show()
{
	::ShowWindow(this->hWnd, SW_SHOW);
}

VOID Control::Hide()
{
	::ShowWindow(this->hWnd, SW_HIDE);
}

VOID Control::Enable()
{
	::EnableWindow(this->hWnd, TRUE);
}

VOID Control::Disable()
{
	::EnableWindow(this->hWnd, FALSE);
}

VOID Control::SetTag(LPVOID tag)
{
	this->lpTag = tag;
}

LPVOID Control::GetTag()
{
	return this->lpTag;
}

VOID Control::SetTitle(LPTSTR title)
{
	strcpy(this->strTitle, title);

	::SetWindowText(this->hWnd, this->strTitle);
}

LPTSTR Control::GetTitle()
{
	::GetWindowText(this->hWnd, this->strTitle, MAX_TITLE);

	return this->strTitle;
}

VOID Control::SetFont(HFONT font)
{
	::SendMessage(this->hWnd, WM_SETFONT, (WPARAM)font, MAKELPARAM(TRUE, 0));
}

HFONT Control::GetFont()
{
	return (HFONT)SendMessage(this->hWnd, WM_GETFONT, 0, 0);
}