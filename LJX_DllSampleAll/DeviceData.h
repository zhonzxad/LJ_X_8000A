//Copyright (c) 2019 KEYENCE CORPORATION. All rights reserved.
#pragma once
#include "LJX8_IF.h"
#include <vector>
#include "ProfileSimpleArrayStore.h"

using namespace std;

struct PROFILE_DATA
{
	LJX8IF_PROFILE_INFO m_profileInfo;

	LJX8IF_PROFILE_HEADER m_profileHeader;
	int* m_pnProfileData;
	LJX8IF_PROFILE_FOOTER m_profileFooter;
	
	PROFILE_DATA();
	PROFILE_DATA(const LJX8IF_PROFILE_INFO &profileInfo, const LJX8IF_PROFILE_HEADER *header, const int *data, const LJX8IF_PROFILE_FOOTER *footer);
	PROFILE_DATA(const PROFILE_DATA& obj);

	BOOL GetIsLuminanceOutput(LJX8IF_PROFILE_INFO profileInfo);
	
	~PROFILE_DATA();
};

// Multiple value for luminance output on
// 有多个亮度输出值
const static int MULTIPLE_VALUE_FOR_LUMINANCE_OUTPUT = 2;

// Value when luminance output is on 
// 亮度输出打开时的值
const static int LUMINANCE_OUTPUT_ON_VALUE = 1;

// Connection max count
// 最大的连接数量
const static LONG LJX8IF_GUI_DEVICE_COUNT = 6;

class CDeviceData
{
public:
	CDeviceData(void);
	~CDeviceData(void);

	CString GetStatusString(void);

	typedef enum
	{
		DEVICESTATUS_NO_CONNECTION = 0, //无连接
		DEVICESTATUS_ETHERNET,			//以太网连接
		DEVICESTATUS_ETHERNET_FAST,		//高速以太网连接
	} DEVICESTATUS;

	DEVICESTATUS m_deviceStatus;							// 连接状态
	LJX8IF_ETHERNET_CONFIG m_ethernetConfig;				// 以太网配置（IP地址和端口号）
	vector<PROFILE_DATA> m_vecProfileData;					// 轮廓数据 Profile Data
	vector<PROFILE_DATA> m_vecProfileDataHighSpeed;			// 高速连接中的轮廓数据 Profile Data for high speed communication
	CProfileSimpleArrayStore m_simpleArrayStore;			// 简单数组数据存储 Simple array data store
	CProfileSimpleArrayStore m_simpleArrayStoreHighSpeed;	// 高速连接中的简单数组数据存储 Simple array data store for high speed communication
};
