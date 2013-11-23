#pragma once

#include "Global.h"

namespace RogueEngine
{
	namespace Graphics
	{
		class Renderer;
		class Material;

		typedef function<void(Renderer*)> MatCallback;
	}

	typedef unordered_map<string, Graphics::Material*> MaterialMap;
	typedef vector<string> MaterialList;
	typedef unordered_map<Graphics::Renderer*, MaterialList> RendererMap;
	typedef list<Graphics::Renderer*> RendererList;
}

#include "Classes\Graphics\Material.h"
#include "Classes\Graphics\Renderer.h"
