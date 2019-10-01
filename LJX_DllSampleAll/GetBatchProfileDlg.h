//Copyright (c) 2019 KEYENCE CORPORATION. All rights reserved.
#pragma once
#include<LJX8_IF.h>

// CGetBatchProfileDlg Dialog

class CGetBatchProfileDlg : public CDialog
{
	DECLARE_DYNAMIC(CGetBatchProfileDlg)

public:
	CGetBatchProfileDlg(CWnd* pParent = NULL);   // Standard constructer
	virtual ~CGetBatchProfileDlg();

	BOOL OnInitDialog();
	LJX8IF_GET_BATCH_PROFILE_REQUEST GetBatchProfileReq(void);

// Dialog data
	enum { IDD = IDD_GETBATCHPROFILEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV Support

	DECLARE_MESSAGE_MAP()

public:
	CString m_strTargetBank;
	CString m_strPosMode;
	DWORD m_dwBatchNo;
	DWORD m_dwProfileNo;
	BYTE m_byProfileCount;
	BYTE m_byEraseFlg;
	static const int BASE_NUMBER = 16;
};
