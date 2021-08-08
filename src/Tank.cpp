#include "Tank.h"
#include "Game.h"

Tank::Tank(SDL_Renderer* renderer, Point<int> &&start_pos):
                                        mTankDir(Direction::UP),
                                        mTankAngle(0),
                                        state(State::STOP)
                                    
{
    this->start_pos = start_pos;
    this->renderer = renderer;
}

Tank::~Tank()
{
    for(Bullet* bullet : vBullets)
        delete bullet;
    SDL_DestroyTexture(texture);
}

void Tank::change_direction(Direction dir)
{
    this->mTankDir = dir;
    this->mTankAngle = 90*as_integer(dir);
}

void Tank::update(float deltaTime)
{
    if(this->state == State::MOVE)
    {
        if(this->mTankDir == Direction::UP)
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
        else if(this->mTankDir == Direction::DOWN)
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

        else if(mTankDir == Direction::RIGHT)
        {

            tank_rect.x += static_cast<int>( 300.0f * deltaTime);
            if (tank_rect.x > (WIDTH - tank_rect.w))
            {
                tank_rect.x = WIDTH - tank_rect.w;
            }
        }
        else if(mTankDir == Direction::LEFT)
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
    for(Bullet* bullet: vBullets)
        bullet->update(deltaTime);
}

void Tank::Load(const char* image_path)
{
    SDL_Rect mSourceRect;
    texture = IMG_LoadTexture(renderer,image_path);
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

void Tank::Fire()
{
    Point<int> bullet_coords;
        /*TODO: have access to bullet rectangle*/
    bullet_coords.x = (this->tank_rect.x + 
                      this->tank_rect.w/2) +
                      this->tank_rect.w/2 *
                      SDL_sin(this->mTankAngle*M_PI/180);
    bullet_coords.y = (this->tank_rect.y + 
                       this->tank_rect.h/2) - 
                       (float)this->tank_rect.h/2 * 
                       SDL_cos(this->mTankAngle*M_PI/180);
    for(Bullet* bullet: vBullets){
        if(bullet->getState() == State::COLLISION){
            bullet->reinitialize(bullet_coords, this->mTankDir);
            return;
        }
    }
    Bullet* bullet = new Bullet(this->renderer, bullet_coords);
    bullet->setDirection(this->mTankDir);
    bullet->Load("../Sprites/Bullet_Red.png");
    vBullets.emplace(bullet);
}

void Tank::setState(State state)
{
    this->state = state; 
}

void Tank::Render()
{
    SDL_RenderCopyEx(this->renderer, this->texture, NULL, 
                     &this->tank_rect, 
                     this->mTankAngle, 
                     NULL, 
                     SDL_FLIP_HORIZONTAL);
     for(Bullet* bullet: vBullets){
        if(bullet->getState() != State::COLLISION)
            bullet->Render();
    }
    
}