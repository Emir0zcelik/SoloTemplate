#include "ShaderFolder.h"

ShaderFolder::ShaderFolder()
	: _CWD("")
{
	_CWD = getcwd(_buffer, 1024);

	_CWD += ("/src/shaders/");
}

ShaderFolder::~ShaderFolder()
{
}

