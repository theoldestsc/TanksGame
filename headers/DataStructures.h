//#pragma once
#ifndef DATAS_H
#define DATAS_H

#define WIDTH 512
#define HEIGHT 384

enum Direction 
{
    UP,
    RIGHT,
    DOWN,
    LEFT,
    NONE,
};

struct Vector2 
{ 
    float x; 
    float y; 
};

#endif