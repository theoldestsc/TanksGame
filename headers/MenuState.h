#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "GameState.h"
#include <vector>

#include "TextureManager.h"
#include "Game.h"
#include "MenuButton.h"

class MenuState : public GameState
{
    public:
        virtual void Update();
        virtual void Render();
        virtual bool onEnter() override;
        virtual bool onExit() override;
        virtual std::string getStateID() const override;
    private:
        static const std::string menuID;
        std::vector<GameObject*> m_gameObjects;

};

#endif