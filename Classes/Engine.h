#pragma once

#include "Global.h"

namespace RogueEngine
{
	class Engine
	{
	public:
					Engine();
					~Engine();

		void		Run();

	private:
		string		m_ConfigPath = "master.cfg";
	};
}