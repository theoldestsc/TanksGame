//#pragma once
#ifndef GAME_H
#define GAME_H
#define _USE_MATH_DEFINES
#include <SDL.h>
#include <vector>
#include <SDL2/SDL_image.h>
#include "DataStructures.h"
#include <cmath>


#include "Tank.h"
#include "Bullet.h"



class Game
{
    public:
        Game();
        bool initialize();
        void RunLoop();
        void ShutDown();
        SDL_Renderer* GetRenderer() const;
    private:
        void ProcessInput();
        void UpdateGame();
        void GenerateOutput();
        SDL_Window* mWindow;
        SDL_Renderer* mRenderer;
        bool mIsRunning;
        Uint32 mTicksCount;
        Tank* tank_obj;
        std::vector<Bullet*> vBullets;
        
};

#endif