
#include "Bullet.h"
#include "Game.h"

Bullet::Bullet(const LoaderParams* pParams):SDLGameObject(pParams),
                                            state(State::MOVE)
{
   
}


void Bullet::setDirection(Direction dir)
{
    this->mBulletDir = dir;
}


void Bullet::Update(float deltaTime)
{
    if(this->state == State::MOVE)
    {
        if(this->mBulletDir == Direction::UP)
        {
            this->position.setY(this->position.getY() + static_cast<int>(-300.0f * deltaTime));
            if(this->position.getY() < 0)
            {
                this->state = State::COLLISION;
            }
            else if (this->position.getY() > (HEIGHT - height))
            {
                this->state = State::COLLISION;
            }
        }
        else if(this->mBulletDir == Direction::DOWN)
        {

            this->position.setY(this->position.getY() + static_cast<int>(300.0f * deltaTime));
            if(this->position.getY() < 0)
            {
                this->state = State::COLLISION;
            }
            else if (this->position.getY() > (HEIGHT - height))
            {
                this->state = State::COLLISION;
            }
        }

        else if(mBulletDir == Direction::RIGHT)
        {

            this->position.setX(this->position.getX() + static_cast<int>( 300.0f * deltaTime));
            if (this->position.getX() > (WIDTH - this->width))
            {
                this->state = State::COLLISION;
            }
        }
        else if(mBulletDir == Direction::LEFT)
        {
        
            this->position.setX(position.getX() + static_cast<int>(-300.0f * deltaTime));
            if(this->position.getX() < 0)
            {
                this->state = State::COLLISION;
            }
            else if (this->position.getX() > (WIDTH - this->width))
            {
                this->state = State::COLLISION;
            }
        }
    }
}

void Bullet::Draw()
{
    TextureManager::Instance()->Draw(textureID, position.getX(), position.getY(), width, height,
                                     Game::Instance()->GetRenderer());
}

void Bullet::Reinitialize(int x, int y, Direction dir)
{
    this->position.setX(x);
    this->position.setY(y);
    state = State::MOVE;
    setDirection(dir);
}

Bullet::~Bullet()
{
    
}




