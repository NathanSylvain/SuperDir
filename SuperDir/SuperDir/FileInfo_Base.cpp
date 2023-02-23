#include "FileInfo_Base.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>



void FileInfo_Base::Init(const char* aDirectory, char* aFile) {

	strncpy_s(mDirectory, aDirectory, 512);
	strncpy_s(mFile, aFile, 256);

	
}