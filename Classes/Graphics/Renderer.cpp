#include "Renderer.h"

namespace RogueEngine
{
	namespace Graphics
	{
		Renderer::Renderer(
			GameObject* owner,
			MaterialList& materials)
			: m_Owner(*owner),
			m_Materials(materials)
		{
			RenderKernel::RegisterRenderer(this, m_Materials);
		}

		Renderer::~Renderer()
		{
			RenderKernel::UnregisterRenderer(this);
		}

		GameObject& Renderer::Owner()
		{
			return m_Owner;
		}

		MaterialList& Renderer::Materials()
		{
			return m_Materials;
		}
	}
}