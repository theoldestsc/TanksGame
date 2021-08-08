#include "Tank.h"
#include "Game.h"

Tank::Tank(const LoaderParams* pParams):SDLGameObject(pParams),
                                        mTankDir(Direction::UP),
                                        mTankAngle(0),
                                        state(State::STOP)
                                    
{
 
}

Tank::~Tank()
{
    for(Bullet* bullet : vBullets)
        delete bullet;
}

void Tank::change_direction(Direction dir)
{
    this->mTankDir = dir;
    this->mTankAngle = 90*dir;
}

void Tank::Update(float deltaTime)
{
    if(this->state == State::MOVE)
    {
        if(this->mTankDir == Direction::UP)
        {
            this->y += static_cast<int>(-300.0f * deltaTime);
            if(this->y < 0)
            {
                this->y = 0;
            }
            else if (this->y > (HEIGHT - height))
            {
                this->y = HEIGHT;
            }
        }
        else if(this->mTankDir == Direction::DOWN)
        {

            this->y += static_cast<int>(300.0f * deltaTime);
            if(this->y < 0)
            {
                this->y = 0;
            }
            else if (this->y > (HEIGHT - height))
            {
                this->y = HEIGHT - height;
            }
        }

        else if(mTankDir == Direction::RIGHT)
        {

            this->x += static_cast<int>( 300.0f * deltaTime);
            if (this->x > (WIDTH - this->width))
            {
                this->x = WIDTH - this->width;
            }
        }
        else if(mTankDir == Direction::LEFT)
        {
        
            this->x += static_cast<int>(-300.0f * deltaTime);
            if(this->x < 0)
            {
                this->x = 0;
            }
            else if (this->x > (WIDTH - this->width))
            {
                this->x = WIDTH - this->width;
            }
        }
    }
    for(Bullet* bullet: vBullets)
        bullet->Update(deltaTime);
}

void Tank::Fire()
{  
    int x = (this->x-3 + //TODO: Not a good approach
             this->width/2) +
             this->width/2 *
             SDL_sin(this->mTankAngle*M_PI/180);
    int y = (this->y-3 + //TODO: Not a good approach
             this->height/2) - 
             this->height/2 * 
             SDL_cos(this->mTankAngle*M_PI/180);
    for(Bullet* bullet: vBullets){
        if(bullet->getState() == State::COLLISION){
            bullet->Reinitialize(x, y, this->mTankDir);
            return;
        }
    }
    LoaderParams pParams(x, y,
                         7, 7, //TODO: Not a good approach
                         std::string("Bullet"));
    Bullet* bullet = new Bullet(&pParams);
    bullet->setDirection(this->mTankDir);
    vBullets.emplace(bullet);
}

void Tank::setState(State state)
{
    this->state = state; 
}

void Tank::Draw()
{
    TextureManager::Instance()->Draw(textureID, x, y, width, height,
                                    Game::Instance()->GetRenderer(), mTankAngle,
                                    SDL_FLIP_HORIZONTAL);
    for(Bullet* bullet: vBullets){
        if(bullet->getState() != State::COLLISION)
            bullet->Draw();
    }
} 