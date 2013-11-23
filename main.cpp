#include "Global.h"

using namespace RogueEngine;

int main()
{
	while (!TCODConsole::isWindowClosed())
	{
		ComponentKernel::Update();
		ComponentKernel::LateUpdate();

		RenderKernel::Clear();
		RenderKernel::Render();
	}
	return 0;
}