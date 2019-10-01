//Copyright (c) 2019 KEYENCE CORPORATION. All rights reserved.
#pragma once
#include <vector>
#include "LJX8_IF.h"
#include "DeviceData.h"

class CThreadSafeBuffer
{
//Singleton Pattern
private:
	CThreadSafeBuffer(void);
	static CThreadSafeBuffer* m_threadSafeBuffer;
	static const int BATCH_FINALIZE_FLAG_BIT_COUNT = 16;

public:
	static CThreadSafeBuffer* getInstance(void);
	~CThreadSafeBuffer(void);

	CCriticalSection m_csDataAccess; 
	int m_anBatchNo[LJX8IF_GUI_DEVICE_COUNT];							// Batch number
	DWORD m_adwCount[LJX8IF_GUI_DEVICE_COUNT];							// Profile data count
	DWORD m_adwNotify[LJX8IF_GUI_DEVICE_COUNT];							// Callback function notification parameter
	vector<PROFILE_DATA> m_vecProfileData[LJX8IF_GUI_DEVICE_COUNT];		// Profile data
	
	void Add(DWORD dwIndex, vector<PROFILE_DATA> &vecProfileData, DWORD dwNotify);
	void AddCount(DWORD deIndex, DWORD dwCount, DWORD dwNotify);
	void Get(DWORD dwIndex, DWORD* pdwNotify, int* pnBatchNo, vector<PROFILE_DATA> &vecProfileData);
	void ClearBuffer(int nCurrentDeviceID);
	DWORD GetCount(DWORD dwIndex, DWORD* pdwNotify, int* pnBatchNo);
};
