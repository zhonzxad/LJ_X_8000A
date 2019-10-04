//Copyright (c) 2019 KEYENCE CORPORATION. All rights reserved.
// OpenEthernetDlg.cpp :Implementation file
//

#include "stdafx.h"
#include "LJX_DllSampleAll.h"
#include "OpenEthernetDlg.h"


// COpenEthernetDlg Dialog

IMPLEMENT_DYNAMIC(COpenEthernetDlg, CDialog)

COpenEthernetDlg::COpenEthernetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COpenEthernetDlg::IDD, pParent)
	, m_nPortNum(24691)
{
}

COpenEthernetDlg::~COpenEthernetDlg()
{
}

void COpenEthernetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IPADDRESS, m_iacIPAddress);
	DDX_Text(pDX, IDC_PORTNUM, m_nPortNum);
	DDV_MinMaxInt(pDX, m_nPortNum, 0, 65535);
}


BEGIN_MESSAGE_MAP(COpenEthernetDlg, CDialog)
	ON_BN_CLICKED(IDOK, &COpenEthernetDlg::OnBnClickedOk)
END_MESSAGE_MAP()

BOOL COpenEthernetDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_iacIPAddress.SetAddress(192, 168, 0, 1);

	CWnd* pWndCommandPort = GetDlgItem(IDC_PORTNUM);
	CEdit *editCommandPort = static_cast<CEdit*>(pWndCommandPort);
	editCommandPort->SetLimitText(5);

	return TRUE;
}

// COpenEthernetDlg Message handler
/*
  Get Ethernet Config
  @return LJX8IF_ETHERNET_CONFIG
  主要指的是IP地址和相应的端口号配置
*/
LJX8IF_ETHERNET_CONFIG COpenEthernetDlg::GetEthernetConfig()
{
	LJX8IF_ETHERNET_CONFIG ethernetConfig;
	DWORD ipAddress = m_dwIPAddress;

	ethernetConfig.abyIpAddress[0] = (BYTE)((ipAddress & 0xFF000000) >> 24);
	ethernetConfig.abyIpAddress[1] = (BYTE)((ipAddress & 0x00FF0000) >> 16);
	ethernetConfig.abyIpAddress[2] = (BYTE)((ipAddress & 0x0000FF00) >> 8);
	ethernetConfig.abyIpAddress[3] = (BYTE)( ipAddress & 0x000000FF);

	ethernetConfig.wPortNo         = (WORD)m_nPortNum;
	ethernetConfig.reserve[0]      = (BYTE)0;
	ethernetConfig.reserve[1]      = (BYTE)0;

	return ethernetConfig;
}

/*
 "OK" button clicked
*/
void COpenEthernetDlg::OnBnClickedOk()
{
	m_iacIPAddress.GetAddress(m_dwIPAddress);

	//当用户点击OK按钮关闭对话框时要执行的动作（事件处理）
	OnOK();
}
