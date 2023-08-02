#pragma once

#include "VAO.h"
#include "IBO.h"
#include "Shader.h"

#include <glad/glad.h>
#include <glm/glm.hpp>

class Renderer
{
public:
	
	void Clear() const;

	void Draw(const VAO& va, const IBO& ib, const Shader& shader) const;
};