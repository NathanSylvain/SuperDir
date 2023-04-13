#pragma once
#include "FileInfo_Base.h"

class FileInfo_Text : public FileInfo_Base {
	public:
		virtual void RetrieveInformation();
		virtual void DisplayInformation();
	protected:
		int mNbLines = 0;
};