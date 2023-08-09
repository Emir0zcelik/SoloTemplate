#pragma once

#include <string>

#include <direct.h>

class Folder
{
	private:
		char _buffer[1024];
		std::string _CWD;
	public:

		Folder();
		
		~Folder();

		inline std::string GetCWD() const { return _CWD; }

};