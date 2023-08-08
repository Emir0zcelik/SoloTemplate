#include "Folder.h"

#include <iostream>

Folder::Folder()
	: _CWD("")
{
	_CWD = getcwd(_buffer, 1024);
}

Folder::~Folder()
{
}

