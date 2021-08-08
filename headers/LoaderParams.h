#ifndef LoaderParams_H
#define LoaderParams_H

#include <string>

class LoaderParams
{
public:
    LoaderParams(int x, int y,
                 int width, int height, 
                 std::string textureID);
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    std::string getTextureID() const;
    
private:
    int x;
    int y;
    int width;
    int height;
    std::string textureID;
};

#endif