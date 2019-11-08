//Copyright (c) 2019 KEYENCE CORPORATION. All rights reserved.
#pragma once
#include "afxcmn.h"
#include "LJX8_IF.h"

// COpenEthernetDlg Dialog

class COpenEthernetDlg : public CDialog
{
	DECLARE_DYNAMIC(COpenEthernetDlg)

public:
	COpenEthernetDlg(CWnd* pParent = NULL);   // Standard constructer
	virtual ~COpenEthernetDlg();

// Dialog data
	enum { IDD = IDD_OPENETHERNETDLG };

	LJX8IF_ETHERNET_CONFIG GetEthernetConfig();
	BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV Support

	DECLARE_MESSAGE_MAP()

private:
	CIPAddressCtrl m_iacIPAddress;
	DWORD m_dwIPAddress;
	int m_nPortNum;

public:
	//ÆÁ±Îµ¯´°²Ù×÷
	CString strIP = _T("192.168.1.0");

	int PortNum = 24691;
};
