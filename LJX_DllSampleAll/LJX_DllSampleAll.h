//Copyright (c) 2019 KEYENCE CORPORATION. All rights reserved.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "Please include 'stdafx.h', before include this file for PCH"
#endif

#include "resource.h"




class CLJX_DllSampleAllApp : public CWinAppEx
{
public:
	CLJX_DllSampleAllApp();

	public:
	virtual BOOL InitInstance();


	DECLARE_MESSAGE_MAP()
};

extern CLJX_DllSampleAllApp theApp;