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

	using	MaterialMap		=	unordered_map	<string, Graphics::Material*>;
	using	MaterialList	=	vector			<string>;
	using	RendererMap		=	unordered_map	<Graphics::Renderer*, MaterialList>;
	using	RendererList	=	list			<Graphics::Renderer*>;
}

#include "Classes\Graphics\Material.h"
#include "Classes\Graphics\Renderer.h"
