#pragma once

#include "Global.h"
#include "include\BaseClasses.h"
#include "include\Graphics.h"

namespace RogueEngine
{
	namespace Graphics
	{
		class Renderer
		{
		public:
			Renderer(GameObject* owner, MaterialList& materials);
			~Renderer();

			GameObject& Owner();
			MaterialList& Materials();

		private:
			GameObject& m_Owner;
			MaterialList m_Materials;
		};
	}
}