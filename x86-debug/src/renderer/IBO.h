#pragma once

#include <glad/glad.h>

class IBO
{
private:
	unsigned int _rendererId;
	unsigned int _count;
public:
	
	IBO(const unsigned int* data, unsigned int count);

	~IBO();

	void Bind() const;

	void Unbind() const;

	inline unsigned int GetCount() const { return _count; }
};