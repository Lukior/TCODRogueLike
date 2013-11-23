#include "Global.h"

namespace RogueEngine
{
	Component::Component()
	{
		ComponentKernel::Register(this);
	}

	Component::~Component()
	{
		ComponentKernel::Unregister(this);
	}

	void Component::Start()
	{
	}

	void Component::Update()
	{
	}

	void Component::LateUpdate()
	{
	}

	GameObject& Component::Owner()
	{
		return *m_Owner;
	}

	void Component::SetOwner(GameObject* theOwner)
	{
		m_Owner = theOwner;
	}
}
