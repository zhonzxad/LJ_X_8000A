//Copyright (c) 2019 KEYENCE CORPORATION. All rights reserved.
#include "StdAfx.h"
#include "DataExport.h"


CString CDataExport::HEIGHT_DATA_ADDITIONAL_FILE_PATH = _T("_height.csv");
CString CDataExport::LUMINANCE_DATA_ADDITIONAL_FILE_PATH = _T("_luminance.csv");

CDataExport::CDataExport(void)
{
}

CDataExport::~CDataExport(void)
{
}

/*
获取要保存的文件路径
@param原始文件名
@param文件名除原始名称外
*/
CString CDataExport::GetDeterminantFilePath(CString strFilePath, CString strFileAdditionalName)
{
	CString strDirectoryPath = strFilePath;
	CString strFileName = PathFindFileName(strFilePath);
	strDirectoryPath.TrimRight(strFileName);
	int indexOfExtensionStart = strFileName.Find(EXTENSION_START_CHAR, 0);
	if (indexOfExtensionStart != INVALID_INDEX)
	{
		strFileName.Delete(indexOfExtensionStart, (strFileName.GetLength() - indexOfExtensionStart + 1));
	}
	CString strNewFilePath = strDirectoryPath + strFileName;
	return strNewFilePath + strFileAdditionalName;
}

/*
  导出轮廓文件数据
  @param 轮廓数据
  @param 原始文件名
  @param 要导出的轮廓数
  @return 是否到处成功 (True:Success)
 */
BOOL CDataExport::ExportProfileEx(const PROFILE_DATA *profileData, CString strFileName, int nProfileCount)
{
	if (strFileName.IsEmpty()) return false;
	if (profileData == NULL) return false;

	CString strFileNameForHeight = GetDeterminantFilePath(strFileName, HEIGHT_DATA_ADDITIONAL_FILE_PATH);
	BOOL isSuccess = ExportMultipleData(profileData, strFileNameForHeight, nProfileCount, PROFILE_DATA_START_INDEX);
	if (!isSuccess) return FALSE;
	if (profileData[0].m_profileInfo.byLuminanceOutput != LUMINANCE_OUTPUT_ON_VALUE) return isSuccess;

	CString strFileNameForLuminance = GetDeterminantFilePath(strFileName, LUMINANCE_DATA_ADDITIONAL_FILE_PATH);
	WORD wProfileDataCount = profileData[0].m_profileInfo.wProfileDataCount;
	return ExportMultipleData(profileData, strFileNameForLuminance, nProfileCount, wProfileDataCount);
}


/*
具体执行到处CSV文件的函数
@param Profile data
@param File name for saving
@param The number of the profiles to export
@return Did the export succeed?(True:Success)
*/
BOOL CDataExport::ExportMultipleData(const PROFILE_DATA *profileData, CString strFileName, int nProfileCount, int nDataStartIndex)
{
	CStringA strPathAnsi(strFileName);
	ofstream ofOutfile(strPathAnsi, ios::binary);

	if(ofOutfile.is_open() == FALSE)
	{
		AfxMessageBox(_T("Failed in exporting file."));
		return FALSE;
	}
	
	unsigned char bom[] = { 0xFF, 0xFE };
	ofOutfile.write((char*)bom, sizeof(bom));

	wchar_t buffer[PROFILE_CHARACTER_BUFFER_SIZE];

	// Write ProfileData
	for(int i = 0; i < nProfileCount; i++)
	{
		for(int k = 0; k < profileData[i].m_profileInfo.wProfileDataCount; k++)		// Profile Data
		{
			int length = swprintf_s(buffer, PROFILE_CHARACTER_BUFFER_SIZE, L"%d\t", profileData[i].m_pnProfileData[nDataStartIndex + k]);
			ofOutfile.write((char*)buffer, length * sizeof(wchar_t));
		}
		ofOutfile.write("\r", sizeof(wchar_t));
		ofOutfile.write("\n", sizeof(wchar_t));
	}
	return TRUE;
}

