//Copyright (c) 2019 KEYENCE CORPORATION. All rights reserved.
#include "StdAfx.h"
#include "DeviceData.h"

CDeviceData::CDeviceData(void)
{
}

CDeviceData::~CDeviceData(void)
{
}

/*
 Get Status
 @return Device status
*/
CString CDeviceData::GetStatusString(void)
{
	CString status = NULL;

	switch(m_deviceStatus)
	{
		case DEVICESTATUS_NO_CONNECTION:
			status = "NoConnection";
			break;

		case DEVICESTATUS_ETHERNET:
			status.Format(_T("Ethernet---%d.%d.%d.%d")
				,m_ethernetConfig.abyIpAddress[0]
				,m_ethernetConfig.abyIpAddress[1]
				,m_ethernetConfig.abyIpAddress[2]
				,m_ethernetConfig.abyIpAddress[3]);
			break;

		case DEVICESTATUS_ETHERNET_FAST:
			status.Format(_T("EthernetFast---%d.%d.%d.%d")
				,m_ethernetConfig.abyIpAddress[0]
				,m_ethernetConfig.abyIpAddress[1]
				,m_ethernetConfig.abyIpAddress[2]
				,m_ethernetConfig.abyIpAddress[3]);
			break;

		default:
			status = "Error";
			break;
	}
	return status;
}


/*
 Constructor for PROFILE_DATA
*/
PROFILE_DATA::PROFILE_DATA()
:m_pnProfileData(NULL)
{
}

/*
 Constructor for PROFILE_DATA
*/
PROFILE_DATA::PROFILE_DATA(const LJX8IF_PROFILE_INFO &profileInfo, const LJX8IF_PROFILE_HEADER *header, const int *data, const LJX8IF_PROFILE_FOOTER *footer)
{
	m_profileInfo = profileInfo;

	m_profileHeader = *header;

	int nMultipleValue = GetIsLuminanceOutput(profileInfo) ? MULTIPLE_VALUE_FOR_LUMINANCE_OUTPUT : 1;
	int nReceiveDataSize = profileInfo.wProfileDataCount * nMultipleValue * profileInfo.byProfileCount;
	m_pnProfileData = new int[nReceiveDataSize];
	memcpy_s(m_pnProfileData, sizeof(int) * nReceiveDataSize, data, sizeof(int) * nReceiveDataSize);
	
	m_profileFooter = *footer;
}

/*
Copy constructor for PROFILE_DATA
*/
PROFILE_DATA::PROFILE_DATA(const PROFILE_DATA& obj)
{
	m_profileInfo = obj.m_profileInfo;
	m_profileHeader = obj.m_profileHeader;
	m_profileFooter = obj.m_profileFooter;

	int nMultipleValue = GetIsLuminanceOutput(obj.m_profileInfo) ? MULTIPLE_VALUE_FOR_LUMINANCE_OUTPUT : 1;
	int nReceiveDataSize = obj.m_profileInfo.wProfileDataCount * obj.m_profileInfo.byProfileCount * nMultipleValue;
	m_pnProfileData = new int[nReceiveDataSize];
	for (int i = 0; i < nReceiveDataSize; i++)
	{
		m_pnProfileData[i] = obj.m_pnProfileData[i];
	}
}

//获取是否有亮度值输出 
BOOL PROFILE_DATA::GetIsLuminanceOutput(LJX8IF_PROFILE_INFO profileInfo)
{
	return profileInfo.byLuminanceOutput == LUMINANCE_OUTPUT_ON_VALUE;
}

/*
 Destructor for PROFILE_DATA
 销毁轮廓数据
*/
PROFILE_DATA::~PROFILE_DATA()
{
	delete[] m_pnProfileData;
}