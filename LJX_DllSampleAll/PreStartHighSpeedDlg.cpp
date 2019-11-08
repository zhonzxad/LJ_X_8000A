//Copyright (c) 2019 KEYENCE CORPORATION. All rights reserved.
// PreStartHighSpeedDlg.cpp :Implementation file
//

#include "stdafx.h"
#include "LJX_DllSampleAll.h"
#include "PreStartHighSpeedDlg.h"


// CPreStartHighSpeedDlg Dialog

IMPLEMENT_DYNAMIC(CPreStartHighSpeedDlg, CDialog)

CPreStartHighSpeedDlg::CPreStartHighSpeedDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPreStartHighSpeedDlg::IDD, pParent)
	, m_bySendPos(2)
	, SendPosNum(2)
{
}

CPreStartHighSpeedDlg::~CPreStartHighSpeedDlg()
{
}

void CPreStartHighSpeedDlg::DoDataExchange(CDataExchange* pDX)
{
	DWORD dwSendPos = (DWORD)m_bySendPos;

	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, dwSendPos);
	DDV_MinMaxUInt(pDX, dwSendPos, 0, 255);

	m_bySendPos = (BYTE)dwSendPos;
}


BEGIN_MESSAGE_MAP(CPreStartHighSpeedDlg, CDialog)
END_MESSAGE_MAP()


BOOL CPreStartHighSpeedDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	CWnd* pWndSendPos = GetDlgItem(IDC_EDIT1);
	CEdit *editSendPos = static_cast<CEdit*>(pWndSendPos);
	editSendPos->SetLimitText(3);

	return TRUE;
}

// CPreStartHighSpeedDlg Message handler
/*
 Get PreStart HighSpeed Communication Request
 @return LJX8IF_HIGH_SPEED_PRE_START_REQ
 作用仅是获取轮廓的启示位置，直接设置值即可
*/
LJX8IF_HIGH_SPEED_PRE_START_REQ CPreStartHighSpeedDlg::getHighSpeedPreStartReq()
{
	LJX8IF_HIGH_SPEED_PRE_START_REQ req;
	req.bySendPosition = m_bySendPos;

	/*LJX8IF_HIGH_SPEED_PRE_START_REQ req;
	req.bySendPosition = SendPosNum;*/

	return req;
}
