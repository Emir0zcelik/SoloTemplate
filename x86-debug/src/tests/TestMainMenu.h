#pragma once

#include "Test.h"

#include "../renderer/Renderer.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


#include <GLFW/glfw3.h>

#include "../tests/TestSampleScene.h"

namespace test {

	class TestMainMenu : public Test
	{
	private:
		Folder _folder;
		std::string _currentDir;

		float _color[4];
		float _positions[16];
		unsigned int _indices[6];

		VAO _va;
		VBO _vb;
		VBOLayout _layout;
		IBO _ib;
		Shader _shader;
		Renderer _renderer;
		Texture _soloLogo;

		glm::mat4 _proj;
		glm::mat4 _view;
		glm::mat4 _model;
		glm::mat4 _mvp;


		int _width, _height;

		bool _isMainMenu, _isExit;

	public:

		TestMainMenu();

		~TestMainMenu();

		void OnUpdate(float deltaTime) override;

		void OnRender() override;

		void OnImGuiRender() override;

		void SetWidth(int width);

		void SetHeight(int height);

		void SetIsMainMenu(bool isMainMenu);

		inline bool GetIsExit() { return _isExit; }

		inline bool GetIsMainMenu() { return _isMainMenu; }
	};

}