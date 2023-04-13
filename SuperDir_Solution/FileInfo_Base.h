#pragma once
#include "IFileInfo.h"

class FileInfo_Base : public IFileInfo {
	public:
		virtual void Init(const char* aFolder, const char* aFile);
		virtual void RetrieveInformation() = 0;
		virtual void DisplayInformation() = 0;
	protected :
		char mFolder[512];
		char mFile[256];
		char* GetFullPath();
};