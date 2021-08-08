#include "Game.h"

Game* Game::gameInstance = nullptr;

Game::Game():mWindow(nullptr),
            mRenderer(nullptr),
            mTicksCount(0),
            mIsRunning(true),
            tankObj(nullptr)
            
{
    
}

Game* Game::Instance()
{
    if(!gameInstance)
    {
        gameInstance = new Game();
        return gameInstance;
    }
    else
        return gameInstance;
}

bool Game::Initialize()
{
    int sdlResult = SDL_Init(SDL_INIT_VIDEO);
    bool ret;

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
    TextureManager* textureManager = TextureManager::Instance();

    ret = textureManager->Load(std::string("../Sprites/tankScaled.png"),
                               std::string("Tank"),
                               mRenderer);
    if(!ret)
        return false;
    ret = textureManager->Load(std::string("../Sprites/Bullet_Red.png"), 
                               std::string("Bullet"), 
                               mRenderer);
    if(!ret)
        return false;
    LoaderParams pParams(5, 100,
                        52, 64, 
                        std::string("Tank"));

    tankObj = new Tank(&pParams);
    return true;
}

void Game::ShutDown()
{
    delete tankObj;

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

    tankObj->setState(State::STOP);
    if(state[SDL_SCANCODE_ESCAPE])
        mIsRunning = false;
    else if(state[SDL_SCANCODE_W]){
        tankObj->setState(State::MOVE);
        tankObj->change_direction(Direction::UP);
    }
    else if(state[SDL_SCANCODE_S]){
        tankObj->setState(State::MOVE);
        tankObj->change_direction(Direction::DOWN);
    }
    else if(state[SDL_SCANCODE_D]){
        tankObj->setState(State::MOVE);
        tankObj->change_direction(Direction::RIGHT);
    }
    else if(state[SDL_SCANCODE_A]){
        tankObj->setState(State::MOVE);
        tankObj->change_direction(Direction::LEFT);
    }
    if(state[SDL_SCANCODE_SPACE])
    {
        tankObj->Fire();
    }
}

void Game::UpdateGame()
{
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16));
    float deltaTime = ( SDL_GetTicks() - mTicksCount)/ 1000.0f;
    if(deltaTime > 0.05f)
        deltaTime = 0.05f;
    mTicksCount = SDL_GetTicks();
    tankObj->Update(deltaTime);
    
}

void Game::GenerateOutput()
{
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 255, 255);
    SDL_RenderClear(mRenderer);
    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
    
    tankObj->Draw();
   
    SDL_RenderPresent(mRenderer);     
}

SDL_Renderer* Game::GetRenderer() const 
{ 
    return mRenderer; 
}

Game::~Game()
{
    delete gameInstance;
}