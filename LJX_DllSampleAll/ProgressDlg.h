#pragma once


// CProgressDlg Dialog

typedef enum {

	PROFILE_PROCESSING_STATUS_COMMUNICATING = 0,
	PROFILE_PROCESSING_STATUS_SAVING
}PROFILE_PROCESSING_STATUS;


class CProgressDlg : public CDialog
{
	DECLARE_DYNAMIC(CProgressDlg)

public:
	CProgressDlg(CWnd* pParent = NULL);   // Standard constructer
	virtual ~CProgressDlg();
	virtual BOOL OnInitDialog();
	void SetStatus(PROFILE_PROCESSING_STATUS status);

// Dialog data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROGRESS_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV Support

	DECLARE_MESSAGE_MAP()
private:
LPCTSTR GetStatusText(PROFILE_PROCESSING_STATUS status);
PROFILE_PROCESSING_STATUS m_status;
};
