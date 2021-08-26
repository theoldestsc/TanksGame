//#pragma once
#ifndef GAME_H
#define GAME_H
#include <SDL.h>
#include <set>
#include <memory>
#include "DataStructures.h"
#include "Bullet.h"
#include "VideoManager.h"

class GameStateMachine;
 

class Game final
{
    public:       
        bool Initialize();
        void RunLoop();
        void ShutDown();
        void Quit(){mIsRunning = false;}
        SDL_Renderer* GetRenderer() const;
        std::unique_ptr<GameStateMachine>& getStateMachine();
        static std::unique_ptr<Game>& Instance();
        ~Game();
        
    private:
        void ProcessInput();
        void UpdateGame();
        void GenerateOutput();

        std::unique_ptr<GameStateMachine> gameStateMachine;
        static std::unique_ptr<Game> gameInstance;
        bool mIsRunning;
        Uint32 mTicksCount;

        Game(Game &other) = delete;
        void operator=(const Game&) = delete;

    protected:
        Game();
        
};

#endif