//#pragma once
#ifndef TANK_H
#define TANK_H

#include <SDL2/SDL_image.h>
#include "DataStructures.h"
#include <Bullet.h>
#include <set>
class Game;



//TODO: Make global object - Game Object, Tank inherits some properties (Think about it)
class Tank
{
    public:
        Tank(SDL_Renderer* renderer, Point<int> &&startPos);
        ~Tank();
        void Update(float deltaTime);
        void change_direction(Direction dir);
        void setState(State state);
        void Fire();
        void Load(const char* image_path);
        void Render();
    private:
        SDL_Renderer* renderer;
        Point<int> startPos;
        std::set<Bullet*> vBullets;
        SDL_Rect tank_rect;
        SDL_Texture* texture;
        double mTankAngle;
        Direction mTankDir;
        State state;
         
};

#endif