//#pragma once
#ifndef GAME_H
#define GAME_H
#include <SDL.h>
#include <vector>
#include <SDL2/SDL_image.h>
#include "DataStructures.h"

#include "Tank.h"
/*struct Bullet
{
    Vector2 mBallVel;
    Vector2 mBallPos;
};*/


class Game
{
    public:
        Game();
        bool initialize();
        void RunLoop();
        void ShutDown();
        SDL_Renderer* mRenderer;
    private:
        void ProcessInput();
        void UpdateGame();
        void GenerateOutput();
        SDL_Window* mWindow;


        bool mIsRunning;
        Uint32 mTicksCount;
        Tank* tank_obj;
};

#endif