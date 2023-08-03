#include "VBO.h"

#include <iostream>

VBO::VBO(const void* data, unsigned int size)
{
	glGenBuffers(1, &_rendererId);
	glBindBuffer(GL_ARRAY_BUFFER, _rendererId);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

}

VBO::~VBO()
{
	glDeleteBuffers(1, &_rendererId);
}

void VBO::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, _rendererId);
}

void VBO::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
