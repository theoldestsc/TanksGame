#include "MenuButton.h"

MenuButton::MenuButton(const LoaderParams* pParams):
                       SDLGameObject(pParams)
{
    currentFrame = MOUSE_OUT;
}

void MenuButton::Update(float deltaTime)
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


void MenuButton::Clean()
{
    SDLGameObject::Clean();
}
