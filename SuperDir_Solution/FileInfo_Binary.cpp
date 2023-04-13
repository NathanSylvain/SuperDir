#include "FileInfo_Binary.h"
#include <filesystem>
#include <iostream>

void FileInfo_Binary::RetrieveInformation()
{
	char* fullPath = GetFullPath();

    if (std::filesystem::exists(fullPath)) {
        mNbBytes = std::filesystem::file_size(fullPath);        
    }
    else {
        std::cout << "File not found" << std::endl;
    }

    delete[] fullPath;
}

void FileInfo_Binary::DisplayInformation()
{
    const char* sizeSuffix[] = { "bytes", "KB", "MB", "GB", "TB" };
    int i = 0;
    double size = mNbBytes;

    while (size >= 1024 && i < 4) {
        size /= 1024;
        i++;
    }

    std::cout << "\t" << mFile << std::setw(40 - strlen(mFile)) << "";

    std::cout << std::fixed << std::setprecision(0) << size << "\t" << sizeSuffix[i];
}
