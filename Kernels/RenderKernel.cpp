#include "RenderKernel.h"

namespace RogueEngine
{
	RenderKernel::RenderKernel()
	{}

	RenderKernel& RenderKernel::Get()
	{
		static RenderKernel me;
		return me;
	}

	void RenderKernel::Initialize(UINT height, UINT width, const string& title, int targetFPS)
	{
		TCODConsole::initRoot(width, height, title.data());
		RenderKernel& me = Get();

		me.m_Height = height;
		me.m_Width = width;
		me.m_Title = title;

		me.m_BackgroundClearColor = TCODColor::black;
		me.m_ForegroundClearColor = TCODColor::black;

		TCODConsole::root->setDefaultBackground(me.m_BackgroundClearColor);
		TCODConsole::root->setDefaultForeground(me.m_ForegroundClearColor);

		TCODSystem::setFps(targetFPS);
	}

	void RenderKernel::RegisterMaterial(const string& name, Graphics::Material* theMaterial)
	{
		RenderKernel& me = Get();

		if (me.m_Materials[name] == nullptr)
		{
			me.m_Materials[name] = theMaterial;
		}
		else
		{
			StringBuilder msg;
			msg << "Material " << theMaterial->Name() << " is already registered";

			OUTPUT_MSG("Warning", msg.str());
		}
	}

	void RenderKernel::UnregisterMaterial(const string& name)
	{
		RenderKernel& me = Get();
		if (me.m_Materials[name] != nullptr)
		{
			delete me.m_Materials[name];
			me.m_Materials.erase(name);
		}
		else
		{
			StringBuilder msg;
			msg << "Material " << name << " is already unregistered or was unknown to RenderKernel";

			OUTPUT_MSG("Warning", msg.str());
		}
	}

	void RenderKernel::RegisterRenderer(Graphics::Renderer* renderer, MaterialList& materials)
	{
		RenderKernel& me = Get();
		if (me.m_Renderers.find(renderer) == me.m_Renderers.end())
		{
			me.m_Renderers[renderer] = materials;
			for (const string& mat : materials)
			{
				me.m_Materials[mat]->RegisterRenderer(renderer);
			}
		}
		else
		{
			StringBuilder msg;
			msg << "The renderer of " << renderer->Owner().Name() << " is already registered";

			OUTPUT_MSG("Warning", msg.str());
		}
	}

	void RenderKernel::UnregisterRenderer(Graphics::Renderer* renderer)
	{
		RenderKernel& me = Get();
		if (me.m_Renderers.find(renderer) != me.m_Renderers.end())
		{
			for (const string& mat : renderer->Materials())
			{
				assert(me.m_Materials[mat] != nullptr);
				me.m_Materials[mat]->UnregisterRenderer(renderer);
			}
			me.m_Renderers.erase(renderer);
		}
	}

	void RenderKernel::Clear()
	{
		TCODConsole::root->clear();
	}

	void RenderKernel::Render()
	{
		RenderKernel& me = Get();
		for (auto matPair : me.m_Materials)
		{
			Graphics::Material* theMat = matPair.second;
			for (Graphics::Renderer* rend : theMat->RegisteredRenderers())
			{
				theMat->Callback()(rend);
			}
		}
		TCODConsole::flush();
	}

	TCODColor& RenderKernel::BackgroundClearColor()
	{
		return Get().m_BackgroundClearColor;
	}

	TCODColor& RenderKernel::ForegroundClearColor()
	{
		return Get().m_ForegroundClearColor;
	}
}