#include "VAO.h"

#include "VBOLayout.h"

VAO::VAO()
{
	glGenVertexArrays(1, &_rendererId);
}

VAO::~VAO()
{
	glDeleteVertexArrays(1, &_rendererId);
}

void VAO::AddBuffer(const VBO& vb, const VBOLayout& layout)
{
	Bind();
	vb.Bind();

	const auto& elements = layout.GetElements();
	unsigned int offset = 0;

	for (unsigned int i = 0; i < elements.size(); i++)
	{
		const auto& element = elements[i];
		
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*)offset);

		offset += element.count * VBOElement::GetSizeOfType(element.type);
	}
}

void VAO::Bind() const
{
	glBindVertexArray(_rendererId);
}

void VAO::Unbind() const
{
	glBindVertexArray(0);
}
