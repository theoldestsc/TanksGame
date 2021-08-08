//#pragma once
#ifndef GAME_H
#define GAME_H
#define _USE_MATH_DEFINES
#include <SDL.h>
#include <set>
#include <SDL2/SDL_image.h>
#include "DataStructures.h"

#include "Tank.h"
#include "Bullet.h"



class Game
{
    public:
        
        bool initialize();
        void RunLoop();
        void ShutDown();
        SDL_Renderer* GetRenderer() const;
        static Game* Instance();
        Game(Game &other) = delete;
        void operator=(const Game&) = delete;
    private:
        void ProcessInput();
        void UpdateGame();
        void GenerateOutput();
        
        static Game* gameInstance;
        SDL_Window* mWindow;
        SDL_Renderer* mRenderer;
        bool mIsRunning;
        Uint32 mTicksCount;
        Tank* tankObj;
        

    protected:
        Game();
        
};

#endif