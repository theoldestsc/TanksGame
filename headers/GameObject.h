#ifndef GameObject_H
#define GameObject_H

#include "LoaderParams.h"

class GameObject
{
    public:
        virtual void Clean() = 0;
        virtual void Draw() = 0;
        virtual void Update(float deltaTime) = 0;
    
    protected:
        GameObject(const LoaderParams* pParams){};
        virtual ~GameObject() {};
};
#endif