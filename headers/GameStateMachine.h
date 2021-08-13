#ifndef GAME_STATE_MACHIENE_H
#define GAME_STATE_MACHIENE_H

#include "GameState.h"
#include <vector>

class GameStateMachine final
{
    public:
        void pushState(GameState* pState);
        void changeState(GameState* pState);
        void popState();
        ~GameStateMachine();
    private:
        std::vector<GameState*> gameStates;

};

#endif