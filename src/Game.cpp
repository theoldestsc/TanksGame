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
    tank_obj = new Tank(this, Point<int>{5, 100}, "../Sprites/tank.png");
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
            if(event.key.keysym.sym == SDLK_SPACE)
                {
                    /*TODO: Too slow, make virtual class GameObject 
                            inherits Tank and Bullet, 
                            load texture for bullet only once
                     */
                    Point<int> bullet_coords;
                    /*TODO: have access to bullet rectangle*/
                    bullet_coords.x = (tank_obj->tank_rect.x + 
                                      tank_obj->tank_rect.w/2) +
                                      tank_obj->tank_rect.w/2 *
                                      SDL_sin(tank_obj->mTankAngle*M_PI/180);

                    bullet_coords.y = (tank_obj->tank_rect.y + 
                                       tank_obj->tank_rect.h/2) - 
                                       (float)tank_obj->tank_rect.h/2 * 
                                       SDL_cos(tank_obj->mTankAngle*M_PI/180);
                    vBullets.push_back(new Bullet(this, bullet_coords, "../Sprites/Bullet_Red.png", tank_obj->mTankDir));
                }
            break;
        default:
            break;
        }
    }        
    //Get state of keyboard
    
    const Uint8* state = SDL_GetKeyboardState(NULL);
    //if escape is pressed, also end loop
    tank_obj->state = State::STOP;
    if(state[SDL_SCANCODE_ESCAPE])
        mIsRunning = false;
    else if(state[SDL_SCANCODE_W]){
        tank_obj->state = State::MOVE;
        tank_obj->change_direction(Direction::UP);
    }
    else if(state[SDL_SCANCODE_S]){
        tank_obj->state = State::MOVE;
        tank_obj->change_direction(Direction::DOWN);
    }
    else if(state[SDL_SCANCODE_D]){
        tank_obj->state = State::MOVE;
        tank_obj->change_direction(Direction::RIGHT);
    }
    else if(state[SDL_SCANCODE_A]){
        tank_obj->state = State::MOVE;
        tank_obj->change_direction(Direction::LEFT);
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
    for(Bullet* bullet: vBullets)
        bullet->update(deltaTime);
}

void Game::GenerateOutput()
{
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 255, 255);
    SDL_RenderClear(mRenderer);
    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
    
    SDL_RenderCopyEx(mRenderer, tank_obj->texture, NULL, 
                    &tank_obj->tank_rect, 
                    tank_obj->mTankAngle, 
                    NULL, 
                    SDL_FLIP_HORIZONTAL);
    for(Bullet* bullet: vBullets)
        SDL_RenderCopy(mRenderer, bullet->texture, NULL, 
                    &bullet->bullet_rect);
    SDL_RenderPresent(mRenderer);     
}

SDL_Renderer* Game::GetRenderer() const 
{ 
    return mRenderer; 
}

