//Copyright (c) 2019 KEYENCE CORPORATION. All rights reserved.
// GetProfileDlg.cpp :Implementation file
//

#include "stdafx.h"
#include "LJX_DllSampleAll.h"
#include "GetProfileDlg.h"


// CGetProfileDlg Dialog

IMPLEMENT_DYNAMIC(CGetProfileDlg, CDialog)

CGetProfileDlg::CGetProfileDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGetProfileDlg::IDD, pParent)
	, m_strTargetBank(_T("00"))
	, m_strPosMode(_T("00"))
	, m_dwProfileNo(0)
	, m_byProfileCount(1)
	, m_byEraseFlg(0)
{

}

CGetProfileDlg::~CGetProfileDlg()
{
}

void CGetProfileDlg::DoDataExchange(CDataExchange* pDX)
{
	QWORD qwProfileNo = (QWORD)m_dwProfileNo;
	DWORD dwProfileCount = (DWORD)m_byProfileCount;

	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TARGETBANK, m_strTargetBank);
	DDX_Text(pDX, IDC_EDIT_POSMODE, m_strPosMode);
	DDX_Text(pDX, IDC_EDIT_PROFILENO, qwProfileNo);
	DDX_Text(pDX, IDC_EDIT_PROFILECNT, dwProfileCount);
	DDX_Text(pDX, IDC_EDIT_ERASEFLG, m_byEraseFlg);
	DDV_MaxChars(pDX, m_strTargetBank, 2);
	DDV_MaxChars(pDX, m_strPosMode, 2);
	DDV_MinMaxULongLong(pDX, qwProfileNo, 0, 4294967295);
	DDV_MinMaxUInt(pDX, dwProfileCount, 1, 255);
	DDV_MinMaxByte(pDX, m_byEraseFlg, 0, 1);

	m_dwProfileNo = (DWORD)qwProfileNo;
	m_byProfileCount = (BYTE)dwProfileCount;
}


BEGIN_MESSAGE_MAP(CGetProfileDlg, CDialog)
END_MESSAGE_MAP()


BOOL CGetProfileDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	CWnd* pWndTargetBank = GetDlgItem(IDC_EDIT_TARGETBANK);
	CWnd* pWndPosMode = GetDlgItem(IDC_EDIT_POSMODE);
	CWnd* pWndProfileNo = GetDlgItem(IDC_EDIT_PROFILENO);
	CWnd* pWndProfileCount = GetDlgItem(IDC_EDIT_PROFILECNT);
	CWnd* pWndEraseFlag = GetDlgItem(IDC_EDIT_ERASEFLG);
	CEdit *editTargetBank = static_cast<CEdit*>(pWndTargetBank);
	CEdit *editPosMode = static_cast<CEdit*>(pWndPosMode);
	CEdit *editProfileNo = static_cast<CEdit*>(pWndProfileNo);
	CEdit *editProfileCount = static_cast<CEdit*>(pWndProfileCount);
	CEdit *editEraseFlag = static_cast<CEdit*>(pWndEraseFlag);
	editTargetBank->SetLimitText(2);
	editPosMode->SetLimitText(2);
	editProfileNo->SetLimitText(10);
	editProfileCount->SetLimitText(3);
	editEraseFlag->SetLimitText(1);

	return TRUE;
}

// CGetProfileDlg Message handler
/*
 Get profile request
 @return LJX8IF_GET_PROFILE_REQUEST
*/
LJX8IF_GET_PROFILE_REQUEST CGetProfileDlg::GetProfileReq(void)
{
	TCHAR* pszEnd = NULL;
	LJX8IF_GET_PROFILE_REQUEST req;

	req.byTargetBank = (BYTE)(::_tcstol(m_strTargetBank, &pszEnd, BASE_NUMBER));
	req.byPositionMode = (BYTE)(::_tcstol(m_strPosMode, &pszEnd, BASE_NUMBER));
	req.dwGetProfileNo  = m_dwProfileNo;
	req.byGetProfileCount = m_byProfileCount;
	req.byErase      = m_byEraseFlg;
	req.reserve[0]   = 0;
	req.reserve[1]   = 0;
	req.reserve2[0]  = 0;
	req.reserve2[1]  = 0;

	return req;
}
