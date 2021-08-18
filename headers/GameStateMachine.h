#ifndef GAME_STATE_MACHIENE_H
#define GAME_STATE_MACHIENE_H

#include "GameState.h"
#include <map>
#include <string>
#include "MenuState.h"
#include "PlayState.h"

class GameStateMachine final
{
    public:
        GameStateMachine();
        void ProcessInput();
        void Render();
        void Update(float deltaTime);
        void setNextState(std::string stateId);
        ~GameStateMachine();
    private:
        std::map<std::string, GameState*> gameStates;
        GameState* currentState;
        GameState* nextState;
};

#endif