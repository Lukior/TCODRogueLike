#include "Global.h"
#include "include\BaseClasses.h"
#include "include\Graphics.h"

using namespace RogueEngine;

class Test : public Component
{
public:
	virtual void Start()
	{
		cout << "I am alive !" << endl;
	}

	virtual void Destroy()
	{
		cout << "And here I die..." << endl;
	}

	virtual void Update()
	{
		float speed = 10.0f;

		Owner().Position =
			Owner().Position
				+ (InputKernel::KeyboardAxis()
					* TimeKernel::DeltaTime()
					* speed);
	}
};

int main()
{
	auto clbk = [](Graphics::Renderer* rend)
	{
		TCODConsole::root->putCharEx(
			rend->Owner().Position.x,
			rend->Owner().Position.y,
			'X',
			TCODColor::white,
			TCODColor::black);
	};

	Graphics::Material testmat("TestMaterial", clbk);

	GameObject root("root");

	root.AddComponent<Test>();

	MaterialList myList;
	myList.push_back(testmat.Name());

	root.Renderer() = new Graphics::Renderer(&root, myList);

	Engine engine;

	engine.Run();

	getchar();
	return 0;
}