#include "Game.h"


Game::Game():mWindow(nullptr),
            mRenderer(nullptr),
            mTicksCount(0),
            mIsRunning(true),
            tank_obj(nullptr)
            
{
    
}

bool Game::initialize()
{
    int sdlResult = SDL_Init(SDL_INIT_VIDEO);
    if(sdlResult != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    }
    mWindow = SDL_CreateWindow("TanksBattle", // Title
                                SDL_WINDOWPOS_UNDEFINED, // Top left x - coordinate of window
                                SDL_WINDOWPOS_UNDEFINED, // Top left y - coordinate of window
                                WIDTH, // Width
                                HEIGHT, // Height
                                0 // Flags
                                );
    if(!mWindow)
    {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return false;        
    }
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(!mRenderer)
    {
        SDL_Log("Failed to create render: %s", SDL_GetError());
        return false;        
    }    
    else
    {
        //Initialize PNG loading
        int imgFlags = IMG_INIT_PNG;
        if(!(IMG_Init(imgFlags)&imgFlags))
        {
            SDL_Log("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
            return false; 
        }
    }
    tank_obj = new Tank(mRenderer, Point<int>{5, 100});
    tank_obj->Load("../Sprites/tank.png");
    return true;
}

void Game::ShutDown()
{
    delete tank_obj;

    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
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
    SDL_Event event;
    //До тех пор пока есть события в очереди
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            mIsRunning = false;
            break;
        case SDL_KEYUP:
            
            break;
        default:
            break;
        }
    }        
    const Uint8* state = SDL_GetKeyboardState(NULL);
    tank_obj->setState(State::STOP);
    if(state[SDL_SCANCODE_ESCAPE])
        mIsRunning = false;
    else if(state[SDL_SCANCODE_W]){
        tank_obj->setState(State::MOVE);
        tank_obj->change_direction(Direction::UP);
    }
    else if(state[SDL_SCANCODE_S]){
        tank_obj->setState(State::MOVE);
        tank_obj->change_direction(Direction::DOWN);
    }
    else if(state[SDL_SCANCODE_D]){
        tank_obj->setState(State::MOVE);
        tank_obj->change_direction(Direction::RIGHT);
    }
    else if(state[SDL_SCANCODE_A]){
        tank_obj->setState(State::MOVE);
        tank_obj->change_direction(Direction::LEFT);
    }
    if(state[SDL_SCANCODE_SPACE])
    {
        /*TODO: Too slow, make virtual class GameObject 
                inherits Tank and Bullet, 
                load texture for bullet only once
         */
        tank_obj->Fire();
    }
}

void Game::UpdateGame()
{
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16));
    float deltaTime = ( SDL_GetTicks() - mTicksCount)/ 1000.0f;
    if(deltaTime > 0.05f)
        deltaTime = 0.05f;
    mTicksCount = SDL_GetTicks();
    tank_obj->update(deltaTime);
    
}

void Game::GenerateOutput()
{
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 255, 255);
    SDL_RenderClear(mRenderer);
    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
    
    tank_obj->Render();
   
    SDL_RenderPresent(mRenderer);     
}

SDL_Renderer* Game::GetRenderer() const 
{ 
    return mRenderer; 
}

