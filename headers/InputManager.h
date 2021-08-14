#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "SDL.h"
#include <memory>
#include "Game.h"
#include <SDL.h>
#include "Vector2D.h"
#include <vector>

//TODO: FIX All enums, use EnumClass
enum mouse_buttons
{
    LEFT_MB = 0,
    MIDDLE_MB = 1,
    RIGHT_MB = 2
};
    

class InputManager
{
    public:
        static std::unique_ptr<InputManager>& Instance();
        void Update();
        void Clean();
        bool isKeyDown(SDL_Scancode key);
        Vector2D* getMousePosition();
        bool getMouseButtonState(int buttonNumber);
        ~InputManager();
    private:
        InputManager(const InputManager&) = delete;
        InputManager& operator=(const InputManager&) = delete;
        InputManager();
        Uint8* state;
        Vector2D* m_mousePosition;
        std::vector<bool> m_mouseButtonStates;
        static std::unique_ptr<InputManager> inputManagerInstance;
};
#endif
