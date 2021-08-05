#ifndef BULLET_H
#define BULLET_H

#include "DataStructures.h"
#include <SDL2/SDL_image.h>

class Game;

class Bullet
{
    public:
        Bullet(Game* game, Point<int> start_pos, const char* image_path, Direction mBulletDir);
        ~Bullet();
        void update(float deltaTime);
        SDL_Rect bullet_rect; //TODO: only avalable for reading - const methods
        SDL_Texture* texture;
    private:
        Point<int> mBallVel;
        Point<int> mBallPos;
        Direction mBulletDir;

};
#endif