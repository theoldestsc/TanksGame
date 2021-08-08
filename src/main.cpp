#include <vector>
#include <iostream>
#include "Game.h"


int main(int argc, char *argv[])
{
    Game* gameInstance = Game::Instance();
    bool success = gameInstance->Initialize();
    if(success)
    {
        gameInstance->RunLoop();
    }
    gameInstance->ShutDown();
    delete gameInstance;
    return 0;
}