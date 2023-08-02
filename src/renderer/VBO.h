#pragma once

#include <glad/glad.h>

class VBO
{
private:
	unsigned int _rendererId;
public:
	
	VBO(const void* data, unsigned int size);
	
	~VBO();

	void Bind() const;

	void UnBind() const;
};