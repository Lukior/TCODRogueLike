#pragma once

namespace RogueEngine
{
	class GameState
	{
	private:
		static GameState *instance;

		GameState();
		virtual ~GameState();

	public:
		static GameState &Instance();
	};
}
