#ifndef SDLGameObject_H
#define SDLGameObject_H

#include "GameObject.h"
#include "TextureManager.h"
#include "Vector2D.h"


class SDLGameObject : public GameObject
{
    public:
        SDLGameObject(const LoaderParams* pParams);
        virtual void Draw();
        virtual void Update(float deltaTime){};
        virtual void Clean(){};
        
    protected:
        Vector2D position;
        /*Vector2D velocity;
        Vector2D acceleration;*/
        int width;
        int height;
        int currentRow;
        int currentFrame;
        std::string textureID;
};
#endif