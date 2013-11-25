#include "Engine.h"

namespace RogueEngine
{
	Engine::Engine()
	{}

	Engine::~Engine()
	{}

	void		Engine::Run()
	{
		RenderKernel::Initialize(80, 80, "test", 60);
		while (!TCODConsole::isWindowClosed())
		{
			TimeKernel::Update();
			InputKernel::Update();

			ComponentKernel::Update();
			ComponentKernel::LateUpdate();

			RenderKernel::Clear();
			RenderKernel::Render();
		}
	}
}