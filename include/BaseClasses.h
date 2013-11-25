#pragma once

#include "Global.h"

namespace RogueEngine
{
	class GameObject;
	class Component;

	using ComponentList	=	list	<Component*>;
	using ChildrenList	=	list	<GameObject*>;
}

#include "Classes\GameObject.h"
#include "Classes\Component.h"
