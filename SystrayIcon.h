// SystrayIcon.h: interface for the SystrayIcon class.
//
//////////////////////////////////////////////////////////////////////

#ifndef SYSTRAYICON_H
#define SYSTRAYICON_H

#include <windows.h>

#define WM_SHELLNOTIFY WM_USER + 2303

class SystrayIcon  
{
private:
	HWND m_hWnd;
	HICON m_hIcon;
	NOTIFYICONDATA m_NotifyData;
	LPTSTR m_strTitle;
	DWORD m_dwID;
	BOOL m_bSetup;

	bool Setup();

public:
	SystrayIcon();
	virtual ~SystrayIcon();

	bool Init(HWND hWnd, DWORD id);
	bool Kill();

	bool SetIcon(HICON icon);
	bool SetTitle(const char* title);

};

#endif
