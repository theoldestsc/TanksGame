#ifndef BULLET_H
#define BULLET_H

#include "SDLGameObject.h"
#include "DataStructures.h"
class Game;

class Bullet : public SDLGameObject
{
    public:
        Bullet(const LoaderParams* pParams);
        ~Bullet();
        virtual void Update(float deltaTime) override;
        virtual void Draw() override;
        void Reinitialize(Point<int> mBallPos, Direction dir);
        void setDirection(Direction dir);
        State getState() const { return state; };
    private:
        Direction mBulletDir;
        State state;
};
#endif