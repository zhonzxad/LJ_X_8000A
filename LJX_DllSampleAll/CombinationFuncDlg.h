//Copyright (c) 2019 KEYENCE CORPORATION. All rights reserved.
#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "LJX8_IF.h"


// CCombinationFuncDlg Dialogue

class CCombinationFuncDlg : public CDialog
{
	DECLARE_DYNAMIC(CCombinationFuncDlg)

public:
	CCombinationFuncDlg(CWnd* pParent = NULL);
	virtual ~CCombinationFuncDlg();

// Dialogue Data
	enum { IDD = IDD_COMBINATIONFUNCDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

	DECLARE_MESSAGE_MAP()

private:
	int m_nConnection;
	int m_nSelectedProgram;
	int m_nCommandPort;
	int m_nReceiveProfileNum;
	int m_nHighSpeedPort;
	int m_nSendPosition;
	int m_nCallbackFrequency;
	CString m_strDataFilePath;
	CComboBox m_cmbSelectedProgram;
	CIPAddressCtrl m_iacIPAddressComb;
	static LJX8IF_PROFILE_INFO m_profileInfo;
	static const int TIMER_EX_ID = 200;
	static const int TIMER_ELASP = 500;

	BOOL OnInitDialog();
	BOOL CheckReturnCode(LONG lRc);
	LJX8IF_TARGET_SETTING GetSelectedProgramTargetSetting();
	DWORD GetSelectedProgramDataSize();
	BOOL GetIsLuminanceOutput(LJX8IF_PROFILE_INFO profileInfo);
	void ShowNgMessage();
	void ShowProcessingResultMessage(LONG lRc);
	void ShowSuccessMessage();
	DWORD GetMaxProfileDataSize();
	DWORD GetAllDataSize(DWORD dwOneDataSize, BYTE byDataCount);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedBtnEstablishcommunication();
	afx_msg void OnBnClickedBtnFinalizecommunication();
	afx_msg void OnBnClickedBtnuploadprogram();
	afx_msg void OnBnClickedBtndownloadprogram();
	afx_msg void OnBnClickedBtnreferencesavepath();
	afx_msg void OnBnClickedBtnGetprofiledata();
	afx_msg void OnBnClickedBtnGetbatchprofiledata();
	afx_msg void OnBnClickedBtnBeginhighspeeddatacommunication();
	afx_msg void OnBnClickedBtnTerminatehighspeedcommunication();
	static void ReceiveHighSpeedData(BYTE* pBuffer, DWORD dwSize, DWORD dwCount, DWORD dwNotify, DWORD dwUser);
};
