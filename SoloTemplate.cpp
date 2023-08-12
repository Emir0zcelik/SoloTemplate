#include "SoloTemplate.h"

int main()
{
    Window windowObj;
    
    GLFWwindow* window = windowObj.InitWindow(1000 , 750, "Solo Renderer");
    
    Renderer renderer;

    ImGui::CreateContext();
    ImGui_ImplGlfwGL3_Init(window, true);
    ImGui::StyleColorsDark();

    test::TestMainMenu* mainMenu = new test::TestMainMenu;

    mainMenu->SetWidth(1000);
    mainMenu->SetHeight(750);

    test::TestSampleScene* sampleScene = new test::TestSampleScene;

    while (!glfwWindowShouldClose(window))
    {
        renderer.Clear();

        windowObj.processInput(window);

        ImGui_ImplGlfwGL3_NewFrame();
        
        
        if (mainMenu->GetIsMainMenu())
        {
            mainMenu->OnUpdate(0.0f);
            mainMenu->OnRender();
            mainMenu->OnImGuiRender();
        }

        else
        {
            if (!sampleScene->GetIsSampleScene())
                mainMenu->SetIsMainMenu(true);

            sampleScene->OnUpdate(0.0f);
            sampleScene->OnRender();
            sampleScene->OnImGuiRender();
        }
        

        if (mainMenu->GetIsExit())
        {
            return 0;
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
