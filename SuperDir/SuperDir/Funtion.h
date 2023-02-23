#pragma once
#include "IFileInfo.h"
class Funtion
{
public:
	static IFileInfo** FindFiles(const char* aFolder);
	static IFileInfo** FFindNextFile(const char* aFolder);
};

