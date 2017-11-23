// Main.cpp: implementation of the Main class.
//
//////////////////////////////////////////////////////////////////////

#include "Main.h"

//////////////////////////////////////////////////////////////////////
// WinMain
//////////////////////////////////////////////////////////////////////

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Main main;

	if (main.Create(hInstance) == TRUE)
	{
		return main.RunToClose();
	}

	return FALSE;
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Main::Main()
{
	this->m_dwWindowStyle = WS_OVERLAPPED | WS_SYSMENU;
	this->m_hMenu = LoadMenu(this->m_hInstance, MAKEINTRESOURCE(IDR_MENU));
	this->m_hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_SUSHI));
	
	this->m_hSystrayMenu = CreatePopupMenu();
	AppendMenu(this->m_hSystrayMenu, MF_STRING, ID_SYSTRAY_EXIT, "Exit");

	systrayicon.SetTitle("Desktop Wallpaper");
	systrayicon.SetIcon(this->m_hIcon);
}

Main::~Main()
{
}

LRESULT Main::SchermProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		{
			::SetTimer(this->m_hWnd, ID_CHANGEWALLPAPER, 10000, NULL);

			leftpanel.Create(this->m_hWnd, 36543);
			break;
		}
	case WM_SIZE:
		{
			leftpanel.Resize(0, 0, 200, HIWORD(lParam));
			break;
		}

	case WM_CLOSE:
		{
			::ShowWindow(this->m_hWnd, SW_HIDE);
			systrayicon.Init(this->m_hWnd, 546);
			return TRUE;
		}

	case WM_QUIT:
		{
			systrayicon.Kill();
			break;
		}

	case WM_TIMER:
		{
			break;
		}

	case WM_COMMAND:
		{
			switch (wParam)
			{
			case ID_FILE_EXIT:
			case ID_SYSTRAY_EXIT:
				{
					systrayicon.Kill();
					PostQuitMessage(0);
					break;
				}
			}
			break;
		}

	case WM_SHELLNOTIFY:
		{
			switch (lParam)
			{
			case WM_LBUTTONDOWN:
				{
					::ShowWindow(this->m_hWnd, SW_SHOW);
					systrayicon.Kill();
					break;
				}

			case WM_RBUTTONUP:
				{
					POINT pt;
					GetCursorPos(&pt);

					TrackPopupMenuEx(this->m_hSystrayMenu, TPM_HORIZONTAL, pt.x, pt.y, this->m_hWnd, NULL);
					break;
				}
			}
			break;
		}
	}
	return BasisScherm::SchermProc(uMsg, wParam, lParam);
}