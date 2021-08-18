#include "MenuButton.h"

MenuButton::MenuButton(const LoaderParams* pParams,  
                       void (*callback)(const MenuButton&),
                       std::string eID):
                       SDLGameObject(pParams), m_callback(callback),
                       press(false),
                       eventID(eID)
{
    if(eventID.empty())
        eventID = textureID;
    currentFrame = MOUSE_OUT;
}

void MenuButton::Update(float deltaTime)
{
    
}

void MenuButton::ProcessInput()
{
    Vector2D* pMousePos = InputManager::Instance()->getMousePosition();
    if(pMousePos->getX() < (position.getX() + width)
    && pMousePos->getX() > position.getX()
    && pMousePos->getY() < (position.getY() + height)
    && pMousePos->getY() > position.getY())
    {
        currentFrame = MOUSE_OVER;
        if(InputManager::Instance()->getMouseButtonState(mouse_buttons::LEFT_MB))
        {
            currentFrame = CLICKED;
            press = true;
        }
        else if(press && release)
        {
            press = false;
            release = false;
            m_callback(*this);
        }
        else if(!InputManager::Instance()->getMouseButtonState(LEFT_MB))
        {
            release = true;
        }
        
    }
    else
    {
        currentFrame = MOUSE_OUT;
    }
}

void MenuButton::Draw()
{
    SDLGameObject::Draw();
}

