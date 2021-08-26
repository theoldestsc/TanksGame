#include "Game.h"
#include "GameStateMachine.h"


std::unique_ptr<Game> Game::gameInstance = nullptr;

Game::Game():mIsRunning(true),
             mTicksCount(0)
{
    
}

std::unique_ptr<Game>& Game::Instance()
{
    if(!gameInstance)
    {
        gameInstance.reset(new Game);
        return gameInstance;
    }
    return gameInstance;
}

bool Game::Initialize()
{
    //TODO: LOG output through all game in debug only
    int sdlResult = SDL_Init(SDL_INIT_VIDEO);
    bool ret;

    if(sdlResult != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    }
    ret = VideoManager::Instance()->Initialize();
    if(!ret)
        return false;
    int imgFlags = IMG_INIT_PNG;
    /*TODO: I think this should place in Texture Manager*/
    if(!(IMG_Init(imgFlags)&imgFlags))
    {
        SDL_Log("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return false; 
    }
 
    gameStateMachine = std::make_unique<GameStateMachine>();
    
    return true;
}

void Game::ShutDown()
{
    /* TODO:Because order is important, rethink this */
    VideoManager::Instance().reset();
    IMG_Quit();
    SDL_Quit();
}


void Game::RunLoop()
{
    while(mIsRunning)
    {
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}

void Game::ProcessInput()
{
    InputManager::Instance()->Update();
    gameStateMachine->ProcessInput();  
}

void Game::UpdateGame()
{
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16));
    float deltaTime = ( SDL_GetTicks() - mTicksCount)/ 1000.0f;
    if(deltaTime > 0.05f)
        deltaTime = 0.05f;
    mTicksCount = SDL_GetTicks();
    gameStateMachine->Update(deltaTime);
}

void Game::GenerateOutput()
{
    SDL_SetRenderDrawColor(GetRenderer(), 0, 0, 255, 255);
    SDL_RenderClear(GetRenderer());
    SDL_SetRenderDrawColor(GetRenderer(), 255, 255, 255, 255);
    gameStateMachine->Render();
    SDL_RenderPresent(GetRenderer());  
}

SDL_Renderer* Game::GetRenderer() const 
{ 
    return VideoManager::Instance()->GetRenderer(); 
}

std::unique_ptr<GameStateMachine>& Game::getStateMachine()
{
    return gameStateMachine;
}

Game::~Game()
{

}