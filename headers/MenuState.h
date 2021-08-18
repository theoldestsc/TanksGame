#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "GameState.h"
#include <vector>

#include "TextureManager.h"
#include "Game.h"
#include "GameStateMachine.h"

class MenuButton;
class GameObject;

class MenuState : public GameState
{
    public:
        virtual void ProcessInput() override;
        virtual void Render() override;
        virtual void Update(float deltatime) override;
        virtual bool onEnter() override;
        virtual bool onExit() override;
        virtual std::string getStateID() const override;
        virtual ~MenuState();

    private:
        static const std::string menuID;
        std::vector<GameObject*> m_gameObjects;
        /*TODO:Create a vector of callbacks 
               and initialize it. Use generic std::function
        */
        static void s_menuToPlay(const MenuButton& button);
        static void s_exitFromMenu(const MenuButton& button);
        

};

#endif