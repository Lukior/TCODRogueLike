#include "GameObject.h"

namespace RogueEngine
{
#pragma region CTOR/DTOR

	GameObject::GameObject(
		const string& myName)
		: m_Name(myName),
		m_Parent(nullptr),
		m_Position(new Math::Vector2())
	{
	}

	GameObject::~GameObject()
	{
		delete m_Position;
		for (Component* c : m_Components)
			delete c;
		for (GameObject* go : m_Children)
			delete go;
	}

#pragma endregion

	Math::Vector2& GameObject::Position()
	{
		return *m_Position;
	}

	ComponentList& GameObject::Components()
	{
		return m_Components;
	}

	ChildrenList& GameObject::Children()
	{
		return m_Children;
	}

	string&	GameObject::Name()
	{
		return m_Name;
	}

	GameObject*& GameObject::Parent()
	{
		return m_Parent;
	}

	ostream& operator<< (ostream& os, GameObject& go)
	{
		static int deepness = 0;

		for (int i = 0; i < deepness; ++i)
			os << "\t";
		os << "Name is " << go.Name();
		if (go.Parent())
			os << ", father is " << go.Parent()->Name();
		os << endl;
		++deepness;
		for (GameObject* cgo : go.Children())
			os << *cgo;
		--deepness;

		return os;
	}
}