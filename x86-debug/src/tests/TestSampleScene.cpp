#include "TestSampleScene.h"



namespace test
{
	test::TestSampleScene::TestSampleScene()
		:_color { 0.2f, 0.3f, 0.7f, 1.0f  },

		 _positions{
			-0.5f, -0.5f,
			-0.5f,  0.5f,
			 0.5f, -0.5f,
			 0.5f,  0.5f,
	     },

		 _indices{
			 0, 1, 2,
			 1, 3, 2
		 },

		 _currentDir(_folder.GetCWD()),
		 _va(),
		 _vb(_positions, 4 * 2 * sizeof(float)),
		 _ib(_indices, 6),
		 _layout(),
		 _shader(_currentDir + "Shader.shader"),
		 _renderer()
	{

		_layout.Push<float>(2);
		_va.AddBuffer(_vb, _layout);

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
		_shader.SetUniform4f("u_Color", 0.2f, 0.3f, 0.7f, 1.0f);
		_renderer.Draw(_va, _ib, _shader);
	}

	void test::TestSampleScene::OnImGuiRender()
	{

	}
}


