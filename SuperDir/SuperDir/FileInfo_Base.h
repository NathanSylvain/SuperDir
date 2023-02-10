#pragma once
#include "IFileInfo.h"
class FileInfo_Base: public IFileInfo
{
public:
	virtual void Init(const wchar_t* aDirectory, char* aFile);

protected:


	const wchar_t* mDirectory;
	char* mFile;

};

