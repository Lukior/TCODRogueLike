#include "ComponentKernel.h"

namespace RogueEngine
{
	ComponentKernel& ComponentKernel::Self()
	{
		static ComponentKernel self;
		return self;
	}

	ComponentKernel::ComponentKernel()
	{
	}

	ComponentKernel::~ComponentKernel()
	{
		for (Component*& c : m_ManagedComponents)
		{
			delete c;
		}
		m_ManagedComponents.clear();
	}

	void ComponentKernel::Register(Component* theCompo)
	{
		auto& comps = Self().m_ManagedComponents;
		auto it = find(comps.begin(), comps.end(), theCompo);

		if (it == comps.end())
			comps.push_back(theCompo);
	}

	void ComponentKernel::Unregister(Component* theCompo)
	{
		auto& comps = Self().m_ManagedComponents;
		auto it = find(comps.begin(), comps.end(), theCompo);
		
		if (it != comps.end())
			comps.erase(it);
	}

	void ComponentKernel::Update()
	{
		auto& comps = Self().m_ManagedComponents;

		for (Component*& c : Self().m_ManagedComponents)
			c->Update();
	}

	void ComponentKernel::LateUpdate()
	{
		auto& comps = Self().m_ManagedComponents;

		for (Component*& c : Self().m_ManagedComponents)
			c->LateUpdate();
	}
}