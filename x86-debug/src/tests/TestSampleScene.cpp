#include "TestSampleScene.h"

namespace test
{
	test::TestSampleScene::TestSampleScene()
		:_color { 0.2f, 0.3f, 0.7f, 1.0f  },

		 _positions{
			 300.0f, 200.0f, 0.0f, 0.0f, // Down Left Corner
			 400.0f, 400.0f, 0.0f, 1.0f, // Up Left Corner
			 500.0f, 200.0f, 1.0f, 0.0f, // Down Right Corner
										 // Up Right Corner
	     },

		 _indices{
			 0, 1, 2,
		 },

		 _currentDir(_folder.GetCWD()),

		 _va(),
		 _vb(_positions, 4 * 4 * sizeof(float)),
		 _ib(_indices, 6),
		 _layout(),

		 _shader(_currentDir + "/src/shaders/Shader.shader"),
		 _renderer(),
		 _soloLogo(_currentDir + "/res/imgs/Solo_Logo.png"),
		_isSampleScene(true),
		_proj(glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, -1.f, 1.f)),
		_view(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))),
		_model(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))),
		_mvp(_proj * _view * _model)
	{

		_layout.Push<float>(2);
		_layout.Push<float>(2);
		_va.AddBuffer(_vb, _layout);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	}

	test::TestSampleScene::~TestSampleScene()
	{
		_shader.Unbind();
	}

	void test::TestSampleScene::OnUpdate(float deltaTime)
	{
	}

	void test::TestSampleScene::OnRender()
	{
		_renderer.Clear();

		_shader.SetUniformMat4f("u_MVP", _mvp);
		_shader.SetUniform4f("u_Color", 0.2f, 0.3f, 0.7f, 1.0f);
		_soloLogo.Bind();
		_shader.SetUniform1i("u_Texture", 0);
		glViewport(0, 150, 800, 600);
		_renderer.Draw(_va, _ib, _shader);
	}

	void test::TestSampleScene::OnImGuiRender()
	{
		ImGuiWindowFlags window_flags_scene = 0;
		window_flags_scene |= ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar;

		ImGuiWindowFlags window_flags_properties = 0;
		window_flags_properties |= ImGuiWindowFlags_NoResize;


		ImGui::SetNextWindowPos(ImVec2(0.0, 0.0));
		ImGui::SetNextWindowSize(ImVec2(1000, 750));

		{
			ImGui::Begin("Sample Scene", nullptr, window_flags_scene);

			_isSampleScene = true;

			ImGui::SetCursorPos(ImVec2(720.0, 0.0));
			ImGui::Text("(%.1f FPS)", ImGui::GetIO().Framerate);
			{
				ImGui::SetNextWindowSize(ImVec2(200, 750));
				ImGui::SetNextWindowPos(ImVec2(800.0, 0.0));
				ImGui::Begin("Properties", nullptr, window_flags_properties);

				if (ImGui::Button("Exit to Main Menu", ImVec2(130, 30)))
				{
					_isSampleScene = false;
				}

				ImGui::End();
			}

			{
				ImGui::SetNextWindowSize(ImVec2(800, 150));
				ImGui::SetNextWindowPos(ImVec2(1.0, 600.0));
				ImGui::Begin("Output", nullptr, window_flags_properties);


				ImGui::End();
			}


			ImGui::End();
		}



	}
}


