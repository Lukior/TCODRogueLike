#include "Global.h"
#include "include\BaseClasses.h"
#include "include\Graphics.h"

using namespace RogueEngine;

int main()
{
	Graphics::Material testmat(
		"TestMaterial",
		[](Graphics::Renderer* rend)
		{
			TCODConsole::root->putCharEx(
				rend->Owner().Position().X(),
				rend->Owner().Position().Y(),
				'X',
				TCODColor::white,
				TCODColor::black);
		});

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