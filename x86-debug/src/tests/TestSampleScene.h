#pragma once

#include "Test.h"

#include "../renderer/VBO.h"
#include "../renderer/VBOLayout.h"
#include "../renderer/IBO.h"
#include "../renderer/VAO.h"
#include "../renderer/Shader.h"
#include "../renderer/Renderer.h"
#include "../renderer/Texture.h"
#include "../renderer/ShaderFolder.h"

namespace test {

	class TestSampleScene : public Test
	{
	private:
		ShaderFolder _folder;
		std::string _currentDir;

		float _color[4];
		float _positions[8];
		unsigned int _indices[6];

		VAO _va;
		VBO _vb;
		VBOLayout _layout;
		IBO _ib;
		Shader _shader;
		Renderer _renderer;
	public:

		TestSampleScene();

		~TestSampleScene();

		void OnUpdate(float deltaTime) override;

		void OnRender() override;

		void OnImGuiRender() override;

	};

}