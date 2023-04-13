#pragma once

namespace myFunctions {
	IFileInfo** FindFiles(const char* aFolder);
	bool isPathHavingExtension(const char* apath, const char* aExtension);
	char* GetFolderPathWithWildCard(const char* aFolder);
	void RetrieveInformation(IFileInfo** aFiles);
	void DisplayInformation(IFileInfo** aFiles);
	void ReleaseMemory(IFileInfo** aFiles);
}