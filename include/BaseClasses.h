#pragma once

#include "Global.h"

namespace RogueEngine
{
	class GameObject;
	class Component;

	typedef list<Component*> ComponentList;
	typedef list<GameObject*> ChildrenList;
}

#include "Classes\GameObject.h"
#include "Classes\Component.h"
