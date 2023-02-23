// SuperDir.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <assert.h>
#include "funtion.h"

int main(int aCount, char* aFile)
{
    assert(1 <= aCount);
    assert(NULL != aFile);
    if (2 > aCount)
    {
        std::cerr << "ERREUR UTILISATEUR  Vous devez donner un chemin\n";
        return 1;
    }
    else
    {
        Funtion::FindFiles(aFile);
    }
    

    
    std::cout << "Hello World!\n";
}

