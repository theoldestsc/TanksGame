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
            this->position.setY(this->position.getY() + static_cast<int>(-300.0f * deltaTime));
            if(this->position.getY() < 0)
            {
                this->position.setY(0);
            }
            else if (this->position.getY() > (HEIGHT - height))
            {
                this->position.setY(HEIGHT - height);
            }
        }
        else if(this->mTankDir == Direction::DOWN)
        {

            this->position.setY(this->position.getY() + static_cast<int>(300.0f * deltaTime));
            if(this->position.getY() < 0)
            {
                this->position.setY(0);
            }
            else if (this->position.getY() > (HEIGHT - height))
            {
                this->position.setY(HEIGHT - height);
            }
        }

        else if(mTankDir == Direction::RIGHT)
        {

            this->position.setX(this->position.getX() + static_cast<int>( 300.0f * deltaTime));
            if (this->position.getX() > (WIDTH - this->width))
            {
                this->position.setX(WIDTH - this->width);
            }
        }
        else if(mTankDir == Direction::LEFT)
        {
        
            this->position.setX(position.getX() + static_cast<int>(-300.0f * deltaTime));
            if(this->position.getX() < 0)
            {
                this->position.setX(0);
            }
            else if (this->position.getX() > (WIDTH - this->width))
            {
                this->position.setX(WIDTH - this->width);
            }
        }
    }
    for(Bullet* bullet: vBullets)
        bullet->Update(deltaTime);
}

void Tank::Fire()
{  
    int x = (this->position.getX()-3 + //TODO: Not a good approach
             this->width/2) +
             this->width/2 *
             SDL_sin(this->mTankAngle*M_PI/180);
    int y = (this->position.getY()-3 + //TODO: Not a good approach
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
    TextureManager::Instance()->Draw(textureID, position.getX(), position.getY(), width, height,
                                    Game::Instance()->GetRenderer(), mTankAngle,
                                    SDL_FLIP_HORIZONTAL);
    for(Bullet* bullet: vBullets){
        if(bullet->getState() != State::COLLISION)
            bullet->Draw();
    }
} 