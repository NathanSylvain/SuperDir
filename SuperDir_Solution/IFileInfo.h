#pragma once

class IFileInfo {
	public:
		virtual void Init(const char* aFolder, const char* aFile) = 0;
		virtual void RetrieveInformation() = 0;
		virtual void DisplayInformation() = 0;
};