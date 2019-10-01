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
const static int MULTIPLE_VALUE_FOR_LUMINANCE_OUTPUT = 2;

// Value when luminance output is on 
const static int LUMINANCE_OUTPUT_ON_VALUE = 1;

// Connection max count
const static LONG LJX8IF_GUI_DEVICE_COUNT = 6;

class CDeviceData
{
public:
	CDeviceData(void);
	~CDeviceData(void);

	CString GetStatusString(void);

	typedef enum
	{
		DEVICESTATUS_NO_CONNECTION = 0,
		DEVICESTATUS_ETHERNET,
		DEVICESTATUS_ETHERNET_FAST,
	} DEVICESTATUS;

	DEVICESTATUS m_deviceStatus;							// Connection state
	LJX8IF_ETHERNET_CONFIG m_ethernetConfig;				// Ethernet Setting
	vector<PROFILE_DATA> m_vecProfileData;					// Profile Data
	vector<PROFILE_DATA> m_vecProfileDataHighSpeed;			// Profile Data for high speed communication
	CProfileSimpleArrayStore m_simpleArrayStore;			// Simple array data store
	CProfileSimpleArrayStore m_simpleArrayStoreHighSpeed;	// Simple array data store for high speed communication
};
