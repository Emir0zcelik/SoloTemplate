#pragma once

#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include <iostream>
#include <string>

#include <stb_image.h>

#include "../renderer/Folder.h"

class Window
{
public:

	Window();

	~Window();


	GLFWwindow* InitWindow(int width, int height, std::string windowName);

	void processInput(GLFWwindow* window);

};
