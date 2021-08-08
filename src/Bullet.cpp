
#include "Bullet.h"
#include "Game.h"

Bullet::Bullet(SDL_Renderer* renderer, Point<int> startPos):
                                        state(State::MOVE)
{
    this->startPos = startPos;
    this->renderer = renderer;
}

void Bullet::Load(const char* image_path)
{
    this->texture = IMG_LoadTexture(this->renderer, image_path);
    if(texture == NULL)
        SDL_Log("Unable to create texture from %s!\
                    SDL Error: %s\n", image_path, SDL_GetError());
    SDL_QueryTexture(texture, NULL, NULL, &bulletRect.w, &bulletRect.h);

    this->bulletRect.x = static_cast<int>(startPos.x); // TODO: FIX THIS with another initialization
    this->bulletRect.y = static_cast<int>(startPos.y);
}


void Bullet::setDirection(Direction dir)
{
    this->mBulletDir = dir;
}

void Bullet::Render()
{
    SDL_RenderCopy(this->renderer, this->texture, NULL, 
                    &this->bulletRect);
}

void Bullet::Update(float deltaTime)
{
    if(state == State::MOVE)
    {
        if(this->mBulletDir == Direction::UP)
        {
            this->bulletRect.y += static_cast<int>(-300.0f * deltaTime);
            if(this->bulletRect.y < 0)
            {
                state = State::COLLISION;
            }
            else if (this->bulletRect.y > (HEIGHT - this->bulletRect.h))
            {
                state = State::COLLISION;
            }
        }
        else if(this->mBulletDir == Direction::DOWN)
        {
            this->bulletRect.y += static_cast<int>(300.0f * deltaTime);
            if(this->bulletRect.y < 0)
            {
                state = State::COLLISION;
            }
            else if (this->bulletRect.y > (HEIGHT - this->bulletRect.h))
            {
                state = State::COLLISION;
            }
        }
        else if(this->mBulletDir == Direction::RIGHT)
        {
            bulletRect.x += static_cast<int>( 300.0f * deltaTime);
            if (bulletRect.x > (WIDTH - bulletRect.w))
            {
                state = State::COLLISION;
            }
        }
        else if(this->mBulletDir == Direction::LEFT)
        {
            bulletRect.x += static_cast<int>(-300.0f * deltaTime);
            if(bulletRect.x < 0)
            {
                state = State::COLLISION;
            }
            else if (bulletRect.x > (WIDTH - bulletRect.w))
            {
                state = State::COLLISION;
            }
        }
    }
}

void Bullet::Reinitialize(Point<int> mBallPos, Direction dir)
{
    bulletRect.x = mBallPos.x;
    bulletRect.y = mBallPos.y;
    state = State::MOVE;
    setDirection(dir);
}

Bullet::~Bullet()
{
    SDL_DestroyTexture(texture);
}




