#pragma once

#include "Global.h"

namespace RogueEngine
{
	class ComponentKernel
	{
	private:
		static ComponentKernel& Self();

		explicit ComponentKernel();
		~ComponentKernel();

	public:
		static void Register(Component*);
		static void Unregister(Component* theCompo);

		static void Update();
		static void LateUpdate();

	private:
		ComponentList m_ManagedComponents;
	};
}
