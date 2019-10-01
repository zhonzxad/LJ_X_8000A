//Copyright (c) 2019 KEYENCE CORPORATION. All rights reserved.
//

#include "stdafx.h"
#include "LJX_DllSampleAll.h"
#include "LJX_DllSampleAllDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLJX_DllSampleAllApp

BEGIN_MESSAGE_MAP(CLJX_DllSampleAllApp, CWinAppEx)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()



CLJX_DllSampleAllApp::CLJX_DllSampleAllApp()
{

}

CLJX_DllSampleAllApp theApp;


BOOL CLJX_DllSampleAllApp::InitInstance()
{
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);

	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	AfxEnableControlContainer();

	SetRegistryKey(_T("The local application that was generated in application Wizard"));

	CLJX_DllSampleAllDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{

	}
	else if (nResponse == IDCANCEL)
	{
	}

	return FALSE;
}
