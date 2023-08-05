#pragma once

#include <direct.h>

#include <string>
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <stb_image.h>

#include <imgui.h>
#include "src/vendor/imgui/imgui_impl_glfw_gl3.h"

#include "src/window_handling/Window.h"

#include "src/renderer/VBO.h"
#include "src/renderer/VBOLayout.h"
#include "src/renderer/IBO.h"
#include "src/renderer/VAO.h"
#include "src/renderer/Shader.h"
#include "src/renderer/Renderer.h"
#include "src/renderer/Texture.h"
