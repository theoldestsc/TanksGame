#include "Tank.h"
#include "Game.h"

Tank::Tank(Game *game, Vector2 start_pos, const char* image_path):
                                        mTankDir(NONE),
                                        mTankAngle(0)
{
    
    SDL_Rect mSourceRect;
    texture = IMG_LoadTexture(game->GetRenderer(),image_path);
    if(texture == NULL)
        SDL_Log("Unable to create texture from %s!\
                    SDL Error: %s\n", image_path, SDL_GetError());
    SDL_QueryTexture(texture, NULL, NULL, &mSourceRect.w, &mSourceRect.h);
    mSourceRect.x = 0;
    mSourceRect.y = 0;
    this->tank_rect.x = static_cast<int>(start_pos.x);
    this->tank_rect.y = static_cast<int>(start_pos.y);
    this->tank_rect.w = mSourceRect.w/8;
    this->tank_rect.h = mSourceRect.h/8;
}

Tank::~Tank()
{
    SDL_DestroyTexture(texture);
}

void Tank::change_direction(Direction dir)
{
    this->mTankDir = dir;
    if (this->mTankDir != Direction::NONE)
        this->mTankAngle = 90*dir;
}

void Tank::update(float deltaTime)
{
    if(this->mTankDir == UP)
    {
        this->tank_rect.y += static_cast<int>(-300.0f * deltaTime);
        if(this->tank_rect.y < 0)
        {
            this->tank_rect.y = 0;
        }
        else if (this->tank_rect.y > (HEIGHT - this->tank_rect.h))
        {
            this->tank_rect.y = HEIGHT;
        }
    }
    else if(this->mTankDir == DOWN)
    {
        
        this->tank_rect.y += static_cast<int>(300.0f * deltaTime);
        if(this->tank_rect.y < 0)
        {
            this->tank_rect.y = 0;
        }
        else if (this->tank_rect.y > (HEIGHT - this->tank_rect.h))
        {
            this->tank_rect.y = HEIGHT - this->tank_rect.h;
        }
    }

    else if(mTankDir == RIGHT)
    {
        
        tank_rect.x += static_cast<int>( 300.0f * deltaTime);
        if (tank_rect.x > (WIDTH - tank_rect.w))
        {
            tank_rect.x = WIDTH - tank_rect.w;
        }
    }
    else if(mTankDir == LEFT)
    {
      
        tank_rect.x += static_cast<int>(-300.0f * deltaTime);
        if(tank_rect.x < 0)
        {
            tank_rect.x = 0;
        }
        else if (tank_rect.x > (WIDTH - tank_rect.w))
        {
            tank_rect.x = WIDTH - tank_rect.w;
        }
    }
}