// Main.h: interface for the Main class.
//
//////////////////////////////////////////////////////////////////////

#ifndef MAIN_H
#define MAIN_H

#include "BasisScherm.h"
#include "SystrayIcon.h"
#include "resource.h"
#include "LeftPanel.h"

#define ID_SYSTRAY_EXIT 345
#define ID_CHANGEWALLPAPER 546

class Main : public BasisScherm  
{
private:
	SystrayIcon systrayicon;
	HMENU m_hSystrayMenu;
	LeftPanel leftpanel;

	LRESULT SchermProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
	Main();
	virtual ~Main();

};

#endif
