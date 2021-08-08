#ifndef TANK_H
#define TANK_H

#include "SDLGameObject.h"
#include "DataStructures.h"
#include <Bullet.h>
#include <set>
class Game;

class Tank : public SDLGameObject
{
    public:
        Tank(const LoaderParams* pParams);
        ~Tank();
        virtual void Update(float deltaTime) override;
        void change_direction(Direction dir);
        void setState(State state);
        void Fire();
        virtual void Draw() override;

    private:
        std::set<Bullet*> vBullets;
        double mTankAngle;
        Direction mTankDir;
        State state;
         
};

#endif