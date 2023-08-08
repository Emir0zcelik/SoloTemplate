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
	"x86-debug/src/renderer/VBO.cpp" "x86-debug/src/renderer/VBO.h"
	"x86-debug/src/renderer/IBO.cpp" "x86-debug/src/renderer/IBO.h"
	"x86-debug/src/renderer/VBOLayout.h"
	"x86-debug/src/renderer/VAO.cpp" "x86-debug/src/renderer/VAO.h"
	"x86-debug/src/renderer/Shader.cpp" "x86-debug/src/renderer/Shader.h"
	"x86-debug/src/renderer/Texture.cpp" "x86-debug/src/renderer/Texture.h"
	"x86-debug/src/renderer/Renderer.cpp" "x86-debug/src/renderer/Renderer.h"
	"x86-debug/src/window_handling/Window.cpp" "x86-debug/src/window_handling/Window.h"
	"x86-debug/src/renderer/Folder.h" "x86-debug/src/renderer/Folder.cpp"
	"x86-debug/src/vendor/imgui/imgui_impl_glfw_gl3.cpp" "x86-debug/src/vendor/imgui/imgui_impl_glfw_gl3.h"
	"x86-debug/src/vendor/stb/stb_image.cpp"
	"x86-debug/src/shaders/Shader.shader" "x86-debug/src/shaders/MainMenu.shader"
    "x86-debug/src/tests/Test.h" "x86-debug/src/tests/Test.cpp"
	"x86-debug/src/tests/TestSampleScene.h" "x86-debug/src/tests/TestSampleScene.cpp"
	"x86-debug/src/tests/TestMainMenu.h" "x86-debug/src/tests/TestMainMenu.cpp")

target_link_libraries(SoloTemplate PRIVATE glad::glad glfw glm::glm imgui::imgui ${Stb_INCLUDE_DIR}) 
