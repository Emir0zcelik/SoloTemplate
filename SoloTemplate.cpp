#include "SoloTemplate.h"

int main()
{
    Window windowObj;
    
    GLFWwindow* window = windowObj.InitWindow(800, 600, "Solo Renderer");
    
    Renderer renderer;

    ImGui::CreateContext();
    ImGui_ImplGlfwGL3_Init(window, true);
    ImGui::StyleColorsDark();

    test::Test* currentTest = nullptr;
    test::TestMenu* menu = new test::TestMenu(currentTest);
    currentTest = menu;

    menu->RegisterTest<test::TestSampleScene>("Sample Scene");

    while (!glfwWindowShouldClose(window))
    {
        windowObj.processInput(window);

        renderer.Clear();

        ImGui_ImplGlfwGL3_NewFrame();
        
        if (currentTest)
        {
            currentTest->OnUpdate(0.0f);
            currentTest->OnRender();

            ImGui::Begin("Sample Scene");
            ImGui::Text("(%.1f FPS)", ImGui::GetIO().Framerate);

            if (currentTest != menu && ImGui::Button("<--"))
            {
                delete currentTest;
                currentTest = menu;

            }

            currentTest->OnImGuiRender();

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
