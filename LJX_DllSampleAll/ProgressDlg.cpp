//Copyright (c) 2019 KEYENCE CORPORATION. All rights reserved.
// CProgressDlg.cpp :Implementation file
//

#include "stdafx.h"
#include "LJX_DllSampleAll.h"
#include "ProgressDlg.h"
#include "afxdialogex.h"


// CProgressDlg Dialog

IMPLEMENT_DYNAMIC(CProgressDlg, CDialog)

CProgressDlg::CProgressDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_PROGRESS_DLG, pParent)
{

}

CProgressDlg::~CProgressDlg()
{
}

void CProgressDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CProgressDlg, CDialog)
END_MESSAGE_MAP()


// CControlLaserDlg Message handler

BOOL CProgressDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	CMenu* pMenu = GetSystemMenu(FALSE);
	pMenu->EnableMenuItem(SC_CLOSE, MF_GRAYED);

	return TRUE;
}

void CProgressDlg::SetStatus(PROFILE_PROCESSING_STATUS status)
{
	m_status = status;
	GetDlgItem(IDC_STATIC)->SetWindowTextW(GetStatusText(status));
}

LPCTSTR CProgressDlg::GetStatusText(PROFILE_PROCESSING_STATUS status)
{
	switch (status)
	{
		case PROFILE_PROCESSING_STATUS_COMMUNICATING:
			return _T("Communicating");
		case PROFILE_PROCESSING_STATUS_SAVING:
			return _T("Saving the file");
	}
	return _T("");
}
