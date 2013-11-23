#pragma once

#include "Global.h"

namespace RogueEngine
{
	class Component
	{
	public:
		Component();
		virtual ~Component();

		virtual void Start() = 0;

		virtual void Update();
		virtual void LateUpdate();

		virtual void Destroy() = 0;

		GameObject& Owner();

	private:
		friend GameObject;

		void SetOwner(GameObject* theOwner);

		GameObject* m_Owner;
	};
}
