#include "GameStateMachine.h"

void GameStateMachine::pushState(GameState *pState)
{
    gameStates.emplace_back(pState);
    gameStates.back()->onEnter();
}

void GameStateMachine::popState()
{
    if(!gameStates.empty())
    {
        if(gameStates.back()->onExit())
        {
            delete gameStates.back();
            gameStates.pop_back();
        }
    }
}

GameStateMachine::~GameStateMachine()
{
    for(auto gameState : gameStates)
    {
        delete gameState;
    }
    gameStates.clear();
}

void GameStateMachine::changeState(GameState *pState)
{
    if(!gameStates.empty())
    {
        if(gameStates.back()->getStateID() == pState->getStateID())
        {
            delete gameStates.back();
            gameStates.pop_back(); //TODO: Rewrite memmory management 
            //return; // do nothing
        }
        else if(gameStates.back()->onExit())
        {
            delete gameStates.back();
            gameStates.pop_back();
        }
    }
    this->pushState(pState);
}


