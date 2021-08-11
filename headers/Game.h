//#pragma once
#ifndef GAME_H
#define GAME_H
#define _USE_MATH_DEFINES
#include <SDL.h>
#include <set>
#include "DataStructures.h"
#include "PlayState.h"
#include "MenuState.h"
#include "GameStateMachine.h"
#include "Tank.h"
#include "Bullet.h"
#include <memory>




class Game
{
    public:       
        bool Initialize();
        void RunLoop();
        void ShutDown();
        SDL_Renderer* GetRenderer() const;
        static Game* Instance();
        Game(Game &other) = delete;
        void operator=(const Game&) = delete;
        ~Game();
        
    private:
        void ProcessInput();
        void UpdateGame();
        void GenerateOutput();

        GameStateMachine* gameStateMachine;
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