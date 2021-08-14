#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "SDL.h"
#include <memory>
#include "Game.h"
#include <SDL.h>

class InputManager
{
    public:
        static std::unique_ptr<InputManager>& Instance();
        void Update();
        void Clean();
        bool isKeyDown(SDL_Scancode key);
        ~InputManager();
    private:
        InputManager();
        Uint8* state;
        static std::unique_ptr<InputManager> inputManagerInstance;
};
#endif
