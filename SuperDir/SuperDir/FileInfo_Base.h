#pragma once
#include "IFileInfo.h"
class FileInfo_Base: public IFileInfo
{
public:
	virtual void Init(const char* aDirectory, char* aFile);

protected:


	 char mDirectory[512];
	char mFile[256];

};

