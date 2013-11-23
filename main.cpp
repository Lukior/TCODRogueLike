#include "Global.h"
#include "include\BaseClasses.h"
#include "include\Graphics.h"

using namespace RogueEngine;

int main()
{
	auto clbk = [](Graphics::Renderer* rend)
	{
		TCODConsole::root->putCharEx(
			rend->Owner().Position().X(),
			rend->Owner().Position().Y(),
			'X',
			TCODColor::white,
			TCODColor::black);
	};

	Graphics::Material testmat("TestMaterial", clbk);

	GameObject root("root");

	MaterialList myList;
	myList.push_back(testmat.Name());

	root.Renderer() = new Graphics::Renderer(&root, myList);

	RenderKernel::Initialize(80, 80, "test", 60);
	while (!TCODConsole::isWindowClosed())
	{
		ComponentKernel::Update();
		ComponentKernel::LateUpdate();

		RenderKernel::Clear();
		RenderKernel::Render();
	}

	getchar();
	return 0;
}