#pragma once
#include "FileInfo_Base.h"
#include <iostream>

class FileInfo_Binary : public FileInfo_Base {
	public:
		virtual void RetrieveInformation();
		virtual void DisplayInformation();
	protected:
		std::uintmax_t mNbBytes;
};