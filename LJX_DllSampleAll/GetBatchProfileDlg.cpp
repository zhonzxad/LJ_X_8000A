//Copyright (c) 2019 KEYENCE CORPORATION. All rights reserved.
// GetBatchProfileDlg.cpp :Implementation file
//

#include "stdafx.h"
#include "LJX_DllSampleAll.h"
#include "GetBatchProfileDlg.h"


// CGetBatchProfileDlg Dialog

IMPLEMENT_DYNAMIC(CGetBatchProfileDlg, CDialog)

CGetBatchProfileDlg::CGetBatchProfileDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGetBatchProfileDlg::IDD, pParent)
	, m_strTargetBank(_T("00"))
	, m_strPosMode(_T("00"))
	, m_dwBatchNo(0)
	, m_dwProfileNo(0)
	, m_byProfileCount(1)
	, m_byEraseFlg(0)
{

}

CGetBatchProfileDlg::~CGetBatchProfileDlg()
{
}

void CGetBatchProfileDlg::DoDataExchange(CDataExchange* pDX)
{
	QWORD qwBatchNo = (QWORD)m_dwBatchNo;
	QWORD qwProfileNo = (QWORD)m_dwProfileNo;
	DWORD dwProfileCount = (DWORD)m_byProfileCount;

	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TARGETBANK, m_strTargetBank);
	DDX_Text(pDX, IDC_EDIT_POSMODE, m_strPosMode);
	DDX_Text(pDX, IDC_EDIT_BATCHNO, qwBatchNo);
	DDX_Text(pDX, IDC_EDIT_PROFILENO, qwProfileNo);
	DDX_Text(pDX, IDC_EDIT_PROFILECNT, dwProfileCount);
	DDX_Text(pDX, IDC_EDIT_ERASEFLG, m_byEraseFlg);
	DDV_MaxChars(pDX, m_strTargetBank, 2);
	DDV_MaxChars(pDX, m_strPosMode, 2);
	DDV_MinMaxULongLong(pDX, qwBatchNo, 0, 4294967295);
	DDV_MinMaxULongLong(pDX, qwProfileNo, 0, 4294967295);
	DDV_MinMaxUInt(pDX, dwProfileCount, 1, 255);
	DDV_MinMaxByte(pDX, m_byEraseFlg, 0, 1);

	m_dwBatchNo = (DWORD)qwBatchNo;
	m_dwProfileNo = (DWORD)qwProfileNo;
	m_byProfileCount = (BYTE)dwProfileCount;
}


BEGIN_MESSAGE_MAP(CGetBatchProfileDlg, CDialog)
END_MESSAGE_MAP()


BOOL CGetBatchProfileDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	CWnd* pWndTargetBank = GetDlgItem(IDC_EDIT_TARGETBANK);
	CWnd* pWndPosMode = GetDlgItem(IDC_EDIT_POSMODE);
	CWnd* pWndBatchNo = GetDlgItem(IDC_EDIT_BATCHNO);
	CWnd* pWndProfileNo = GetDlgItem(IDC_EDIT_PROFILENO);
	CWnd* pWndProfileCount = GetDlgItem(IDC_EDIT_PROFILECNT);
	CWnd* pWndEraseFlag = GetDlgItem(IDC_EDIT_ERASEFLG);
	CEdit *editTargetBank = static_cast<CEdit*>(pWndTargetBank);
	CEdit *editPosMode = static_cast<CEdit*>(pWndPosMode);
	CEdit *editBatchNo = static_cast<CEdit*>(pWndBatchNo);
	CEdit *editProfileNo = static_cast<CEdit*>(pWndProfileNo);
	CEdit *editProfileCount = static_cast<CEdit*>(pWndProfileCount);
	CEdit *editEraseFlag = static_cast<CEdit*>(pWndEraseFlag);
	editTargetBank->SetLimitText(2);
	editPosMode->SetLimitText(2);
	editBatchNo->SetLimitText(10);
	editProfileNo->SetLimitText(10);
	editProfileCount->SetLimitText(3);
	editEraseFlag->SetLimitText(1);

	return TRUE;
}


// CGetBatchProfileDlg Message handler
/*
 Get batch profile request
 @return LJX8IF_GET_BATCH_PROFILE_REQUEST
*/
LJX8IF_GET_BATCH_PROFILE_REQUEST CGetBatchProfileDlg::GetBatchProfileReq(void)
{
	TCHAR* pszEnd = NULL;
	LJX8IF_GET_BATCH_PROFILE_REQUEST req;
	
	req.byTargetBank = (BYTE)(::_tcstol(m_strTargetBank, &pszEnd, BASE_NUMBER));
	req.byPositionMode    = (BYTE)(::_tcstol(m_strPosMode, &pszEnd, BASE_NUMBER));
	req.dwGetBatchNo = m_dwBatchNo;
	req.dwGetProfileNo  = m_dwProfileNo;
	req.byGetProfileCount = m_byProfileCount;
	req.byErase      = m_byEraseFlg;

	return req;
}