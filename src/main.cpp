#include <vector>
#include <iostream>
#include "Game.h"

/*TODO: Clean some useless 
        virtual from classes add 
        'final' for some classes.
        Clean include's tree
*/

/*TODO:Use smartpointers except new
       where we can
*/
int main()
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