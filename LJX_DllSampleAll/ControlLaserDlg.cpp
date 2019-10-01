//Copyright (c) 2019 KEYENCE CORPORATION. All rights reserved.
// ClearErrorDlg.cpp :Implementation file
//

#include "stdafx.h"
#include "LJX_DllSampleAll.h"
#include "ControlLaserDlg.h"
#include "afxdialogex.h"


// CControlLaserDlg Dialog

IMPLEMENT_DYNAMIC(CControlLaserDlg, CDialog)

CControlLaserDlg::CControlLaserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_CONTROLLASERDLG, pParent)
	, m_strLaserStatus(_T("00"))
{

}

CControlLaserDlg::~CControlLaserDlg()
{
}

void CControlLaserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_LASERSTATE, m_strLaserStatus);
	DDV_MaxChars(pDX, m_strLaserStatus, 2);
}


BEGIN_MESSAGE_MAP(CControlLaserDlg, CDialog)
END_MESSAGE_MAP()


// CControlLaserDlg Message handler
/*
Get Laser status
@return Laser status
*/
BYTE CControlLaserDlg::GetLaserStatus()
{
	TCHAR* pszEnd = NULL;
	BYTE nLaserStatus = (BYTE)(::_tcstol(m_strLaserStatus, &pszEnd, BASE_NUMBER));

	if (errno == ERANGE) {
		return -1;			// Overflow, Underflow
	}

	return nLaserStatus;
}

