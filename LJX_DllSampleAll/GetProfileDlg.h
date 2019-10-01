//Copyright (c) 2019 KEYENCE CORPORATION. All rights reserved.
#pragma once
#include<LJX8_IF.h>


// CGetProfileDlg Dialog

class CGetProfileDlg : public CDialog
{
	DECLARE_DYNAMIC(CGetProfileDlg)

public:
	CGetProfileDlg(CWnd* pParent = NULL);   // Standard constructer
	virtual ~CGetProfileDlg();

	BOOL OnInitDialog();
	LJX8IF_GET_PROFILE_REQUEST CGetProfileDlg::GetProfileReq(void);

// Dialog data
	enum { IDD = IDD_GETPROFILEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV Support

	DECLARE_MESSAGE_MAP()

private:
	CString m_strTargetBank;
	CString m_strPosMode;
	DWORD m_dwProfileNo;
	BYTE m_byProfileCount;
	BYTE m_byEraseFlg;
	static const int BASE_NUMBER = 16;
};
