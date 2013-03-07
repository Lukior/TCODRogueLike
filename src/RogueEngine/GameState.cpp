#include "GameState.h"

RogueEngine::GameState *RogueEngine::GameState::instance = nullptr;

RogueEngine::GameState::GameState()
{

}

RogueEngine::GameState::~GameState()
{

}

RogueEngine::GameState &RogueEngine::GameState::Instance()
{
	if (!instance)
		instance = new RogueEngine::GameState();
	return *instance;
}
