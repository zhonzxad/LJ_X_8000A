//Copyright (c) 2019 KEYENCE CORPORATION. All rights reserved.
#pragma once


// CDepthProgramSelectDlg Dialog

class CDepthProgramSelectDlg : public CDialog
{
	DECLARE_DYNAMIC(CDepthProgramSelectDlg)

public:
	CDepthProgramSelectDlg(BOOL isDiplayDepth, BOOL isDisplayProgram, CWnd* pParent = NULL);   // Standard constructer
	virtual ~CDepthProgramSelectDlg();
	
	BYTE GetDepth();
	BYTE GetTarget();
	void OnShowWindow(BOOL isShow, UINT nStatus);

// Dialog data
	enum { IDD = IDD_DEPTHPROGRAMSELECTDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV Support

	DECLARE_MESSAGE_MAP()

private:
	BOOL m_bIsDepthVisible;
	BOOL m_bIsTargetVisible;
	CString m_strDepth;
	CString m_strTarget;
	static const int BASE_NUMBER = 16;
};
