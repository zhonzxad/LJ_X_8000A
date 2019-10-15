//Copyright (c) 2019 KEYENCE CORPORATION. All rights reserved.

#pragma once
#include "LJX8_IF.h"
#include "LJX8_ErrorCode.h"
#include "DeviceData.h"
#include "afxwin.h"
#include "afxcmn.h"

// CSingleFuncDlg Dialogue

using namespace std;

class CSingleFuncDlg : public CDialog
{
	DECLARE_DYNAMIC(CSingleFuncDlg)

public:
	CSingleFuncDlg(CWnd* pParent = NULL);
	virtual ~CSingleFuncDlg();

// Dialogue Data
	enum { IDD = IDD_SINGLEFUNCDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	DECLARE_MESSAGE_MAP()
	
private:
	// DDX variable
	CEdit m_txtCommandLog;									// 用于命令日志的EditBox
	CStatic m_sttConnectionStatus[LJX8IF_GUI_DEVICE_COUNT];	// 状态标签
	CButton m_btnDeviceState;								// 设备状态的单选按钮 
	CComboBox m_cmbXRange;									// X（范围）系列的组合框
	CComboBox m_cmbXThinning;								// X压缩的组合框
	CString m_strSpinStartTimer;							// 启动计时器的旋转控制（CString）
	CString m_strSpinProfIndex;								// 配置文件索引的旋转控制
	CString m_strSpinProfCount;								// 旋转控制轮廓数
	CSpinButtonCtrl m_sbcSpinStartTimer;					// 启动计时器的旋转控制（CSpinButtonCtrl）Spin Control for Start Timer
	CSpinButtonCtrl m_sbcSpinProfIndex;						// 轮廓索引的旋转控制（CSpinButtonCtrl）Spin Control for Profile index
	CSpinButtonCtrl m_sbcSpinProfCount;						// 旋转控制轮廓数 （CSpinButtonCtrl）Spin Control for Profile count
	CString m_strSaveFilePath;								// 保存文件路径
	CString m_strHighSpeedSaveFilePath;						// 高速保存文件路径
	CComboBox m_cmbSamplingPeriod;							// 采样期间的组合框
	CComboBox m_cmbLuminanceOutput;							// 亮度输出组合框
	CComboBox m_cmbLjvMeasureX;								// LJ-V测量X的组合框
	CComboBox m_cmbLjvBinning;								// 用于LJ-V分箱的组合框 Combo Box for LJ-V Binning
	CComboBox m_cmbLjvThinning;								// 用于LJ-V稀疏的组合框 Combo Box for LJ-V Thinning
	CStatic m_sttBufferSizeValue;							// 缓冲区大小的标签 

	int m_nCurrentDeviceID;
	int m_nXRange;
	int m_nXThinning;
	int m_nSamplingPeriod;
	int m_nLuminanceOutput;
	int m_nLjvMeasureX;
	int m_nLjvBinning;
	int m_nLjvThinning;
	int m_nHeadType;
	BOOL m_bIsUseSimpleArray;
	BOOL m_bIsCountOnly;
	BOOL m_bIsStartTimer;
	CString m_strCommandLog;
	int m_anProfReceiveCount[LJX8IF_GUI_DEVICE_COUNT];
	static CDeviceData m_aDeviceData[LJX8IF_GUI_DEVICE_COUNT];
	static LJX8IF_PROFILE_INFO m_aProfileInfo[];
	static BOOL m_bIsBufferFull[];
	static BOOL m_bIsStopCommunicationByError[];

	static const int NO_ERROR_VALUE = 0;

	// Storage structure (storage status)
	// 仓储结构（仓储对象）
	static const int STORAGE_INFO_STATUS_EMPTY    = 0;
	static const int STORAGE_INFO_STATUS_STORING  = 1;
	static const int STORAGE_INFO_STATUS_FINISHED = 2;

	// Storage structure (storage target)
	// 仓储结构（仓储对象）
	static const int STORAGE_INFO_TARGET_DATA    = 0;
	static const int STORAGE_INFO_TARGET_PROFILE = 2;
	static const int STORAGE_INFO_TARGET_BATCH   = 3;
	
	// Maximum Communication Data Size
	// 最大通讯数据量大小
	static const DWORD LJX8IFEX_MAXIMUM_READ_DATA_SIZE = 1024 * 1024;

	static const int TIMER_ID    = 100;
	static const int TIMER_ELASP = 200;
	static const int BUFFER_FULL_TIMER_ID = 300;

	// buffer full timer interval
	// 缓冲区满定时器间隔
	static const int BUFFER_FULL_TIMER_INTERVAL = 500;

	//LJ-X head index of radio button
	//LJ_X 的单选框按钮索引
	static const int LJX_HEAD_INDEX = 0;

	//LJ-VB head index of radio button
	//LJ_VB 的单选框按钮索引
	static const int LJVB_HEAD_INDEX = 2;

	//Thinning combobox index
	//LJ_V细化组合框索引
	static const int LJV_THINNING_OFF_INDEX = 0;
	static const int LJV_THINNING_2_INDEX = 1;

