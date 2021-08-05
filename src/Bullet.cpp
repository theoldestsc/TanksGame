
#include "Bullet.h"
#include "Game.h"

Bullet::Bullet(Game* game, Vector2 start_pos, const char* image_path, Direction mBulletDir)
                :mBulletDir(NONE)
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
    
}

Bullet::~Bullet()
{
    SDL_DestroyTexture(texture);
}




