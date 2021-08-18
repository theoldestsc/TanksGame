#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "GameState.h"
#include <vector>

#include "TextureManager.h"
#include "Tank.h"
#include "Game.h"
#include "MenuButton.h"

class PlayState : public GameState 
{
    public:
        virtual void ProcessInput() override;
        virtual void Render() override;
        virtual void Update(float deltaTime) override;
        virtual bool onEnter() override;
        virtual bool onExit() override;
        virtual std::string getStateID() const override;
        ~PlayState();
    private:
        static const std::string playID;
        std::vector<GameObject*> m_gameObjects;
};

#endif
