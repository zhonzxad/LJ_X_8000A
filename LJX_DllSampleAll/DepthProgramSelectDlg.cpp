//Copyright (c) 2019 KEYENCE CORPORATION. All rights reserved.
// DepthProgramSelectDlg.cpp :Implementation file
//

#include "stdafx.h"
#include "LJX_DllSampleAll.h"
#include "DepthProgramSelectDlg.h"


// CDepthProgramSelectDlg Dialog

IMPLEMENT_DYNAMIC(CDepthProgramSelectDlg, CDialog)

CDepthProgramSelectDlg::CDepthProgramSelectDlg(BOOL isDisplayDepth, BOOL isDisplayProgram, CWnd* pParent /*=NULL*/)
	: CDialog(CDepthProgramSelectDlg::IDD, pParent)
	, m_bIsDepthVisible(isDisplayDepth)
	, m_bIsTargetVisible(isDisplayProgram)
	, m_strDepth(_T("00"))
	, m_strTarget(_T("00"))
{

}

CDepthProgramSelectDlg::~CDepthProgramSelectDlg()
{
}

void CDepthProgramSelectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_DEPTH, m_strDepth);
	DDX_Text(pDX, IDC_EDIT_TARGET, m_strTarget);
	DDV_MaxChars(pDX, m_strDepth, 2);
	DDV_MaxChars(pDX, m_strTarget, 2);
}


BEGIN_MESSAGE_MAP(CDepthProgramSelectDlg, CDialog)
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// CDepthProgramSelectDlg Message handler
/*
 Displya only the necessary parameter
 @param Display flag
 @param Status
*/
void CDepthProgramSelectDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialog::OnShowWindow(bShow, nStatus);

	
	if(!m_bIsDepthVisible)
	{
		GetDlgItem(IDC_STATIC_HEX2)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_TARGET)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_PROGRAMNOTE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_SPECIFYNOTE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_SPECIFYNOTE2)->ShowWindow(SW_HIDE);
	}

	if(!m_bIsTargetVisible)
	{
		GetDlgItem(IDC_STATIC_HEX1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_LEVEL)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_DEPTH)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_LEVELNOTE)->ShowWindow(SW_HIDE);
	}

	CWnd* pWndDepth = GetDlgItem(IDC_EDIT_DEPTH);
	CWnd* pWndTarget = GetDlgItem(IDC_EDIT_TARGET);
	CEdit *editDepth = static_cast<CEdit*>(pWndDepth);
	CEdit *editTarget = static_cast<CEdit*>(pWndTarget);
	editDepth->SetLimitText(2);
	editTarget->SetLimitText(2);
}

/*
 Get Depth
 @return Depth
*/
BYTE CDepthProgramSelectDlg::GetDepth()
{
	TCHAR* pszEnd =NULL;
	BYTE byReceiveData = (BYTE)(::_tcstol(m_strDepth, &pszEnd, BASE_NUMBER));

	if (errno == ERANGE) { 
		return -1;			// Overflow, Underflow
	} 

	return byReceiveData;
}

/*
 Get Target
 @return Target
*/
BYTE CDepthProgramSelectDlg::GetTarget()
{
	TCHAR* pszEnd = NULL;
	BYTE byReceiveData = (BYTE)(::_tcstol(m_strTarget, &pszEnd, BASE_NUMBER));

	if (errno == ERANGE) { 
		return -1;			// Overflow, Underflow
	} 

	return byReceiveData;
}
