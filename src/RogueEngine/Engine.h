#pragma once

#include <vector>

#include "Scene.h"
#include "GameState.h"

using namespace std;

namespace RogueEngine
{
	class Engine
	{
	private:
		vector<Scene*> TheScenes;
		GameState &TheGameState;

	public:
		Engine();
		~Engine();
	};
}
