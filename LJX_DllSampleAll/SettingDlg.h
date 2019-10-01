//Copyright (c) 2019 KEYENCE CORPORATION. All rights reserved.
#pragma once
#include "LJX8_IF.h"
#include<vector>

// CSettingDlg Dialog

using namespace std;

class CSettingDlg : public CDialog
{
	DECLARE_DYNAMIC(CSettingDlg)

public:
	CSettingDlg(BOOL isDisplay, CWnd* pParent = NULL);   // Standard constructer
	virtual ~CSettingDlg();

	BYTE GetDepth();
	LJX8IF_TARGET_SETTING GetTargetSetting();
	vector<BYTE> GetSendData();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);

// Dialog data
	enum { IDD = IDD_SETTINGDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV Support

	DECLARE_MESSAGE_MAP()

public:
	int m_nDataAmount;

private:
	BOOL m_bIsDisplay;
	CString m_strDepth;
	CString m_strType;
	CString m_strCategory;
	CString m_strItem;
	CString m_strTarget1;
	CString m_strTarget2;
	CString m_strTarget3;
	CString m_strTarget4;
	CString m_strParameters;
	vector<BYTE> m_vecSendData;

	static const int BASE_NUMBER = 16;
};
