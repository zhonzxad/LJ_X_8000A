//Copyright (c) 2019 KEYENCE CORPORATION. All rights reserved.
// GetErrorDlg.cpp :Implementation file
//

#include "stdafx.h"
#include "LJX_DllSampleAll.h"
#include "GetErrorDlg.h"


// CGetErrorDlg Dialog

IMPLEMENT_DYNAMIC(CGetErrorDlg, CDialog)

CGetErrorDlg::CGetErrorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGetErrorDlg::IDD, pParent)
	, m_byReceiveMax(10)
{

}

CGetErrorDlg::~CGetErrorDlg()
{
}

BOOL CGetErrorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	CWnd* pWndErrorCount = GetDlgItem(IDC_EDIT_ERRCNT);
	CEdit *editErrorCount = static_cast<CEdit*>(pWndErrorCount);
	editErrorCount->SetLimitText(3);

	return TRUE;
}

void CGetErrorDlg::DoDataExchange(CDataExchange* pDX)
{
	UINT wReceiveMax = m_byReceiveMax;
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ERRCNT, wReceiveMax);
	DDV_MinMaxUInt(pDX, wReceiveMax, 0, 255);
	m_byReceiveMax = wReceiveMax;
}


BEGIN_MESSAGE_MAP(CGetErrorDlg, CDialog)
END_MESSAGE_MAP()


// CGetErrorDlg Message handler
