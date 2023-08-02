#include "SoloTemplate.h"

int main()
{
    Window windowObj;
    
    GLFWwindow* window = windowObj.InitWindow(800, 600, "Solo Renderer");

    while (!glfwWindowShouldClose(window))
    {
        windowObj.processInput(window);


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
