
#include "Bullet.h"
#include "Game.h"

Bullet::Bullet(Game* game, Point<int> start_pos, const char* image_path, Direction mBulletDir)
                :mBulletDir(mBulletDir)
{
    SDL_Rect mSourceRect;
    state = State::MOVE;
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
    if(state == State::MOVE)
    {
        if(this->mBulletDir == Direction::UP)
        {
            this->bullet_rect.y += static_cast<int>(-300.0f * deltaTime);
            if(this->bullet_rect.y < 0)
            {
                state = State::COLLISION;
            }
            else if (this->bullet_rect.y > (HEIGHT - this->bullet_rect.h))
            {
                state = State::COLLISION;
            }
        }
        else if(this->mBulletDir == Direction::DOWN)
        {
            this->bullet_rect.y += static_cast<int>(300.0f * deltaTime);
            if(this->bullet_rect.y < 0)
            {
                state = State::COLLISION;
            }
            else if (this->bullet_rect.y > (HEIGHT - this->bullet_rect.h))
            {
                state = State::COLLISION;
            }
        }
        else if(this->mBulletDir == Direction::RIGHT)
        {
            bullet_rect.x += static_cast<int>( 300.0f * deltaTime);
            if (bullet_rect.x > (WIDTH - bullet_rect.w))
            {
                state = State::COLLISION;
            }
        }
        else if(this->mBulletDir == Direction::LEFT)
        {
            bullet_rect.x += static_cast<int>(-300.0f * deltaTime);
            if(bullet_rect.x < 0)
            {
                state = State::COLLISION;
            }
            else if (bullet_rect.x > (WIDTH - bullet_rect.w))
            {
                state = State::COLLISION;
            }
        }
    }
}

void Bullet::reinitialize(Point<int> mBallPos, Direction dir)
{
    bullet_rect.x = mBallPos.x;
    bullet_rect.y = mBallPos.y;
    state = State::MOVE;
    mBulletDir = dir;
}

Bullet::~Bullet()
{
    SDL_DestroyTexture(texture);
}




