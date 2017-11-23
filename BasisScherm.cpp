// BasisScherm.cpp: implementation of the BasisScherm class.
//
//////////////////////////////////////////////////////////////////////

#include "BasisScherm.h"

//////////////////////////////////////////////////////////////////////
// Statics
//////////////////////////////////////////////////////////////////////

LRESULT BasisScherm::StaticProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	BasisScherm* scherm = NULL;

	if (uMsg == WM_NCCREATE)
	{
		scherm = reinterpret_cast <BasisScherm*> (((LPCREATESTRUCT)lParam)->lpCreateParams);
		
		::SetWindowLong(hWnd, GWL_USERDATA, reinterpret_cast <long> (scherm));

		if (scherm != NULL)
		{
			scherm->m_hWnd = hWnd;
		}
	}
	else
	{
		scherm = reinterpret_cast <BasisScherm*> (::GetWindowLong(hWnd, GWL_USERDATA));
	}

	if (scherm != NULL)
	{
		return scherm->SchermProc(uMsg, wParam, lParam);
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BasisScherm::BasisScherm()
{
	this->m_hInstance			 = NULL;
	this->m_hWnd				 = NULL;
	this->m_hMenu				 = NULL;
	this->m_hIcon				 = NULL;
	this->m_hCursor				 = LoadCursor(NULL, IDC_ARROW);
	this->m_hAccelTable			 = NULL;
	this->m_hbrWindowColor		 = (HBRUSH)COLOR_WINDOW + 0;

	this->m_dwCreationX			 = CW_USEDEFAULT;
	this->m_dwCreationY			 = CW_USEDEFAULT;
	this->m_dwCreationHeight	 = CW_USEDEFAULT;
	this->m_dwCreationWidth		 = CW_USEDEFAULT;
 	this->m_dwCreationFlags		 = SW_SHOW;
	this->m_dwWindowStyle		 = WS_OVERLAPPEDWINDOW;
	this->m_dwExWindowStyle		 = WS_EX_WINDOWEDGE;
	this->m_strWindowTitle		 = "Hoofd BasisScherm";
	this->m_strWindowClass		 = "BasisScherm";
}

BasisScherm::~BasisScherm()
{
	ClearWindowClass();
}

LRESULT BasisScherm::Create(HINSTANCE hInstance)
{
	this->m_hInstance = hInstance;

	if (InitWindowClass() == TRUE)
	{
		this->m_hWnd = ::CreateWindowEx(	this->m_dwExWindowStyle,
											this->m_strWindowClass,
											this->m_strWindowTitle, 
											this->m_dwWindowStyle,
											this->m_dwCreationX,
											this->m_dwCreationY,
											this->m_dwCreationWidth,
											this->m_dwCreationHeight, 
											NULL,
											this->m_hMenu,
											this->m_hInstance,
											(VOID*)this);

		if (this->m_hWnd != NULL)
		{
			::ShowWindow(this->m_hWnd, this->m_dwCreationFlags);

			::UpdateWindow(this->m_hWnd);

			return TRUE;
		}
	}
	return FALSE;
}

LRESULT BasisScherm::RunToClose()
{
	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		if (!TranslateAccelerator(msg.hwnd, this->m_hAccelTable, &msg)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	
	return msg.wParam;
}

LRESULT BasisScherm::InitWindowClass()
{
	WNDCLASSEX wcex;

	if (::GetClassInfoEx(this->m_hInstance, this->m_strWindowClass, &wcex) == NULL)
	{
		wcex.cbSize			= sizeof(WNDCLASSEX); 
		wcex.style			= CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc	= (WNDPROC) BasisScherm::StaticProc;
		wcex.cbClsExtra		= 0;
		wcex.cbWndExtra		= 0;
		wcex.lpszMenuName	= NULL;
		wcex.hIconSm		= NULL;

		wcex.hInstance		= this->m_hInstance;
		wcex.hIcon			= this->m_hIcon;
		wcex.hbrBackground	= this->m_hbrWindowColor;
		wcex.lpszClassName	= this->m_strWindowClass;
		wcex.hCursor		= this->m_hCursor;

		if (::RegisterClassEx(&wcex) == NULL)
		{
			return FALSE;
		}
	}

	return TRUE;
}

LRESULT BasisScherm::ClearWindowClass()
{
	if (::UnregisterClass(this->m_strWindowClass, this->m_hInstance) == NULL)
	{
		return FALSE;
	}
	return TRUE;
}

LRESULT BasisScherm::SchermProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		{
			if (::MessageBox(this->m_hWnd, "Weet je zeker dat je wil sluiten?", this->m_strWindowTitle, MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
			{
				PostQuitMessage(0);
			}
			else
			{
				return FALSE;
			}
			break;
		}
	}
	return DefWindowProc(this->m_hWnd, uMsg, wParam, lParam);
}
