//Copyright (c) 2019 KEYENCE CORPORATION. All rights reserved.
#pragma once
#include "LJX8_IF.h"
#include <vector>

using namespace std;

class CProfileSimpleArrayStore
{
private:
	static const int BATCH_FINALIZE_FLAG_BIT_COUNT = 16;
	CCriticalSection m_csDataAccess;
	DWORD m_dwCount;
	DWORD m_dwNotify;
	vector<WORD> m_vecProfileData;
	vector<WORD> m_vecLuminanceData;
	void CProfileSimpleArrayStore::SaveBitmap(DWORD dwIndex, DWORD dwCount, CString strPathBase);
	void CProfileSimpleArrayStore::SaveTiff(DWORD dwIndex, DWORD dwCount, CString strPathBase);
	void CProfileSimpleArrayStore::SaveBitmapCore(CString strFilePath, WORD* data, DWORD dwWidth, DWORD dwHeight);
	void CProfileSimpleArrayStore::SaveTiffCore(CString strFilePath, WORD* data, DWORD dwWidth, DWORD dwHeight);

public:
	CProfileSimpleArrayStore();
	~CProfileSimpleArrayStore();
	bool m_bIsLuminanceEnable;
	int m_nDataWidth;
	int m_nBatchNo;
	DWORD GetCount();
	void AddCount(DWORD dwCount);
	DWORD GetNotify();
	void AddNotify(DWORD dwNotify);
	bool AddReceivedData(WORD* pwProfileBuffer, WORD* pwLuminanceBuffer, DWORD dwCount);
	void Clear();
	bool SaveDataAsImages(CString strFilePath, DWORD dwIndex, DWORD dwCount);
	void WriteTiffHeader(FILE* fTif, DWORD dwWidth, DWORD dwHeight);
	void WriteTiffTag(FILE* fTif, unsigned short kind, unsigned short dataType, unsigned int dataSize, unsigned int data);
};
