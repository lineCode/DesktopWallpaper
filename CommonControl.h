// CommonControl.h: interface for the CommonControl class.
//
//////////////////////////////////////////////////////////////////////

#ifndef COMMONCONTROL_H
#define COMMONCONTROL_H

#include "Control.h"

class CommonControl : public Control
{
protected:
	CommonControl();
	virtual ~CommonControl();

public:
	BOOL Create(HWND hParent, DWORD dwId);

};

#endif
