//Copyright (c) 2019 KEYENCE CORPORATION. All rights reserved.
#pragma once
#include "afxcmn.h"
#include "LJX8_IF.h"


// CHighSpeedEthernetInitializeDlg Dialog

class CHighSpeedEthernetInitializeDlg : public CDialog
{
	DECLARE_DYNAMIC(CHighSpeedEthernetInitializeDlg)

public:
	CHighSpeedEthernetInitializeDlg(CWnd* pParent = NULL);   // Standard constructer
	virtual ~CHighSpeedEthernetInitializeDlg();

	BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();

// Dialog data
	enum { IDD = IDD_HIGHSPEEDETHERNETINITIALIZEDLG };

	LJX8IF_ETHERNET_CONFIG ethernetConfig;
	LJX8IF_ETHERNET_CONFIG GetEthernetConfig();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV Support

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_dwHighSpeedPortNo;
	DWORD m_dwProfileCount;

private:
	CIPAddressCtrl m_iacIPAddress;
	DWORD m_dwIPAddress;
	DWORD m_dwCommandPort;
};
