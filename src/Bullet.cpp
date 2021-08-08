
#include "Bullet.h"
#include "Game.h"

Bullet::Bullet(const LoaderParams* pParams):SDLGameObject(pParams),
                                            state(State::MOVE)
{
    x = pParams->getX();
    y = pParams->getY();
    width = pParams->getWidth();
    height = pParams->getHeight();
    textureID = pParams->getTextureID();
}

/*void Bullet::Load(const char* image_path)
{
    this->texture = IMG_LoadTexture(this->renderer, image_path);
    if(texture == NULL)
        SDL_Log("Unable to create texture from %s!\
                    SDL Error: %s\n", image_path, SDL_GetError());
    SDL_QueryTexture(texture, NULL, NULL, &bulletRect.w, &bulletRect.h);

    this->bulletRect.x = static_cast<int>(startPos.x); // TODO: FIX THIS with another initialization
    this->bulletRect.y = static_cast<int>(startPos.y);
}*/


void Bullet::setDirection(Direction dir)
{
    this->mBulletDir = dir;
}


void Bullet::Update(float deltaTime)
{
    if(state == State::MOVE)
    {
        if(this->mBulletDir == Direction::UP)
        {
            this->y += static_cast<int>(-300.0f * deltaTime);
            if(this->y < 0)
            {
                state = State::COLLISION;
            }
            else if (this->y > (HEIGHT - height))
            {
                state = State::COLLISION;
            }
        }
        else if(this->mBulletDir == Direction::DOWN)
        {
            this->y += static_cast<int>(300.0f * deltaTime);
            if(this->y < 0)
            {
                state = State::COLLISION;
            }
            else if (this->y > (HEIGHT - this->height))
            {
                state = State::COLLISION;
            }
        }
        else if(this->mBulletDir == Direction::RIGHT)
        {
            this->x += static_cast<int>( 300.0f * deltaTime);
            if (this->x > (WIDTH - this->width))
            {
                state = State::COLLISION;
            }
        }
        else if(this->mBulletDir == Direction::LEFT)
        {
            this->x += static_cast<int>(-300.0f * deltaTime);
            if(this->x < 0)
            {
                state = State::COLLISION;
            }
            else if (this->x > (WIDTH - this->width))
            {
                state = State::COLLISION;
            }
        }
    }
}

void Bullet::Draw()
{
    TextureManager::Instance()->Draw(textureID, x, y, width, height,
                                     Game::Instance()->GetRenderer());
}

void Bullet::Reinitialize(Point<int> mBallPos, Direction dir)
{
    this->x = mBallPos.x;
    this->y = mBallPos.y;
    state = State::MOVE;
    setDirection(dir);
}

Bullet::~Bullet()
{
    
}




