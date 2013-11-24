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

		if (InputKernel::IsPressed(TCOD_keycode_t::TCODK_RIGHT))
		{
			Owner().Position.x =
				MIN(Owner().Position.x + speed * TimeKernel::DeltaTime(), 79);
		}
		else if (InputKernel::IsPressed(TCOD_keycode_t::TCODK_LEFT))
		{
			Owner().Position.x =
				MAX(Owner().Position.x - speed * TimeKernel::DeltaTime(), 0);
		}
		if (InputKernel::IsPressed(TCOD_keycode_t::TCODK_UP))
		{
			Owner().Position.y =
				MAX(Owner().Position.y - speed * TimeKernel::DeltaTime(), 0);
		}
		else if (InputKernel::IsPressed(TCOD_keycode_t::TCODK_DOWN))
		{
			Owner().Position.y =
				MIN(Owner().Position.y + speed * TimeKernel::DeltaTime(), 79);
		}
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

	getchar();
	return 0;
}