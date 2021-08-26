#include "InputManager.h"

std::unique_ptr<InputManager> InputManager::inputManagerInstance = nullptr;

InputManager::InputManager()
{
    m_mousePosition = new Vector2D(0, 0);
    for(int i = 0; i < 3; i++)
    {
        m_mouseButtonStates.push_back(false);
    }

}

bool InputManager::getMouseButtonState(int buttonNumber)
{
    return m_mouseButtonStates[buttonNumber];
}


Vector2D* InputManager::getMousePosition()
{
    return m_mousePosition;
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
        case SDL_MOUSEMOTION:
            m_mousePosition->setX(event.motion.x);
            m_mousePosition->setY(event.motion.y);
            break;
        case SDL_MOUSEBUTTONDOWN:
            switch (event.button.button)
            {
            case SDL_BUTTON_LEFT:
                m_mouseButtonStates[LEFT_MB] = true;
                break;
            case SDL_BUTTON_MIDDLE:
                m_mouseButtonStates[MIDDLE_MB] = true;
                break;
            case SDL_BUTTON_RIGHT:
                m_mouseButtonStates[RIGHT_MB] = true;
                break;
            default:
                break;
            }
            break;
        case SDL_MOUSEBUTTONUP:
            switch (event.button.button)
            {
            case SDL_BUTTON_LEFT:
                m_mouseButtonStates[LEFT_MB] = false;
                break;
            case SDL_BUTTON_MIDDLE:
                m_mouseButtonStates[MIDDLE_MB] = false;
                break;
            case SDL_BUTTON_RIGHT:
                m_mouseButtonStates[RIGHT_MB] = false;
                break;

            default:
                break;
            }
            break;
        default:
            break;
        }
    }
  
    state = const_cast<Uint8*>(SDL_GetKeyboardState(NULL));
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
    delete m_mousePosition;
}