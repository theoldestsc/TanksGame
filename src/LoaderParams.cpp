#include "LoaderParams.h"


LoaderParams::LoaderParams(int x, int y,
                 int width, int height, 
                 std::string textureID):
                 x(x),y(y),
                 width(width), 
                 height(height),
                 textureID(textureID)
{

}

int LoaderParams::getX() const 
{ 
    return x; 
}

int LoaderParams::getY() const 
{ 
    return y; 
}

int LoaderParams::getWidth() const 
{ 
    return width; 
}

int LoaderParams::getHeight() const 
{ 
    return height; 
}

std::string LoaderParams::getTextureID() const 
{ 
    return textureID; 
}