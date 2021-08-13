#include <vector>
#include <iostream>
#include "Game.h"


int main(int argc, char *argv[])
{
    std::unique_ptr<Game>& gameInstance = Game::Instance();
    bool success = gameInstance->Initialize();
    if(success)
    {
        gameInstance->RunLoop();
    }
    gameInstance->ShutDown();
    return 0;
}