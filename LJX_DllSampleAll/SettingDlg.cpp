//Copyright (c) 2019 KEYENCE CORPORATION. All rights reserved.
// SettingDlg.cpp :Implementation file
//

#include "stdafx.h"
#include "LJX_DllSampleAll.h"
#include "SettingDlg.h"


// CSettingDlg Dialog

IMPLEMENT_DYNAMIC(CSettingDlg, CDialog)

CSettingDlg::CSettingDlg(BOOL isDisplay, CWnd* pParent /*=NULL*/)
	: CDialog(CSettingDlg::IDD, pParent)
	, m_bIsDisplay(isDisplay)
	// Settings that change the sampling period of the running area to "100 Hz"
	, m_strDepth(_T("1"))
	, m_strType(_T("10"))
	, m_strCategory(_T("0"))
	, m_strItem(_T("2"))
	, m_strTarget1(_T("0"))
	, m_strTarget2(_T("0"))
	, m_strTarget3(_T("0"))
	, m_strTarget4(_T("0"))
	, m_nDataAmount(1)
	, m_strParameters(_T("3"))
{
}

CSettingDlg::~CSettingDlg()
{
}

void CSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_DEPTH, m_strDepth);
	DDX_Text(pDX, IDC_EDIT_TYPE, m_strType);
	DDX_Text(pDX, IDC_EDIT_CATEGORY, m_strCategory);
	DDX_Text(pDX, IDC_EDIT_ITEM, m_strItem);

	DDX_Text(pDX, IDC_EDIT_TARGET1, m_strTarget1);
	DDX_Text(pDX, IDC_EDIT_TARGET2, m_strTarget2);
	DDX_Text(pDX, IDC_EDIT_TARGET3, m_strTarget3);
	DDX_Text(pDX, IDC_EDIT_TARGET4, m_strTarget4);

	DDX_Text(pDX, IDC_EDIT_DATAAMOUNT, m_nDataAmount);
	DDX_Text(pDX, IDC_EDIT_PARAMETER, m_strParameters);
	DDV_MaxChars(pDX, m_strDepth, 2);
	DDV_MaxChars(pDX, m_strType, 2);
	DDV_MaxChars(pDX, m_strCategory, 2);
	DDV_MaxChars(pDX, m_strItem, 2);
	DDV_MaxChars(pDX, m_strTarget1, 2);
	DDV_MaxChars(pDX, m_strTarget2, 2);
	DDV_MaxChars(pDX, m_strTarget3, 2);
	DDV_MaxChars(pDX, m_strTarget4, 2);
	DDV_MinMaxInt(pDX, m_nDataAmount, 0, 32767);
	DDV_MaxChars(pDX, m_strParameters, 6500);
}


BEGIN_MESSAGE_MAP(CSettingDlg, CDialog)
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// CSettingDlg Message handler
/*
 Displya only the necessary parameter
 @param Display flag
 @param Status
*/
void CSettingDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialog::OnShowWindow(bShow, nStatus);

	if(!m_bIsDisplay)
	{
		GetDlgItem(IDC_EDIT_PARAMETER)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_PARAMETERNOTE)->ShowWindow(SW_HIDE);
	}

	CWnd* pWndDepth = GetDlgItem(IDC_EDIT_DEPTH);
	CWnd* pWndType = GetDlgItem(IDC_EDIT_TYPE);
	CWnd* pWndCategory = GetDlgItem(IDC_EDIT_CATEGORY);
	CWnd* pWndItem = GetDlgItem(IDC_EDIT_ITEM);
	CWnd* pWndTarget1 = GetDlgItem(IDC_EDIT_TARGET1);
	CWnd* pWndTarget2 = GetDlgItem(IDC_EDIT_TARGET2);
	CWnd* pWndTarget3 = GetDlgItem(IDC_EDIT_TARGET3);
	CWnd* pWndTarget4 = GetDlgItem(IDC_EDIT_TARGET4);
	CWnd* pWndDataAMount = GetDlgItem(IDC_EDIT_DATAAMOUNT);
	CWnd* pWndParameter = GetDlgItem(IDC_EDIT_PARAMETER);
	CEdit *editDepth = static_cast<CEdit*>(pWndDepth);
	CEdit *editType = static_cast<CEdit*>(pWndType);
	CEdit *editCategory = static_cast<CEdit*>(pWndCategory);
	CEdit *editItem = static_cast<CEdit*>(pWndItem);
	CEdit *editTarget1 = static_cast<CEdit*>(pWndTarget1);
	CEdit *editTarget2 = static_cast<CEdit*>(pWndTarget2);
	CEdit *editTarget3 = static_cast<CEdit*>(pWndTarget3);
	CEdit *editTarget4 = static_cast<CEdit*>(pWndTarget4);
	CEdit *editDataAMount = static_cast<CEdit*>(pWndDataAMount);
	CEdit *editParameter = static_cast<CEdit*>(pWndParameter);
	editDepth->SetLimitText(2);
	editType->SetLimitText(2);
	editCategory->SetLimitText(2);
	editItem->SetLimitText(2);
	editTarget1->SetLimitText(2);
	editTarget2->SetLimitText(2);
	editTarget3->SetLimitText(2);
	editTarget4->SetLimitText(2);
	editDataAMount->SetLimitText(5);
	editParameter->SetLimitText(6500);
}

/*
 Get the Depth
 @return Depth
*/
BYTE CSettingDlg::GetDepth(void)
{
	TCHAR* pszEnd = NULL;
	BYTE receiveData = (BYTE)( ::_tcstol(m_strDepth, &pszEnd, BASE_NUMBER) );

	if (errno == ERANGE) { 
		return -1;			// Overflow, Underflow
	} 

	return receiveData;
}

/*
 Get the target setting
 @return LJX8IF_TARGET_SETTING
*/
LJX8IF_TARGET_SETTING CSettingDlg::GetTargetSetting()
{
	LJX8IF_TARGET_SETTING targetSetting;
	TCHAR*	pszEnd;

	targetSetting.byType = (BYTE)( ::_tcstol(m_strType, &pszEnd, BASE_NUMBER) );
	targetSetting.byCategory = (BYTE)( ::_tcstol(m_strCategory, &pszEnd, BASE_NUMBER) );
	targetSetting.byItem = (BYTE)( ::_tcstol(m_strItem, &pszEnd, BASE_NUMBER) );
	targetSetting.reserve = 0;							// reserve
	targetSetting.byTarget1 = (BYTE)( ::_tcstol(m_strTarget1, &pszEnd, BASE_NUMBER) );
	targetSetting.byTarget2 = (BYTE)( ::_tcstol(m_strTarget2, &pszEnd, BASE_NUMBER) );
	targetSetting.byTarget3 = (BYTE)( ::_tcstol(m_strTarget3, &pszEnd, BASE_NUMBER) );
	targetSetting.byTarget4 = (BYTE)( ::_tcstol(m_strTarget4, &pszEnd, BASE_NUMBER) );

	return targetSetting;
}

/*
 Get the send data
 @return Send data
*/
vector<BYTE> CSettingDlg::GetSendData()
{	
	CString strReceiveBuffer;
	int nCount = 0;
	TCHAR szSeparator = _T(',');
	
	while( AfxExtractSubString(strReceiveBuffer, m_strParameters, nCount++, szSeparator) )
	{
		TCHAR*	pszEnd;
		BYTE byReceiveData = (BYTE)( ::_tcstol(strReceiveBuffer, &pszEnd, BASE_NUMBER) );
		m_vecSendData.push_back(byReceiveData);
	}

	return m_vecSendData;
}