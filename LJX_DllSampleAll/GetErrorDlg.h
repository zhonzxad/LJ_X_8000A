//Copyright (c) 2019 KEYENCE CORPORATION. All rights reserved.
#pragma once


// CGetErrorDlg Dialog

class CGetErrorDlg : public CDialog
{
	DECLARE_DYNAMIC(CGetErrorDlg)

public:
	CGetErrorDlg(CWnd* pParent = NULL);   // Standard constructer
	virtual ~CGetErrorDlg();

	BOOL OnInitDialog();

// Dialog data
	enum { IDD = IDD_GETERRORDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV Support

	DECLARE_MESSAGE_MAP()

public:
	BYTE m_byReceiveMax;
};
