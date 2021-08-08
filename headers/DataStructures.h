//#pragma once
#ifndef DATAS_H
#define DATAS_H

#define WIDTH 512
#define HEIGHT 384

#include <type_traits>

enum State
{
    MOVE,
    STOP,
    COLLISION,
};

enum Direction 
{
    UP,
    RIGHT,
    DOWN,
    LEFT,
};

template<typename T>
struct Point 
{ 
    T x; 
    T y; 
};

template<typename T>
struct Size
{ 
    T w; 
    T h; 
};

#endif