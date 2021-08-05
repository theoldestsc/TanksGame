
#include "Bullet.h"
#include "Game.h"

Bullet::Bullet(Game* game, Point<int> start_pos, const char* image_path, Direction mBulletDir)
                :mBulletDir(mBulletDir)
{
    SDL_Rect mSourceRect;
    texture = IMG_LoadTexture(game->GetRenderer(),image_path);
    if(texture == NULL)
        SDL_Log("Unable to create texture from %s!\
                    SDL Error: %s\n", image_path, SDL_GetError());
    SDL_QueryTexture(texture, NULL, NULL, &mSourceRect.w, &mSourceRect.h);
    mSourceRect.x = 0;
    mSourceRect.y = 0;
    this->bullet_rect.x = static_cast<int>(start_pos.x) - mSourceRect.w/2; // TODO: FIX THIS with another initialization
    this->bullet_rect.y = static_cast<int>(start_pos.y) - mSourceRect.h/2;
    this->bullet_rect.w = mSourceRect.w;
    this->bullet_rect.h = mSourceRect.h;
}

void Bullet::update(float deltaTime)
{
    if(this->mBulletDir == UP)
    {
        this->bullet_rect.y += static_cast<int>(-300.0f * deltaTime);
        if(this->bullet_rect.y < 0)
        {
            this->bullet_rect.y = 0;
        }
        else if (this->bullet_rect.y > (HEIGHT - this->bullet_rect.h))
        {
            this->bullet_rect.y = HEIGHT;
        }
    }
    else if(this->mBulletDir == DOWN)
    {
        this->bullet_rect.y += static_cast<int>(300.0f * deltaTime);
        if(this->bullet_rect.y < 0)
        {
            this->bullet_rect.y = 0;
        }
        else if (this->bullet_rect.y > (HEIGHT - this->bullet_rect.h))
        {
            this->bullet_rect.y = HEIGHT - this->bullet_rect.h;
        }
    }
    else if(this->mBulletDir == RIGHT)
    {
        bullet_rect.x += static_cast<int>( 300.0f * deltaTime);
        if (bullet_rect.x > (WIDTH - bullet_rect.w))
        {
            bullet_rect.x = WIDTH - bullet_rect.w;
        }
    }
    else if(this->mBulletDir == LEFT)
    {
        bullet_rect.x += static_cast<int>(-300.0f * deltaTime);
        if(bullet_rect.x < 0)
        {
            bullet_rect.x = 0;
        }
        else if (bullet_rect.x > (WIDTH - bullet_rect.w))
        {
            bullet_rect.x = WIDTH - bullet_rect.w;
        }
    }
}

Bullet::~Bullet()
{
    SDL_DestroyTexture(texture);
}




