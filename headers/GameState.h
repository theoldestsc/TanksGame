#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <string>
#include <iostream>

class GameState
{
    public:
        virtual void ProcessInput() = 0;
        virtual void Render() = 0;
        virtual void Update(float deltaTime) = 0;
        virtual bool onEnter() = 0;
        virtual bool onExit() = 0;
        virtual std::string getStateID() const = 0;
        virtual ~GameState(){};
        
};
#endif