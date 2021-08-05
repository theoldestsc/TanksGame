//#pragma once
#ifndef TANK_H
#define TANK_H

#include <SDL2/SDL_image.h>
#include "DataStructures.h"

class Game;



//TODO: Make global object - Game Object, Tank inherits some properties (Think about it)
class Tank
{
    public:
        Tank(Game* game, Point<int> start_pos, const char* image_path);
        ~Tank();
        void update(float deltaTime);
        void change_direction(Direction dir);
        SDL_Rect tank_rect; //TODO: only avalable for reading - const methods
        SDL_Texture* texture; //TODO: only avalable for reading - const methods
        double mTankAngle;  //TODO: only avalable for reading - const methods
        Direction mTankDir; //TODO: only avalable for reading - const methods
        State state;
    private:
        
};

#endif