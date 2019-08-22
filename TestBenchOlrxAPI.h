
/* Unittest.h : main header file for the Unittest application
   Copyright (c) 1987-2019 Advanced Systems for Power Engineering, Inc. (ASPEN).
   All rights reserved. 
*/
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CUnittestApp:
// See Unittest.cpp for the implementation of this class
//

class CUnittestApp : public CWinApp
{
public:
	CUnittestApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CUnittestApp theApp;
