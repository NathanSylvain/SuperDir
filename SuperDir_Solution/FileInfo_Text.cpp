#include "FileInfo_Text.h"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <iomanip>

void FileInfo_Text::RetrieveInformation()
{
	char* fullPath = GetFullPath();
	mNbLines = 0;

	std::filesystem::path filepath(fullPath);

	if (!std::filesystem::exists(filepath)) {
		std::cerr << "Erreur. Le fichier n'existe pas\n";
		exit(1);
	}

	std::ifstream file(filepath);

	std::string currentLine;

	while (std::getline(file, currentLine)) {
		mNbLines++;
		currentLine.clear();
	}

	file.close(); if (!std::filesystem::exists(filepath)) {
		std::cerr << "Erreur. Le fichier n'existe pas\n";
		exit(1);
	}

	delete[] fullPath;
}

void FileInfo_Text::DisplayInformation()
{
	std::cout << "\t" << mFile << std::setw(40 - strlen(mFile)) << "" << mNbLines << "\tlignes";
}
