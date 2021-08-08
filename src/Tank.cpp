#include "Tank.h"
#include "Game.h"

Tank::Tank(const LoaderParams* pParams):SDLGameObject(pParams),
                                        mTankDir(Direction::UP),
                                        mTankAngle(0),
                                        state(State::STOP)
                                    
{
    x = pParams->getX();
    y = pParams->getY();
    width = pParams->getWidth();
    height = pParams->getHeight();
    textureID = pParams->getTextureID();
}

Tank::~Tank()
{
    
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
    Point<int> bullet_coords;
        /*TODO: have access to bullet rectangle*/
    bullet_coords.x = (this->x + 
                      this->width/2) +
                      this->width/2 *
                      SDL_sin(this->mTankAngle*M_PI/180);
    bullet_coords.y = (this->y + 
                       this->height/2) - 
                       this->height/2 * 
                       SDL_cos(this->mTankAngle*M_PI/180);
    for(Bullet* bullet: vBullets){
        if(bullet->getState() == State::COLLISION){
            bullet->Reinitialize(bullet_coords, this->mTankDir);
            return;
        }
    }
    LoaderParams pParams(bullet_coords.x, bullet_coords.y,
                         7, 7, 
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