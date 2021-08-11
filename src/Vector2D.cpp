#include "Vector2D.h"

Vector2D::Vector2D(float x, float y)
{
    this->x = x;
    this->y = y;
}

float Vector2D::getX() const
{
    return this->x;
}

float Vector2D::getY() const
{
    return this->y;
}

void Vector2D::setX(float x)
{
    this->x = x;
}

void Vector2D::setY(float y)
{
    this->y = y;
}

Vector2D Vector2D::operator+(const Vector2D& v2) const
{
    return Vector2D(this->x + v2.x, this->y+v2.y);
}

Vector2D& Vector2D::operator+=(const Vector2D& v2)
{
    this->x += v2.x;
    this->y += v2.y;
    return *this;

}

Vector2D& Vector2D::operator-=(const Vector2D& v2)
{
    this->x -= v2.x;
    this->y -= v2.y;
    return *this;
}


Vector2D& Vector2D::operator*=(float scalar)
{
    this->x *= scalar;
    this->y *= scalar;
    return *this;
}

Vector2D Vector2D::operator-(const Vector2D& v2) const
{
    return Vector2D(this->x - v2.x, this->y - v2.y);
}


Vector2D Vector2D::operator/(float scalar)
{
    this->x /= scalar;
    this->y /= scalar;
    return *this;
}

float Vector2D::length()
{
     return SDL_sqrt(this->x * this->x + this->y * this->y);
}

void Vector2D::normalize()
{
    float l = length();
    if ( l > 0) // we never want to attempt to divide by 0
    {
        (*this) *= 1 / l;
    }

}