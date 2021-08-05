//#pragma once
#ifndef DATAS_H
#define DATAS_H

#define WIDTH 512
#define HEIGHT 384

enum State
{
    MOVE,
    STOP,
};

enum Direction 
{
    UP,
    RIGHT,
    DOWN,
    LEFT,
};

struct Vector2 
{ 
    float x; 
    float y; 
};

#endif