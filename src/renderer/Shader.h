#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>

#include <glad/glad.h>
#include <glm/glm.hpp>


struct ShaderProgramSource {

	std::string VertexSource;
	std::string FragmentSource;
};

class Shader
{
private:
	unsigned int _rendererId;
	std::string _filePath;
	std::unordered_map<std::string, int> _uniformLocationCache;
public:

	Shader(const std::string filepath);

	~Shader();

	void Bind() const;

	void Unbind() const;

	//Set Uniforms

private:
	ShaderProgramSource ParseShader(const std::string& filepath);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	unsigned int GetUniformLocation(const std::string& name);
};
