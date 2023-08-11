#pragma once

#include "Test.h"

#include "../renderer/Renderer.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace test 
{
	class TestSampleScene : public Test
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

			bool _isSampleScene;
		public:

			TestSampleScene();

			~TestSampleScene();

			void OnUpdate(float deltaTime) override;

			void OnRender() override;

			void OnImGuiRender() override;

			inline bool GetIsSampleScene() { return _isSampleScene; }
	};
}