//Copyright (c) 2019 KEYENCE CORPORATION. All rights reserved.
//

#pragma once
#include "afxcmn.h"
#include "SingleFuncDlg.h"
#include "CombinationFuncDlg.h"

#include "LJX8_IF.h"
#include "LJX8_ErrorCode.h"


// CLJX_DllSampleAllDlg Dialogue
class CLJX_DllSampleAllDlg : public CDialog
{

public:
	CLJX_DllSampleAllDlg(CWnd* pParent = NULL);

// Dialogue Data
	enum { IDD = IDD_LJX_DLLSAMPLEALL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);


protected:
	HICON m_hIcon;

	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	CTabCtrl m_xcTab;
	CSingleFuncDlg m_singleFuncDlg;
	CCombinationFuncDlg m_combinationFuncDlg;
	
public:
	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
};
