#ifndef SDLGameObject_H
#define SDLGameObject_H

#include "GameObject.h"
#include "TextureManager.h"


class SDLGameObject : public GameObject
{
    public:
        SDLGameObject(const LoaderParams* pParams);
        virtual void Draw();
        virtual void Update(float deltaTime){};
        virtual void Clean(){};
    protected:
        int x;
        int y;
        int width;
        int height;
        int currentRow;
        int currentFrame;
        std::string textureID;
};
#endif