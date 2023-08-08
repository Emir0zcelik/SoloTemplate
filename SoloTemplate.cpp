#include "SoloTemplate.h"

int main()
{
    Window windowObj;
    
    GLFWwindow* window = windowObj.InitWindow(800, 600, "Solo Renderer");
    
    Renderer renderer;

    ImGui::CreateContext();
    ImGui_ImplGlfwGL3_Init(window, true);
    ImGui::StyleColorsDark();

    test::TestMainMenu* mainMenu = new test::TestMainMenu;

    mainMenu->SetWidth(800);
    mainMenu->SetHeight(600);

    test::TestSampleScene sampleScene;

    while (!glfwWindowShouldClose(window))
    {
        renderer.Clear();

        windowObj.processInput(window);

        ImGui_ImplGlfwGL3_NewFrame();
        
        mainMenu->OnUpdate(0.0f);
        mainMenu->OnRender();
        mainMenu->OnImGuiRender();

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
