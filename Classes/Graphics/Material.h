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
			Material(const string& name, MatCallback callback);
			~Material();

			const string& Name() const;
			const MatCallback& Callback() const;

			const RendererList& RegisteredRenderers() const;

			void RegisterRenderer(Renderer* renderer);
			void UnregisterRenderer(Renderer* renderer);

		private:
			MatCallback m_Callback;

			string m_Name;

			RendererList m_Renderers;
		};
	}
}