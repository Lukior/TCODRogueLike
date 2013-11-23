#include "Material.h"

namespace RogueEngine
{
	namespace Graphics
	{
		Material::Material(
			const string& name,
			MatCallback callback)
			: m_Callback(callback),
			m_Name(name)
		{
			RenderKernel::RegisterMaterial(m_Name, this);
		}

		Material::~Material()
		{
			RenderKernel::UnregisterMaterial(m_Name);
		}

		const MatCallback& Material::Callback() const
		{
			return m_Callback;
		}

		const string& Material::Name() const
		{
			return m_Name;
		}

		const RendererList& Material::RegisteredRenderers() const
		{
			return m_Renderers;
		}

		void Material::RegisterRenderer(Renderer* renderer)
		{
			auto it = find(m_Renderers.begin(), m_Renderers.end(), renderer);
			if (it == m_Renderers.end())
				m_Renderers.push_back(renderer);
			else
			{
				StringBuilder msg;
				msg << "Renderer of " << renderer->Owner().Name() << " already registered in material " << m_Name;

				OUTPUT_MSG("Warning", msg.str());
			}
		}

		void Material::UnregisterRenderer(Renderer* renderer)
		{
			auto it = find(m_Renderers.begin(), m_Renderers.end(), renderer);
			if (it != m_Renderers.end())
			{
				m_Renderers.erase(it);
			}
			else
			{
				StringBuilder msg;
				msg << "Renderer of " << renderer->Owner().Name() << " has already been unregistered or was unknown to material " << m_Name;

				OUTPUT_MSG("Warning", msg.str());
			}
		}
	}
}