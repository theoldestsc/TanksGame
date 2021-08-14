#include "GameStateMachine.h"

void GameStateMachine::pushState(GameState *pState)
{
    gameStates.push_back(pState);
    gameStates.back()->onEnter();
    
}

GameState* GameStateMachine::getState()
{
    return gameStates.back();
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
    for(auto *gameState : gameStates)
    {
        gameState->onExit();
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
            std::cout << "changeState First if\n";
            delete gameStates.back();
            gameStates.pop_back(); //TODO: Rewrite memmory management 
            //return; // do nothing
        }
        else if(gameStates.back()->onExit())
        {
            std::cout << "changeState Second if\n";
            delete gameStates.back();
            gameStates.pop_back();
        }
    }
    std::cout << "push\n";
    this->pushState(pState);
}


