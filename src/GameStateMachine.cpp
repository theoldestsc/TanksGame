#include "GameStateMachine.h"


void GameStateMachine::setNextState(std::string id)
{
    //TODO:CHECK THIS IN DEBUG ONLY
    nextState = gameStates[id];
}

void GameStateMachine::ProcessInput()
{
   if(nextState)
   {
       if(currentState->onExit())
       {
           currentState = nextState;
           currentState->onEnter();
           nextState = nullptr;
       }
   }
   currentState->ProcessInput();
}

void GameStateMachine::Update(float deltaTime)
{
   currentState->Update(deltaTime);
}

void GameStateMachine::Render()
{
    currentState->Render();
}

GameStateMachine::GameStateMachine():nextState(nullptr)
{
    MenuState* menu = new MenuState();
    PlayState* play = new PlayState();

    gameStates["MENU"] = menu;
    gameStates["PLAY"] = play;

    currentState = menu;
    menu->onEnter();
}

GameStateMachine::~GameStateMachine()
{
    for(auto it = gameStates.begin(); it != gameStates.end();)
    {
        delete it->second;
        it = gameStates.erase(it);
    }
}