	//Thinning combobox index
	//LJ_X细化组合框索引
	static const int LJX_THINNING_OFF_INDEX = 0;
	static const int LJX_THINNING_2_INDEX = 1;

	//Profile data count lower limmit 
	//配置文件数据计数下限
	static const int PROFILE_DATA_MIN_COUNT = 200;

	//divide value for tempareture display
	//温度显示的分度值
	static const int DIVIDE_VALUE_FOR_HEAD_TEMPARETURE_DISPLAY = 100;

	//data count in one line(get setting result)
	//一行数据计数（获取设置结果）
	static const int DATA_COUNT_IN_ONE_LINE = 8;

	// value of not accessing memory(check memory)
	// 不访问内存（检查内存）的值
	static const int NOT_ACCESS_VALUE = 0;

	//head temperature invalid value
	//传感头温度初始值
	static const int HEAD_TEMPERATURE_INVALID_VALUE = 0xFFFF;

	typedef enum
	{
		SENDCOMMAND_NONE,												// 发送空 None
		SENDCOMMAND_REBOOT_CONTROLLER,									// 发送重启 Restart
		SENDCOMMAND_TRIGGER,											// 发送触发 Trigger
		SENDCOMMAND_START_MEASURE,										// 发送开始测量 Start measurement
		SENDCOMMAND_STOP_MEASURE,										// 发送停止测量 Stop measurement
		SENDCOMMAND_GET_PROFILE,										// 发送获取轮廓数据 Get profiles
		SENDCOMMAND_GET_BATCH_PROFILE,									// 发送获取批次配置文件 Get batch profiles
		SENDCOMMAND_REQUEST_STORAGE,									// 发送手动存储请求 Manual storage request
		SENDCOMMAND_INITIALIZE_HIGH_SPEED_DATA_ETHERNET_COMMUNICATION,	// 发送初始化以太网高速数据通信 Initialize Ethernet high-speed data communication
		SENDCOMMAND_PRE_START_HIGH_SPEED_DATA_COMMUNICATION,			// 发送开始高速数据通信之前要求准备 Request preparation before starting high-speed data communication
		SENDCOMMAND_START_HIGH_SPEED_DATA_COMMUNICATION,				// 发送开始高速数据通讯 Start high-speed data communication
	} SENDCOMMAND; 
	SENDCOMMAND m_sendCommand; //发送命令

	BOOL OnInitDialog();
	BOOL PreTranslateMessage(MSG* pMsg);
	void DisplayCommandLog(LONG lRc, int commandID);
	void AddLog(int nDisplayFormat, LONG lRc);
	void AddLog(int nDisplayFormat, CString strErrorMessage);
	void AddLog(CString commandCode, CString result, LONG lRc);
	void AddErrorLog(LONG lRc);
	void AddResult(CString item, CString text);
	void AddLogResult(LONG lRc, CString commandCode);
	void AddSettingErrorLog(DWORD dwError);
	void AddAdditionalErrorLog(int nDisplayFormat, int nErrorLog);
	void CommonErrorLog(LONG lRc);
	void IndividualErrorLog(LONG lRc);
	BOOL ControllerErrorLog(LONG lRc);
	void ShowMessage(CString strMessage);
	void ShowResponse(LJX8IF_GET_PROFILE_RESPONSE rsp);
	void ShowResponse(LJX8IF_GET_BATCH_PROFILE_RESPONSE rsp);
	void ShowProfileInfo(LJX8IF_PROFILE_INFO profileInfo);
	void ShowHeadTemperature(SHORT nSensorTemperature, SHORT nProcessorTemperature, SHORT nCaseTemperature);
	CString GetTemperatureText(SHORT nTemperature);
	void UpDateReceiveCount();
	void InitializeAllConnectionInfo();
	void InitializeConnectionInfo(int targetDeviceID);
	int GetOneProfileDataSize();
	int GetXDirectionDataCount();
	int GetLjvProfileCountByMeasureRange();
	int GetLjvXDirectionDataCount();
	int GetLjvProfileCount();
	int GetLjvDivideValueByBinning();
	int GetLjxXDirectionDataCount();
	int GetLjxProfileCount();
	int GetLjxProfileCountByMeasureRange();
	int GetLjxDivideValueByThinning();
	bool GetIsLjxXBinningOn();
	bool GetLjxLuminanceOutputOn();
	int CalculateDataSize(const LJX8IF_PROFILE_INFO &profileInfo);
	void AnalyzeProfileData(BYTE byGetProfileCount, LJX8IF_PROFILE_INFO profileInfo, vector<int> profileData);
	void ExportProfile();
	BOOL GetIsLuminanceOutput(LJX8IF_PROFILE_INFO profileInfo);
	static void ReceiveHighSpeedData(BYTE* pBuffer, DWORD dwSize, DWORD dwCount, DWORD dwNotify, DWORD dwUser);
	static void CountProfileReceive(BYTE* pBuffer, DWORD dwSize, DWORD dwCount, DWORD dwNotify, DWORD dwUser);
	static void ReceiveHighSpeedSimpleArray(LJX8IF_PROFILE_HEADER* pProfileHeaderArray, WORD* pHeightProfileArray, WORD* pLuminanceProfileArray, DWORD dwLuminanceEnable, DWORD dwProfileDataCount, DWORD dwCount, DWORD dwNotify, DWORD dwUser);
	static void CountSimpleArrayReceive(LJX8IF_PROFILE_HEADER* pProfileHeaderArray, WORD* pHeightProfileArray, WORD* pLuminanceProfileArray, DWORD dwLuminanceEnable, DWORD dwProfileDataCount, DWORD dwCount, DWORD dwNotify, DWORD dwUser);
	void ClearAllHighspeedBuffer(int nDeviceId);

