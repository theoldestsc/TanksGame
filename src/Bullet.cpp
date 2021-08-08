
#include "Bullet.h"
#include "Game.h"

Bullet::Bullet(SDL_Renderer* renderer, Point<int> start_pos):state(State::MOVE)
{
    this->start_pos = start_pos;
    this->renderer = renderer;
}

void Bullet::Load(const char* image_path)
{
    SDL_Rect mSourceRect;
    this->texture = IMG_LoadTexture(this->renderer, image_path);
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

void Bullet::setDirection(Direction dir)
{
    this->mBulletDir = dir;
}

void Bullet::Render()
{
    SDL_RenderCopy(this->renderer, this->texture, NULL, 
                    &this->bullet_rect);
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
    setDirection(dir);
}

Bullet::~Bullet()
{
    SDL_DestroyTexture(texture);
}




