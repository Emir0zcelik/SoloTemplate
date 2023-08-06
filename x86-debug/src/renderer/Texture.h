#pragma once

#include <string>

#include <glad/glad.h>
#include <stb_image.h>

class Texture
{
private:
    unsigned int _rendererID;
    std::string _filePath;
    unsigned char* _localBuffer;
    int _width, _height, _bPP;

public:
    Texture(const std::string& path);
    ~Texture();

    void Bind(unsigned int slot = 0) const;
    void Unbind() const;

    inline int GetWidth() const { return _width; }
    inline int GetHeight() const { return _height; }
};