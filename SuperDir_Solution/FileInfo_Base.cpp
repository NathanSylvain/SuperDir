#pragma once
#include "FileInfo_Base.h"
#include <string.h>
#include <stdio.h>

void FileInfo_Base::Init(const char* aFolder, const char* aFile)
{
	strncpy_s(mFolder, aFolder, 512);
	strncpy_s(mFile, aFile, 256);
}

char* FileInfo_Base::GetFullPath()
{
	char* fullPath = new char[512 + 256];
	memset(fullPath, '\0', (512 + 256));

	int i = 0;
	int j = 0;

	while (mFolder[i] != '\0' && i < 512) {
		fullPath[i] = mFolder[i];
		i++;
	}

	if (fullPath[i - 1] != '\\') {
		fullPath[i] = '\\';
		i++;
	}

	while (mFile[j] != '\0' && j < 256) {
		fullPath[i + j] = mFile[j];
		j++;
	}

	fullPath[i + j] = '\0';

	return fullPath;
}
