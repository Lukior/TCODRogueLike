#pragma once

#include "Global.h"

namespace RogueEngine
{
	class GameObject
	{
	private:
		template<typename T>
		bool IsPresent()
		{
			for (Component*& c : m_Components)
			{
				if (dynamic_cast<T*>(c))
					return true;
			}
			return false;
		}

	public:
		GameObject(const string& myName);
		~GameObject();

		template<typename T>
		void AddComponent();

		template<typename T>
		void RemoveComponent();

		Math::Vector2&	Position();

		ComponentList&	Components();
		ChildrenList&	Children();
		string&			Name();
		GameObject*&	Parent();

		friend ostream& operator<< (ostream& os, GameObject& go);

	private:
		string					m_Name;

		Math::Vector2			m_Position;

		ComponentList			m_Components;
		ChildrenList			m_Children;
		GameObject*				m_Parent;
	};

	template<typename T>
	void GameObject::AddComponent()
	{
		if (IsPresent<T>())
			return;
		T* theCompo = new T;
		theCompo->SetOwner(this);
		m_Components.push_back(theCompo);
		theCompo->Start();
	}

	template<typename T>
	void GameObject::RemoveComponent()
	{
		for (Component*& c : m_Components)
		{
			if (dynamic_cast<T*>(c))
			{
				auto it = find(m_Components.begin(), m_Components.end(), c);

				c->Destroy();
				delete c;
				m_Components.erase(it);
				return;
			}
		}
	}
}
