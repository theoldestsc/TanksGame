#ifndef GameObject_H
#define GameObject_H

#include "LoaderParams.h"

class GameObject
{
    public:
        virtual void Draw() = 0;
        virtual void Update(float deltatime) = 0;
        virtual void ProcessInput() = 0;
        virtual ~GameObject(){};
};
#endif