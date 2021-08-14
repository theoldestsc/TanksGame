#include "InputManager.h"

std::unique_ptr<InputManager> InputManager::inputManagerInstance = nullptr;

InputManager::InputManager()
{

}

std::unique_ptr<InputManager>& InputManager::Instance()
{
    if(!inputManagerInstance)
    {
        inputManagerInstance.reset(new InputManager());
    }
    return inputManagerInstance;
}

void InputManager::Update()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            Game::Instance()->Quit();
            break;
        case SDL_KEYUP:
            
            break;
        default:
            break;
        }
    }
    state = (Uint8*)SDL_GetKeyboardState(NULL);
}


bool InputManager::isKeyDown(SDL_Scancode key)
{
    if(state != 0)
    {
        if(state[key] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
    
}

void InputManager::Clean()
{
    
}

InputManager::~InputManager()
{

}