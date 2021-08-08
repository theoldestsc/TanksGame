#ifndef BULLET_H
#define BULLET_H

#include "DataStructures.h"
#include <SDL2/SDL_image.h>

class Game;

class Bullet
{
    public:
        Bullet(SDL_Renderer* renderer, Point<int> startPos);
        ~Bullet();
        void Update(float deltaTime);     
        void Reinitialize(Point<int> mBallPos, Direction dir);
        void Load(const char* image_path);
        void Render();
        void setDirection(Direction dir);
        State getState() const { return state; };
    private:
        Point<int> mBallVel;
        Point<int> mBallPos;
        Direction mBulletDir;
        SDL_Renderer* renderer;
        Point<int> startPos;
        State state;
        SDL_Rect bulletRect;
        SDL_Texture* texture;
        

};
#endif