#include "Test.h"

namespace test
{
	TestMenu::TestMenu(Test*& currentTestPointer)
		:_currentTest(currentTestPointer)
	{

	}

	void TestMenu::OnImGuiRender()
	{
		for (auto& test : _tests)
		{
			if (ImGui::Button(test.first.c_str()))
			{
				_currentTest = test.second();
			}

		}
	}
}


