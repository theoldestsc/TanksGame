#ifndef MENUBUTTON_H
#define MENUBUTTON_H
#include "SDLGameObject.h"
#include "InputManager.h"
#include <string>

class MenuButton : public SDLGameObject
{
    public:
        MenuButton(const LoaderParams* pParams,  
                   void (*callback)(const MenuButton& button),
                   std::string eID = "");
        virtual void Draw() override;
        virtual void Update(float deltaTime) override;
        virtual void ProcessInput() override;
        std::string eventID;
    private:
        enum ButtonState
        {
            MOUSE_OUT = 0,
            MOUSE_OVER = 1,
            CLICKED = 2
        };
        void (*m_callback)(const MenuButton& button);
        bool press;
        bool release;
        


};


#endif