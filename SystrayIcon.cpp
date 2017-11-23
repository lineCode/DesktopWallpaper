// SystrayIcon.cpp: implementation of the SystrayIcon class.
//
//////////////////////////////////////////////////////////////////////

#include "SystrayIcon.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SystrayIcon::SystrayIcon()
{
	this->m_hWnd			 = NULL;
	this->m_hIcon			 = NULL;
	this->m_strTitle		 = "";
	this->m_bSetup			 = FALSE;
}

SystrayIcon::~SystrayIcon()
{
}

bool SystrayIcon::Setup()
{
	this->m_NotifyData.cbSize				 = sizeof(NOTIFYICONDATA);
	this->m_NotifyData.hIcon				 = this->m_hIcon;
	this->m_NotifyData.hWnd					 = this->m_hWnd;
	this->m_NotifyData.uID					 = this->m_dwID;
	this->m_NotifyData.uCallbackMessage		 = WM_SHELLNOTIFY;
	this->m_NotifyData.uFlags				 = NIF_ICON | NIF_MESSAGE | NIF_TIP;

	strcpy(this->m_NotifyData.szTip, this->m_strTitle);

	this->m_bSetup = Shell_NotifyIcon(NIM_ADD, &m_NotifyData);
	
	return this->m_bSetup == TRUE;
}

bool SystrayIcon::Init(HWND hWnd, DWORD id)
{
	this->m_hWnd							 = hWnd;
	this->m_dwID							 = id;

	if (this->m_bSetup)
		Kill();

	Setup();

	return TRUE;
}

bool SystrayIcon::Kill()
{
	Shell_NotifyIcon(NIM_DELETE, &m_NotifyData);
	
	return true;
}

bool SystrayIcon::SetIcon(HICON icon)
{
	this->m_hIcon = icon;
	
	if (this->m_bSetup)
	{
		Kill();
		Setup();
	}

	return true;
}

bool SystrayIcon::SetTitle(const char* title)
{
	this->m_strTitle = const_cast <char*> (title);
	
	if (this->m_bSetup)
	{
		Kill();
		Setup();
	}

	return true;
}