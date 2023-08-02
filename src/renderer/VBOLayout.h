#pragma once

#include <vector>
#include <glad/glad.h>

#define ASSERT(x) if(!(x)) __debugbreak();

struct VertexBufferElement {
	unsigned int type;
	unsigned int count;
	unsigned char normalized;

	static unsigned int GetSizeOfType(unsigned int type) {
		switch (type)
		{
		case GL_FLOAT:	return sizeof(float);
		case GL_UNSIGNED_INT:	return sizeof(unsigned int);
		case GL_UNSIGNED_BYTE:	return sizeof(unsigned char);
		}
		ASSERT(false);
		return 0;
	}

	class VertexBufferLayout {
	private:
		std::vector<VertexBufferElement> _elements;
		unsigned int _stride;
	public:

		VertexBufferLayout() :_stride(0) {}

		template<typename T>
		void Push(unsigned int count) {

			ASSERT(false);
		}

		template<>
		void Push<float>(unsigned int count) {

			_elements.push_back({ GL_FLOAT, count, GL_FALSE });
			_stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
		}

		template<>
		void Push<unsigned int>(unsigned int count) {

			_elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
			_stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
		}

		template<>
		void Push<unsigned char>(unsigned int count) {

			_elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
			_stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
		}

		inline const std::vector <VertexBufferElement> GetElements() const { return _elements; }
		inline unsigned int GetStride() const { return _stride; }
	};
};