#pragma once

#define WIN32_LEAN_AND_MEAN

#include <list>
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <assert.h>

#include <windows.h>

#include "include\TCOD\libtcod.hpp"

using namespace std;

namespace RogueEngine
{
/*** Kernels  ***************************/
	class ComponentKernel;
	class RenderKernel;

/*** Base Objects ***********************/
	class Component;
	class GameObject;

	namespace Graphics
	{
		class Renderer;
		class Material;
	}

/*** Math (We may as well indulge in bestiality) ***/
	namespace Math
	{
		class Vector2;
	}

/*** Typedefs ***************************/
	typedef list<Component*> ComponentList;
	typedef list<GameObject*> ChildrenList;
	typedef unordered_map<string, Graphics::Material*> MaterialMap;
	typedef vector<string> MaterialList;
	typedef unordered_map<Graphics::Renderer*, MaterialList> RendererMap;
	typedef list<Graphics::Renderer*> RendererList;

	typedef stringstream StringBuilder;
}

#include "Classes\Math\Vector2.h"
#include "Classes\Component.h"
#include "Classes\GameObject.h"
#include "Classes\Graphics\Material.h"
#include "Classes\Graphics\Renderer.h"

#include "Systems\ComponentKernel.h"
#include "Systems\RenderKernel.h"

#define OUTPUT_MSG(level, msg) cout << level << " : " << msg << endl;