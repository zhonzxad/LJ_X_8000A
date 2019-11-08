//Copyright (c) 2019 KEYENCE CORPORATION. All rights reserved.
// HighSpeedEthernetInitializeDlg.cpp :Implementation file
//

#include "stdafx.h"
#include "LJX_DllSampleAll.h"
#include "HighSpeedEthernetInitializeDlg.h"


// CHighSpeedEthernetInitializeDlg Dialog

IMPLEMENT_DYNAMIC(CHighSpeedEthernetInitializeDlg, CDialog)

CHighSpeedEthernetInitializeDlg::CHighSpeedEthernetInitializeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHighSpeedEthernetInitializeDlg::IDD, pParent)
	, m_dwCommandPort(24691)
	, m_dwHighSpeedPortNo(24692)
	, m_dwProfileCount(1)
{

}

CHighSpeedEthernetInitializeDlg::~CHighSpeedEthernetInitializeDlg()
{
}

void CHighSpeedEthernetInitializeDlg::DoDataExchange(CDataExchange* pDX)
{
	QWORD qwProfileCount = (QWORD)m_dwProfileCount;
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IPADDRESS, m_iacIPAddress);
	DDX_Text(pDX, IDC_EDIT_COMMANDPORT, m_dwCommandPort);
	DDX_Text(pDX, IDC_EDIT_HIGHSPEEDPORT, m_dwHighSpeedPortNo);
	DDX_Text(pDX, IDC_EDIT_PROFCNT, qwProfileCount);
	DDV_MinMaxUInt(pDX, m_dwHighSpeedPortNo, 0, 65535);
	DDV_MinMaxUInt(pDX, m_dwCommandPort, 0, 65535);
	DDV_MinMaxULongLong(pDX, qwProfileCount, 0, 4294967295);
	m_dwProfileCount = (DWORD)qwProfileCount;
}


BEGIN_MESSAGE_MAP(CHighSpeedEthernetInitializeDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CHighSpeedEthernetInitializeDlg::OnBnClickedOk)
END_MESSAGE_MAP()

BOOL CHighSpeedEthernetInitializeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	//m_iacIPAddress.SetAddress(ethernetConfig.abyIpAddress[0], ethernetConfig.abyIpAddress[1], ethernetConfig.abyIpAddress[2], ethernetConfig.abyIpAddress[3]);
	
	//m_dwCommandPort = ethernetConfig.wPortNo;

	m_iacIPAddress.SetAddress(192, 168, 0, 1);
	m_dwCommandPort = 24691;

	UpdateData(FALSE);

	CWnd* pWndCommandPort = GetDlgItem(IDC_EDIT_COMMANDPORT);
	CWnd* pWndHighSpeedPort = GetDlgItem(IDC_EDIT_HIGHSPEEDPORT);
	CWnd* pWndProfileCount = GetDlgItem(IDC_EDIT_PROFCNT);
	CEdit *editCommandPort = static_cast<CEdit*>(pWndCommandPort);
	CEdit *editHighSpeedPort = static_cast<CEdit*>(pWndHighSpeedPort);
	CEdit *editProfileCount = static_cast<CEdit*>(pWndProfileCount);
	editCommandPort->SetLimitText(5);
	editHighSpeedPort->SetLimitText(5);
	editProfileCount->SetLimitText(10);

	return TRUE;
}

// CHighSpeedEthernetInitializeDlg Message handler
/*
 Get Ethernet config
 获取当前以太网的配置（主要指的是IP地址和端口号配置）
 @return LJX8IF_ETHERNET_CONFIG
*/
LJX8IF_ETHERNET_CONFIG CHighSpeedEthernetInitializeDlg::GetEthernetConfig()
{
	LJX8IF_ETHERNET_CONFIG ethernetConfig;
	DWORD ipAddress = m_dwIPAddress;

	ethernetConfig.abyIpAddress[0] = (BYTE)((ipAddress & 0xFF000000) >> 24);
	ethernetConfig.abyIpAddress[1] = (BYTE)((ipAddress & 0x00FF0000) >> 16);
	ethernetConfig.abyIpAddress[2] = (BYTE)((ipAddress & 0x0000FF00) >> 8);
	ethernetConfig.abyIpAddress[3] = (BYTE)( ipAddress & 0x000000FF);

	ethernetConfig.wPortNo         = (WORD)m_dwCommandPort;
	ethernetConfig.reserve[0]      = (BYTE)0;
	ethernetConfig.reserve[1]      = (BYTE)0;

	return ethernetConfig;
}

/*
 "OK" button clicked
*/
void CHighSpeedEthernetInitializeDlg::OnBnClickedOk()
{
	m_iacIPAddress.GetAddress(m_dwIPAddress);
	
	OnOK();
}
