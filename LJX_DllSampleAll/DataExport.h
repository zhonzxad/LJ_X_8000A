//Copyright (c) 2019 KEYENCE CORPORATION. All rights reserved.
#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "DeviceData.h"

using namespace std;

class CDataExport
{
public:
	CDataExport(void);
	~CDataExport(void);

	static BOOL ExportProfileEx(const PROFILE_DATA *profileData, CString strFileName, int nProfileCount);
	static BOOL ExportMultipleData(const PROFILE_DATA *profileData, CString strFileName, int nProfileCount, int nDataStartIndex);
	static CString CDataExport::GetDeterminantFilePath(CString strFileName, CString strFileAdditionalName);

private:
	static CString HEIGHT_DATA_ADDITIONAL_FILE_PATH;
	static CString LUMINANCE_DATA_ADDITIONAL_FILE_PATH;

	const static int PROFILE_DATA_START_INDEX = 0;
	const static char EXTENSION_START_CHAR = '.';
	const static int INVALID_INDEX = -1;
	const static int PROFILE_CHARACTER_BUFFER_SIZE = 16;
};
