#pragma once

#include "Global.h"
#include "include\Graphics.h"

namespace RogueEngine
{
	class RenderKernel
	{
	public:
		static void Initialize(UINT height, UINT width, const string& title);

		static void RegisterMaterial(const string& name, Graphics::Material* theMaterial);
		static void UnregisterMaterial(const string& name);

		static void RegisterRenderer(Graphics::Renderer* renderer, MaterialList& materials);
		static void UnregisterRenderer(Graphics::Renderer* renderer);

		static void Clear();
		static void Render();

		static TCODColor& BackgroundClearColor();
		static TCODColor& ForegroundClearColor();

	private:
		RenderKernel();
		static RenderKernel& Get();

		MaterialMap m_Materials;
		RendererMap m_Renderers;

		UINT m_Height;
		UINT m_Width;

		string m_Title;

		TCODColor m_BackgroundClearColor;
		TCODColor m_ForegroundClearColor;
	};
}