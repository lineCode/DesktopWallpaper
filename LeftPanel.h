// LeftPanel.h: interface for the LeftPanel class.
//
//////////////////////////////////////////////////////////////////////

#ifndef LEFTPANEL_H
#define LEFTPANEL_H

#include "CustomControl.h"
#include "Button.h"
#include "List.h"

#include <commdlg.h>
#include <shlwapi.h>
#include <shlobj.h>

class LeftPanel : public CustomControl  
{
protected:
	Button button;
	List list;
	HFONT font;

protected:
	LRESULT ObjectProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
	LPTSTR Directory(HWND hOwner);

public:
	LeftPanel();
	virtual ~LeftPanel();

	BOOL SetFolderPath(const char* path);

};

#endif
