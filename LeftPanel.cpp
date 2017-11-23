// LeftPanel.cpp: implementation of the LeftPanel class.
//
//////////////////////////////////////////////////////////////////////

#include "LeftPanel.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

LeftPanel::LeftPanel()
{
	this->hBackgroundColor = (HBRUSH)COLOR_WINDOW;
	this->hCursor = LoadCursor(NULL, IDC_ARROW);
	this->hIcon = NULL;
	this->hSmallIcon = NULL;

	this->strControlClass = "LeftPanel";
	this->dwStyle = WS_CHILD | WS_VISIBLE;
	this->dwExStyle = WS_EX_WINDOWEDGE;

	this->font = CreateFont(14, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, "Verdana");
}

LeftPanel::~LeftPanel()
{
	::DeleteObject(this->font);
}

LRESULT LeftPanel::ObjectProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		{
			button.Create(this->hWnd, 346);
			button.SetFont(font);
			button.SetTitle("Change Directory");

			list.Create(this->hWnd, 345);
			list.SetFont(font);
			break;
		}
	case WM_SIZE:
		{
			button.Resize( 10, 10, LOWORD(lParam)-20, 20);
			list.Resize(10, 40, LOWORD(lParam)-20, HIWORD(lParam)-50);
			break;
		}

	case WM_COMMAND:
		{
			switch (wParam)
			{
			case 346:
				{
					LPTSTR tmp = Directory(this->hWnd);

					if (tmp)
                    {
						SetFolderPath(tmp);
                        delete []tmp;
                    }
					break;
				}
			}
			break;
		}
	}
	return CustomControl::ObjectProc(uMsg, wParam, lParam);
}

BOOL LeftPanel::SetFolderPath(const char* path)
{
	return DlgDirList(this->hWnd, const_cast<char*>(path), 345, NULL, 0);
}

LPTSTR LeftPanel::Directory(HWND hOwner)
{
	BROWSEINFO bi;
    ITEMIDLIST *pidl;
    CHAR mydir[MAX_PATH];
    CHAR *result;

    bi.hwndOwner = hOwner;
    bi.pidlRoot = 0;
    bi.pszDisplayName = mydir;
    bi.lpszTitle = "Find a directory...";
    bi.ulFlags = BIF_RETURNONLYFSDIRS | BIF_EDITBOX;
    bi.lpfn = 0;
    bi.lParam = 0;

    //Call the directory browse dialog and assign it to a ITEMIDLIST
    pidl=SHBrowseForFolder(&bi);

    //Return the selected path
    if ( SHGetPathFromIDList(pidl, mydir) )
	{
		result = new char[strlen( mydir )+1];
        int i = 0;
        for ( i = 0; i < (int)strlen( mydir ); i++ )
		{
			result[i] = mydir[i];
			if ( mydir[i] == '\\' )
				result[i] = '/';
		}
		result[i]='\0';
		return result;
	}
	
	return NULL;
}
