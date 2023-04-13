#include <iostream>
#include "IFileInfo.h"
#include "Functions.h"

int main(int aCount, const char** aParams) {
	if (aCount != 2) {
		std::cout << "Erreur: Veuillez passer en paramètre un chemin de dossier\n";
		return 1;
	}

	IFileInfo** files = myFunctions::FindFiles(aParams[1]);

	if (files != nullptr) {

		myFunctions::RetrieveInformation(files);

		myFunctions::DisplayInformation(files);

		myFunctions::ReleaseMemory(files);

		delete[] files;

	} else { 
		printf("Une erreur est survenue\n");
		return 1;
	}

	return 0;
}