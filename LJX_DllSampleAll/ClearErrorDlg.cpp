//Copyright (c) 2019 KEYENCE CORPORATION. All rights reserved.
// ClearErrorDlg.cpp :Implementation file
//

#include "stdafx.h"
#include "LJX_DllSampleAll.h"
#include "ClearErrorDlg.h"


// CClearErrorDlg Dialog

IMPLEMENT_DYNAMIC(CClearErrorDlg, CDialog)

CClearErrorDlg::CClearErrorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClearErrorDlg::IDD, pParent)
	, m_strErrorCode(_T("0085"))
{

}

CClearErrorDlg::~CClearErrorDlg()
{
}

void CClearErrorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ERRORCODE, m_strErrorCode);
	DDV_MaxChars(pDX, m_strErrorCode, 4);
}

BEGIN_MESSAGE_MAP(CClearErrorDlg, CDialog)
END_MESSAGE_MAP()


// CClearErrorDlg Message handler
/*
 ªÒ»°¥ÌŒÛ¬Î
 @return Error code
*/
WORD CClearErrorDlg::GetErrCode()
{
	TCHAR* pszEnd = NULL;
	WORD nErrorCode = (WORD)(::_tcstol(m_strErrorCode, &pszEnd, BASE_NUMBER));

	if (errno == ERANGE) {
		return -1;			// Overflow, Underflow
	}

	return nErrorCode;
}
