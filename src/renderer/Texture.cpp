#include "Texture.h"

Texture::Texture(const std::string& path)
	:_rendererID(0), _filePath(path), _localBuffer(nullptr), _width(0), _height(0), _bPP(0)
{
	stbi_set_flip_vertically_on_load(true);

	_localBuffer = stbi_load(path.c_str(), &_width, &_height, &_bPP, 4);

	glGenTextures(1, &_rendererID);
	glBindTexture(GL_TEXTURE_2D, _rendererID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _localBuffer);
	glBindTexture(GL_TEXTURE_2D, 0);

	if (_localBuffer)
		stbi_image_free(_localBuffer);
}

Texture::~Texture()
{
	glDeleteTextures(1, &_rendererID);
}

void Texture::Bind(unsigned int slot) const
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, _rendererID);
}

void Texture::Unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
