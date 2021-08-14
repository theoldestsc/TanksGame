#ifndef MENUBUTTON_H
#define MENUBUTTON_H
#include "SDLGameObject.h"
#include "InputManager.h"

class MenuButton : public SDLGameObject
{
    public:
        MenuButton(const LoaderParams* pParams);
        virtual void Draw() override;
        virtual void Update(float deltaTime) override;
        virtual void Clean();
    
    private:
        enum ButtonState
        {
            MOUSE_OUT = 0,
            MOUSE_OVER = 1,
            CLICKED = 2
        };

};


#endif