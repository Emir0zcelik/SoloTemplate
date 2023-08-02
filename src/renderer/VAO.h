#pragma once

#include <glad/glad.h>

#include "VBO.h"

class VBOLayout;

class VAO
{
private:
	unsigned int _rendererId;
public:

	VAO();

	~VAO();

	void AddBuffer(const VBO& vb, const VBOLayout& layout);

	void Bind() const;

	void Unbind() const;
};