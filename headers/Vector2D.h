#include <SDL.h>

class Vector2D final
{
    public:
        Vector2D(float x, float y);
        float getX() const;
        float getY() const;

        void setX(float x);
        void setY(float y);
        Vector2D operator + (const Vector2D& v2) const;
        Vector2D operator - (const Vector2D& v2) const;
        Vector2D& operator += (const Vector2D& v2);
        Vector2D& operator -= (const Vector2D& v2);
        Vector2D& operator *= (float scalar);
        Vector2D operator / (float scalar);
        void normalize();
        float length();
    private:
        float x;
        float y;
};