	void UpdateBufferSizeText();
	CString GetBufferSizeText();
	void UpdateBufferSizeSettingItemEnabled();
	void UpdateHighSpeedGetSimpleArrayItemEnabled();
	void UpdateLjxBufferSizeSettingItemEnabled(BOOL isEnabled);
	void UpdateLjvBufferSizeSettingItemEnabled(BOOL isEnabled);
	void UpdateHighSpeedProfileSaveSettingItemEnabled();
	void ConfirmTimerElapse();
	void ConfirmProfileindex();
	void ConfirmProfilecount();

	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnClearlog();
	afx_msg void OnBnClickedBtnHighSpeedSavedestination();
	afx_msg void OnBnClickedSaveprofile();
	afx_msg void OnBnClickedBtnInitialize();
	afx_msg void OnBnClickedBtnFinalize();
	afx_msg void OnBnClickedBtnGetversion();
	afx_msg void OnBnClickedBtnEthernetopen();
	afx_msg void OnBnClickedBtnCommunicationclose();
	afx_msg void OnBnClickedBtnRebootcontroller();
	afx_msg void OnBnClickedBtnReturntofactorysettig();
	afx_msg void OnBnClickedBtnControllaser();
	afx_msg void OnBnClickedBtnGeterror();
	afx_msg void OnBnClickedBtnClearerror();
	afx_msg void OnBnClickedBtnTrginterrorreset();
	afx_msg void OnBnClickedBtnGettriggerandpulsecount();
	afx_msg void OnBnClickedBtnGetheadtemperature();
	afx_msg void OnBnClickedBtnGetserialnumber();
	afx_msg void OnBnClickedBtnGetattentionstatus();
	afx_msg void OnBnClickedBtnTrigger();
	afx_msg void OnBnClickedBtnStartmeasure();
	afx_msg void OnBnClickedBtnStopmeasure();
	afx_msg void OnBnClickedBtnClearmemory();
	afx_msg void OnBnClickedBtnSetsetting();
	afx_msg void OnBnClickedBtnGetsetting();
	afx_msg void OnBnClickedBtnInitializesetting();
	afx_msg void OnBnClickedBtnReflectsetting();
	afx_msg void OnBnClickedBtnRewritetemporarysetting();
	afx_msg void OnBnClickedBtnCheckmemoryaccess();
	afx_msg void OnBnClickedBtnChangeactiveprogram();
	afx_msg void OnBnClickedBtnGetactiveprogram();
	afx_msg void OnBnClickedBtnGetprofile();
	afx_msg void OnBnClickedBtnGetbatchprofile();
	afx_msg void OnBnClickedBtnInitializeHighspeeddatacommunication();
	afx_msg void OnBnClickedBtnPrestarthighspeeddatacommunication();
	afx_msg void OnBnClickedBtnStarthighspeeddatacommunication();
	afx_msg void OnBnClickedBtnStophighspeeddatacommunication();
	afx_msg void OnBnClickedBtnFinalizehighspeeddatacommunication();
	afx_msg void OnBnClickedChkTimer();
	afx_msg void OnCbnSelchangeCmbLjxmeasurex();
	afx_msg void OnCbnSelchangeCmbLjxthinning();
	afx_msg void OnCbnSelchangeCmbLjxluminanceoutput();
	afx_msg void OnCbnSelchangeCmbLjxsamplingperiod();
	afx_msg void OnCbnSelchangeCmbLjvmeasurex();
	afx_msg void OnCbnSelchangeCmbLjvthinning();
	afx_msg void OnCbnSelchangeCmbLjvbinning();
	afx_msg void OnBnClickedRadioLjx();
	afx_msg void OnBnClickedRadioLjv();
	afx_msg void OnBnClickedRadioLjvb();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedChkCountOnly();
	afx_msg void OnBnClickedBtnSavedestination();
	afx_msg void OnBnClickedBtnGetbatchsimplearray();
	afx_msg void OnBnClickedBtnSaveasbitmapfile();
	afx_msg void OnBnClickedChkUsesimplearray();
	afx_msg void OnBnClickedBtnInitializehighspeeddatacommunicationSimplearray();
	afx_msg void OnBnClickedBtnHispeedsaveasbitmapfile();
	afx_msg void OnEnKillfocusEditStarttimer();
	afx_msg void OnEnKillfocusEditProfileindex();
	afx_msg void OnEnKillfocusEditProfilecount();
};
