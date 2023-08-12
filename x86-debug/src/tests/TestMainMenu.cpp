#include "TestMainMenu.h"

test::TestMainMenu::TestMainMenu()
	:_color { 0.2f, 0.3f, 0.7f, 1.0f  },

	_positions{
	    300.0f, 400.0f, 0.0f, 0.0f, // Down Left Corner
		300.0f, 600.0f, 0.0f, 1.0f, // Up Left Corner
		700.0f, 400.0f, 1.0f, 0.0f, // Down Right Corner
		700.0f, 600.0f, 1.0f, 1.0f, // Up Right Corner
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
	_height(0),
	_isMainMenu(true),
	_isExit(false),

	_proj(glm::ortho(0.0f, 1000.0f, 0.0f, 750.0f, -1.0f, 1.0f)),
	_view(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))),
	_model(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))),
	_mvp(_proj* _view* _model)
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


	glm::mat4 trans = glm::mat3(1.0f);
	trans = glm::translate(trans, glm::vec3(0.0f, 0.0f, 0.0f));
	trans = glm::scale(trans, glm::vec3(0.75f, 0.75f, 0.75f));
	trans = glm::rotate(trans, (float)glfwGetTime() / 2, glm::vec3(0.0f, 1.0f, 0.0f));

	_shader.SetUniformMat4f("u_Transform", trans);
	_shader.SetUniformMat4f("u_MVP", _mvp);

	_soloLogo.Bind();
	_shader.SetUniform1i("u_Texture", 0);
	glViewport(0, 0, 1000, 750);
	_renderer.Draw(_va, _ib, _shader);
}

void test::TestMainMenu::OnImGuiRender()
{
	ImGuiWindowFlags window_flags = 0;
	window_flags |= ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar;

	ImGui::SetNextWindowPos(ImVec2(0.0, 0.0));
	ImGui::SetNextWindowSize(ImVec2(_width, _height));

	ImGui::Begin("Main Menu", nullptr, window_flags);

	ImGui::SetCursorPos(ImVec2(920.0, 0.0));
	ImGui::Text("(%.1f FPS)", ImGui::GetIO().Framerate);

	ImGui::SetCursorPos(ImVec2(300.0, 500.0));
	if (ImGui::Button("Scene", ImVec2(100, 100)))
	{
		_isMainMenu = false;	
	}

	ImGui::SameLine();
	ImGui::SetCursorPos(ImVec2(600.0, 500.0));
	if (ImGui::Button("Exit", ImVec2(100, 100)))
	{
		_isExit = true;
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

void test::TestMainMenu::SetIsMainMenu(bool isMainMenu)
{
	_isMainMenu = isMainMenu;
}
