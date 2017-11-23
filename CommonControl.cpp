// CommonControl.cpp: implementation of the CommonControl class.
//
//////////////////////////////////////////////////////////////////////

#include "CommonControl.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CommonControl::CommonControl()
{
}

CommonControl::~CommonControl()
{
}

BOOL CommonControl::Create(HWND hParent, DWORD dwId)
{
	this->hParent = hParent;
	this->dwId = dwId;
	
	this->hWnd = ::CreateWindowEx(	this->dwExStyle,
									this->strControlClass, 
									this->strTitle,
									this->dwStyle,
									CW_USEDEFAULT,
									CW_USEDEFAULT,
									CW_USEDEFAULT,
									CW_USEDEFAULT,
									this->hParent,
							(HMENU)	this->dwId,
									GetModuleHandle(NULL),
									this);

	if (this->hWnd)
	{
		::ShowWindow(this->hWnd, SW_SHOW);
		::UpdateWindow(this->hWnd);
		return TRUE;
	}
	
	return FALSE;
}