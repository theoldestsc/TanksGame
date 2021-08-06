//#pragma once
#ifndef DATAS_H
#define DATAS_H

#define WIDTH 512
#define HEIGHT 384

#include <type_traits>

enum class State
{
    MOVE,
    STOP,
    COLLISION,
};

enum class Direction 
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

template <typename Enumeration>
constexpr auto as_integer(Enumeration const value) -> typename std::underlying_type<Enumeration>::type
{
    return static_cast<typename std::underlying_type<Enumeration>::type>(value);
}

#endif