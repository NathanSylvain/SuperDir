#pragma once
class IFileInfo
{

public:

    virtual void Init(const wchar_t* aFolder, char* aFile) = 0;

    virtual void RetrieveInformation() = 0;

    virtual void DisplayInformation() = 0;
};

