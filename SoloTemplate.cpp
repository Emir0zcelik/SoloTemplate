#include "SoloTemplate.h"

int main()
{

    char buffer[1024];

    std::string currentDir = getcwd(buffer, 1024);

    currentDir += ("/shaders/");

    Window windowObj;
    
    GLFWwindow* window = windowObj.InitWindow(800, 600, "Solo Renderer");


    float positions[] = {
    -0.5f, -0.5f,
    -0.5f,  0.5f,
     0.5f, -0.5f,
     0.5f,  0.5f,
    };

    unsigned int indices[] = {
        0, 1, 2,
        1, 3, 2
    };

    VAO va;

    VBO vb(positions, 4 * 2 * sizeof(float));
    IBO ib(indices, 6);

    VBOLayout layout;

    layout.Push<float>(2);

    va.AddBuffer(vb, layout);
    
    Shader shader(currentDir + "Shader.shader");

    shader.Bind();

    Renderer renderer;

    ImGui::CreateContext();
    ImGui_ImplGlfwGL3_Init(window, true);
    ImGui::StyleColorsDark();

    int width, height;
    ImGuiWindowFlags windowFlags = 0;
    windowFlags |= ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
    while (!glfwWindowShouldClose(window))
    {
        windowObj.processInput(window);

        renderer.Clear();

        ImGui_ImplGlfwGL3_NewFrame();

        shader.Bind();
        shader.SetUniform4f("u_Color", 0.0f, 0.333f, 0.667f, 1.0f);

        renderer.Draw(va, ib, shader);

        glfwGetWindowSize(window, &width, &height);
        {
            ImGui::SetNextWindowSize(ImVec2(width, height));
            ImGui::SetNextWindowPos(ImVec2(0, 0));
            ImGui::Begin("Scene View", nullptr, windowFlags);
   
            ImGui::End();
        }

        ImGui::Render();
        ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    ImGui_ImplGlfwGL3_Shutdown();
    ImGui::DestroyContext();
    glfwTerminate();
    return 0;
}
