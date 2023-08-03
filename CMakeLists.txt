cmake_minimum_required (VERSION 3.8)

set(CMAKE_TOOLCHAIN_FILE "C:/Dev/vcpkg/scripts/buildsystems/vcpkg.cmake")

project ("SoloTemplate")

find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(Stb REQUIRED)

add_executable(SoloTemplate 
	"SoloTemplate.cpp" "SoloTemplate.h" 
	"src/renderer/VBO.cpp" "src/renderer/VBO.h"
	"src/renderer/IBO.cpp" "src/renderer/IBO.h"
	"src/renderer/VBOLayout.h"
	"src/renderer/VAO.cpp" "src/renderer/VAO.h"
	"src/renderer/Shader.cpp" "src/renderer/Shader.h"
	"src/renderer/Texture.cpp" "src/renderer/Texture.h"
	"src/renderer/Renderer.cpp" "src/renderer/Renderer.h"
	"src/window_handling/Window.cpp" "src/window_handling/Window.h" 
	"src/vendor/imgui/imgui_impl_glfw_gl3.cpp" "src/vendor/imgui/imgui_impl_glfw_gl3.h"
	"src/vendor/stb/stb_image.cpp"
	"src/shaders/Shader.shader"
)


target_link_libraries(SoloTemplate PRIVATE glad::glad glfw glm::glm imgui::imgui ${Stb_INCLUDE_DIR}) 
