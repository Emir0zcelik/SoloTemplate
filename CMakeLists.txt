# CMakeList.txt : CMake project for SoloTemplate, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_TOOLCHAIN_FILE "C:/Dev/vcpkg/scripts/buildsystems/vcpkg.cmake")

project ("SoloTemplate")

find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(Stb REQUIRED)

add_executable(SoloTemplate "SoloTemplate.cpp" "SoloTemplate.h" "src/renderer/VAO.h" "src/renderer/VAO.cpp" "src/renderer/Shader.h" "src/renderer/Shader.cpp" "src/renderer/Renderer.h" "src/renderer/Renderer.cpp")

target_link_libraries(SoloTemplate PRIVATE glad::glad glfw glm::glm imgui::imgui ${Stb_INCLUDE_DIR}) 

# TODO: Add tests and install targets if needed.
