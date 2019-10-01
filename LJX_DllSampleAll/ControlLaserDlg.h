#pragma once
#include "afxwin.h"


// CControlLaserDlg Dialog

class CControlLaserDlg : public CDialog
{
	DECLARE_DYNAMIC(CControlLaserDlg)

public:
	CControlLaserDlg(CWnd* pParent = NULL);   // Standard constructer
	virtual ~CControlLaserDlg();
	BYTE GetLaserStatus();

// Dialog data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONTROLLASERDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV Support
	DECLARE_MESSAGE_MAP()

private:
	static const int BASE_NUMBER = 16;
	CString m_strLaserStatus;
	
};
