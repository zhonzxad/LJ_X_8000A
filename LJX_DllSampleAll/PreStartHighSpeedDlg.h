//Copyright (c) 2019 KEYENCE CORPORATION. All rights reserved.
#pragma once
#include "LJX8_IF.h"

// CPreStartHighSpeedDlg Dialog

class CPreStartHighSpeedDlg : public CDialog
{
	DECLARE_DYNAMIC(CPreStartHighSpeedDlg)

public:
	CPreStartHighSpeedDlg(CWnd* pParent = NULL);   // Standard constructer
	virtual ~CPreStartHighSpeedDlg();

	BOOL OnInitDialog();
	LJX8IF_HIGH_SPEED_PRE_START_REQ getHighSpeedPreStartReq();

// Dialog data
	enum { IDD = IDD_PRESTARTHIGHSPEEDDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV Support

	DECLARE_MESSAGE_MAP()

private:
	BYTE m_bySendPos;

public:
	BYTE SendPosNum;
};
