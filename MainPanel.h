// MainPanel.h: interface for the MainPanel class.
//
//////////////////////////////////////////////////////////////////////

#ifndef MAINPANEL_H
#define MAINPANEL_H

#include "CustomControl.h"

class MainPanel : public CustomControl  
{
protected:
	LRESULT ObjectProc(UINT uMsg, WPARAM wParam, LPARAM lParam);


public:
	MainPanel();
	virtual ~MainPanel();

};

#endif
