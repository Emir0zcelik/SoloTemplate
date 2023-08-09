#pragma once

#include "Test.h"


#include "../renderer/VBO.h"
#include "../renderer/VBOLayout.h"
#include "../renderer/IBO.h"
#include "../renderer/VAO.h"
#include "../renderer/Shader.h"
#include "../renderer/Renderer.h"
#include "../renderer/Texture.h"
#include "../renderer/Folder.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


#include <GLFW/glfw3.h>

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


		int _width, _height;
	public:

		TestMainMenu();

		~TestMainMenu();

		void OnUpdate(float deltaTime) override;

		void OnRender() override;

		void OnImGuiRender() override;

		void SetWidth(int width);

		void SetHeight(int height);
	};

}