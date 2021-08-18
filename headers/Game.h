//#pragma once
#ifndef GAME_H
#define GAME_H
#define _USE_MATH_DEFINES
#include <SDL.h>
#include <set>
#include "DataStructures.h"


//#include "InputManager.h"
//#include "Tank.h"
#include "Bullet.h"
#include <memory>


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
        SDL_Window* mWindow;
        SDL_Renderer* mRenderer;
        bool mIsRunning;
        Uint32 mTicksCount;
        //std::unique_ptr<Tank> tankObj;
        Game(Game &other) = delete;
        void operator=(const Game&) = delete;

    protected:
        Game();
        
};

#endif