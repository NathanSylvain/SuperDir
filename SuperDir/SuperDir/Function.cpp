#include "Funtion.h";
#include <Windows.h>;
#include "FileInfo_CPP.h"
#include "FileInfo_H.h"
#include "FileInfo_EXE.h"
#include "FileInfo_Other.h"
#include <filesystem>
#include <tchar.h>
#include <stdio.h>


IFileInfo** Funtion::FindFiles(const char* aFolder)
{
	IFileInfo** fichiers = new IFileInfo * [100];

	for (unsigned int i = 0; i < 99; i++)
	{
		if (fichiers != NULL)
		{
			fichiers[i] = NULL;
		}
	}

	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;
	

	wchar_t* wFolderName = new wchar_t[4096];
	MultiByteToWideChar(CP_ACP, 0, aFolder, -1, wFolderName, 4096);
	hFind = FindFirstFile(wFolderName, &FindFileData);

	if (INVALID_HANDLE_VALUE == hFind)
	{
		printf("FindFirstFile failed (%d)\n", GetLastError());
		return fichiers;
	}
	else
	{
		_tprintf(TEXT("The first file found is %s\n"),FindFileData.cFileName);
		FindClose(hFind);
	}
	
		
	
}

IFileInfo** Funtion::FFindNextFile(const char* aFolder)
{
    WIN32_FIND_DATA FindFileData;
    LARGE_INTEGER filesize;
    TCHAR szDir[MAX_PATH];
    size_t length_of_arg = 0;
    HANDLE hFind = INVALID_HANDLE_VALUE;
    DWORD dwError = 0;
    IFileInfo** fichiersM = new IFileInfo * [100]; //pour pas que ca plante


    wchar_t* wFolderName = new wchar_t[4096];
    MultiByteToWideChar(CP_ACP, 0, aFolder, -1, wFolderName, 4096);
    hFind = FindFirstFile(wFolderName, &FindFileData);

    if (length_of_arg > (MAX_PATH - 3))
    {
        _tprintf(TEXT("\nDirectory path is too long.\n"));

    }

    _tprintf(TEXT("\nTarget directory is %s\n\n"), aFolder);



    hFind = FindFirstFile(szDir, &FindFileData);

    do
    {
        if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            _tprintf(TEXT("  %s   <DIR>\n"), FindFileData.cFileName);
        }
        else
        {
            filesize.LowPart = FindFileData.nFileSizeLow;
            filesize.HighPart = FindFileData.nFileSizeHigh;
            _tprintf(TEXT("  %s   %ld bytes\n"), FindFileData.cFileName, filesize.QuadPart);
        }
    } while (FindNextFile(hFind, &FindFileData) != 0);

    dwError = GetLastError();

    FindClose(hFind);
    return fichiersM;
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