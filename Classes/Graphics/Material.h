#pragma once

#include "Global.h"
#include "include\Graphics.h"

namespace RogueEngine
{
	namespace Graphics
	{
		class Material
		{
		public:
			Material(const string& name, int ascii, TCODColor foreground, TCODColor background);
			~Material();

			int& Ascii();
			TCODColor& Foreground();
			TCODColor& Background();
			const string& Name() const;

			const RendererList& RegisteredRenderers() const;

			void RegisterRenderer(Renderer* renderer);
			void UnregisterRenderer(Renderer* renderer);

		private:
			TCODColor m_Foreground;
			TCODColor m_Background;
			int m_Ascii;

			string m_Name;

			RendererList m_Renderers;
		};
	}
}