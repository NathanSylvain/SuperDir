#include "Funtion.h";
#include <Windows.h>;
#include "FileInfo_CPP.h"
#include "FileInfo_H.h"
#include "FileInfo_EXE.h"
#include "FileInfo_Other.h"


IFileInfo** Funtion::FindFiles(const char* aFolder) 
{
	IFileInfo** fichiers = new IFileInfo * [100];
	memset(fichiers, NULL, 100 * sizeof(IFileInfo));


		
	return fichiers;
}

//void CreateFileInfoInstance() {

//	if (filename.substr(filename.find_last_of(".") + 1) == "cpp") {
//		lFiles[0] = new FileInfo_CPP;
//	}
//	else if (filename.substr(filename.find_last_of(".") + 1) == "h")
//	{
//		lFiles[count] = new FileInfo_H;
//	}
//	else if (filename.substr(filename.find_last_of(".") + 1) == "exe")
//	{
//		lFiles[count] = new FileInfo_EXE;
//	}
//	else
//	{
//		lFiles[count] = new FileInfo_Other;
//	}
//}