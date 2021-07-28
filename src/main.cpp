#include <vector>
#include <iostream>
#include "Game.h"

int main(int argc, char *argv[])
{
    Game game;
    bool success = game.initialize();
    if(success)
    {
        game.RunLoop();
    }
    game.ShutDown();
    return 0;
}