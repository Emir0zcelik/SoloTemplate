#pragma once

#include <string>

#include <direct.h>

class ShaderFolder
{
	private:
		char _buffer[1024];
		std::string _CWD;
	public:

		ShaderFolder();
		
		~ShaderFolder();

		inline std::string GetCWD() const { return _CWD; }
};