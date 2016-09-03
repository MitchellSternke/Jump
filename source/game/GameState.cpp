#include "GameState.hpp"
#include "GameStateManager.hpp"

GameState::GameState() :
    gameStateManager(nullptr)
{
}

void GameState::popState()
{
    gameStateManager->popState();
}

void GameState::pushState(GameState* state)
{
    gameStateManager->pushState(state);
}
