#include "TestMainMenu.h"

test::TestMainMenu::TestMainMenu()
	:_color { 0.2f, 0.3f, 0.7f, 1.0f  },

	_positions{
	   -0.5f, -0.5f, 0.0f, 0.0f,
	   -0.5f,  0.5f, 0.0f, 1.0f,
		0.5f, -0.5f, 1.0f, 0.0f,
		0.5f,  0.5f, 1.0f, 1.0f,
	},

	_indices{
		0, 1, 2,
		1, 3, 2
	},

	_currentDir(_folder.GetCWD()),
	_va(),
	_vb(_positions, 4 * 4 * sizeof(float)),
	_ib(_indices, 6),
	_layout(),
	_shader(_currentDir + "/src/shaders/MainMenu.shader"),
	_renderer(),
	_soloLogo(_currentDir + "/res/imgs/Solo_Logo.png"),
	_width(0),
	_height(0)
{

	_layout.Push<float>(2);
	_layout.Push<float>(2);
	_va.AddBuffer(_vb, _layout);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

test::TestMainMenu::~TestMainMenu()
{
	_shader.Unbind();
}

void test::TestMainMenu::OnUpdate(float deltaTime)
{

}

void test::TestMainMenu::OnRender()
{
	_renderer.Clear();

	_soloLogo.Bind();
	_shader.SetUniform1i("u_Texture", 0);
	_renderer.Draw(_va, _ib, _shader);
}

void test::TestMainMenu::OnImGuiRender()
{
	ImGuiWindowFlags window_flags = 0;
	window_flags |= ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar;

	ImGui::SetNextWindowPos(ImVec2(0.0, 0.0));
	ImGui::SetNextWindowSize(ImVec2(_width, _height));

	ImGui::Begin("Main Menu", nullptr, window_flags);

	ImGui::SetCursorPos(ImVec2(720, 0.0));
	ImGui::Text("(%.1f FPS)", ImGui::GetIO().Framerate);

	ImGui::SetCursorPos(ImVec2(200.0, 350.0));
	if (ImGui::Button("Scene", ImVec2(100, 100)))
	{
		std::cout << "Main scene enter" << std::endl;
	}

	ImGui::SameLine();
	ImGui::SetCursorPos(ImVec2(500.0, 350.0));
	if (ImGui::Button("Exit", ImVec2(100, 100)))
	{
		std::cout << "BYE!" << std::endl;
	}


	ImGui::End();
}

void test::TestMainMenu::SetWidth(int width)
{
	_width = width;
}

void test::TestMainMenu::SetHeight(int height)
{
	_height = height;
}


