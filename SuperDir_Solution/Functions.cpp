#include "IFileInfo.h"
#include "FileInfo_H.h"
#include "FileInfo_CPP.h"
#include "FileInfo_EXE.h"
#include "FileInfo_Other.h"
#include "Functions.h"
#include <windows.h>
#include <stdio.h>

namespace myFunctions {
	IFileInfo** myFunctions::FindFiles(const char* aFolder) {
		IFileInfo** files = new IFileInfo * [100] {};
		int lastPosition = 0;
		char* folderPath = GetFolderPathWithWildCard(aFolder);

		// Créer les variables nécessaires pour FindFirstFile() et FindNextFile()
		WIN32_FIND_DATAA FindFileData;
		HANDLE hFind;

		hFind = FindFirstFileA(folderPath, &FindFileData);

		delete[] folderPath;

		if (hFind == INVALID_HANDLE_VALUE) {
			printf("FindFirstFile a echoue.\n");
			return nullptr;
		}

		do {
			if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
				// Est un dossier. On ne fait rien avec cela pour l'instant
				if (strcmp(FindFileData.cFileName, ".") && strcmp(FindFileData.cFileName, "..")) {
					//printf("\t%s\t<DIR>\n", FindFileData.cFileName);
				}
			}
			else {
				if (isPathHavingExtension(FindFileData.cFileName, ".h")) {
					files[lastPosition] = new FileInfo_H;
				} 
				else if (isPathHavingExtension(FindFileData.cFileName, ".cpp")) {
					files[lastPosition] = new FileInfo_CPP;
				} 
				else if (isPathHavingExtension(FindFileData.cFileName, ".exe")) {
					files[lastPosition] = new FileInfo_EXE;
				}
				else {
					files[lastPosition] = new FileInfo_Other;
				}

				files[lastPosition]->Init(aFolder, FindFileData.cFileName);
				lastPosition++;

				//printf("\t%s\n", FindFileData.cFileName);
			}
			
		} while (FindNextFileA(hFind, &FindFileData) != 0);

		FindClose(hFind);

		return files;
	}

	bool isPathHavingExtension(const char* aPath, const char* aExtension) {
		int currentPosition = strlen(aExtension);

		for (int i = strlen(aPath); i >= 0 && currentPosition >= 0; i--) {
			if (toupper(aPath[i]) != toupper(aExtension[currentPosition])) {
				break;
			}
			currentPosition--;
		}

		return currentPosition == -1;
	}

	char* GetFolderPathWithWildCard(const char* aFolder) {
		int length = strlen(aFolder);
		char lastChar = aFolder[length - 1];
		char* folderPath = new char[length + 3];
		strcpy_s(folderPath, length+3, aFolder);

		if (lastChar != '/' && lastChar != '\\') {
			strcat_s(folderPath, length+3, "\\*");
		}
		else {
			strcat_s(folderPath, length + 3, "*");
		}

		return folderPath;
	}

	void RetrieveInformation(IFileInfo** aFiles) {
		for (int i = 0; i < 100 && aFiles[i] != nullptr; i++) {
			aFiles[i]->RetrieveInformation();
		}
	}

	void DisplayInformation(IFileInfo** aFiles) {
		for (int i = 0; i < 100 && aFiles[i] != nullptr; i++) {
			aFiles[i]->DisplayInformation();
		}
	}

	void ReleaseMemory(IFileInfo** aFiles) {
		for (int i = 0; i < 100 && aFiles[i] != nullptr; i++) {
			delete aFiles[i];
		}
	}
}